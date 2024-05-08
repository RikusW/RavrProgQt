// RavrProgQt.cpp
// vim:ts=4 sts=0 sw=4

#include "RavrProgQt.h"
#include <QFileDialog>
#include <QVariant>

#include <stdio.h>

//-------------------------------------------------------------------------------------------------
//Programmer Tab

void RavrProgQt::ProgChanged(int n)
{
	ui.InterfaceCombo->clear();

	if(n >= 0) {
		prog = prog_list->GetAt(n);
	}else{
		prog = 0;
	}

	if(prog) {
		progif = progif_list = prog->interface; //XXX
		for(ProgIF *i = progif; i; i = i->next) {
			ui.InterfaceCombo->addItem(i->name());
		}
		Refresh(); //ports
	}else{
		progif = progif_list = 0;
	}

	if(progif) {
		IfChanged(0); //XXX
	}
}

//---------------------------------------------------------

void ProgCB(u32 total, u32 current, void *v)
{
	if(!total) total = 1;
	((QProgressBar*)v)->setValue((current*100)/total);
}

//---------------------------------------------------------

void RavrProgQt::IfChanged(int n)
{
	if(n < 0) {
		progif_list = progif = 0;
		return;
	}

	if(progif_list) {
		progif = progif_list->GetAt(n);
	}else{
		progif = 0;
		return;
	}

	progif->PCBvoid = (void*)ui.progressBar;
	progif->ProgressCallback = ProgCB;

	//Programming Clock
	int *up = progif->GetPClockList();
	ui.PClockCombo->clear();
	if(up) {
		up++;
		ui.PClockCombo->addItem("Default");
		while(*up) {
			QString s;
			s.setNum(*up);
			ui.PClockCombo->addItem(s);
			up++;
		}
	}else{
		ui.PClockCombo->addItem("Not Available");
	}
	
	//Clock Generator
	up = progif->GetEClockList();
	ui.EClockCombo->clear();
	if(up) {
		up++;
		ui.EClockCombo->addItem("Default");
		while(*up) {
			QString s;
			s.setNum(*up);
			ui.EClockCombo->addItem(s);
			up++;
		}
		ui.EClockCombo->addItem("Off");
	}else{
		ui.EClockCombo->addItem("Not Available");
	}

	//device list
	ui.DeviceCombo->clear();
	device = progif->GetDeviceList(); //device = auto;
	for(Device *d = device; d; d = d->next) {
		//debug
		QString n, s = d->name;
		n.setNum(d->signature,16);
		s += "  " + n;
		n.setNum(d->jtag_id,16);
		s += " -- " + n;

		ui.DeviceCombo->addItem(s);
		if(d->name == devname) { //no need for strcmp, always points to the same buffer
			ui.DeviceCombo->setCurrentIndex(d->i);
		}
	}
}

//---------------------------------------------------------

void RavrProgQt::PClockChanged(int i)
{
	progif->SetPClockI(i);
}

void RavrProgQt::ApplyP()
{
	if(progifc && progifc->GetPClockList()) {
		int f = progifc->ApplyPClock();
		QString s;
		s.setNum(f);
		s = "Default = " + s;
		ui.PClockCombo->setItemText(0,s);
		if(progifc->PSaved()) {
			ui.PClockCombo->setCurrentIndex(0); //XXX
		}
	}
}

//---------------------------------------------------------

void RavrProgQt::EClockChanged(int i)
{
	progif->SetEClockI(i);
}

void RavrProgQt::ApplyE()
{
	if(progifc && progifc->GetEClockList()) {
		int f = progifc->ApplyEClock();
		QString s;
		if(f) {
			s.setNum(f);
		}else{
			s = "OFF";
		}
		s = "Default = " + s;
		ui.EClockCombo->setItemText(0,s);
		if(progifc->PSaved()) {
			ui.EClockCombo->setCurrentIndex(0);
		}
	}
}

//---------------------------------------------------------

void RavrProgQt::Refresh()
{
	if(!prog) {
		return;
	}

	QString s;
	const char *c;
	ui.PortCombo->clear();
    for (u32 i = 0; (c = prog->port->GetPort(i)); i++) {
		s = c;
        ui.PortCombo->addItem(s);
		if(s.contains("ACM") || s.contains("USB") || s.contains("usb")) {
		    ui.PortCombo->setCurrentIndex(i);
		}
    }
}

//---------------------------------------------------------

void RavrProgQt::Connect()
{
	if(progifc) {
		puts("Disconnecting");
		progifc->Disconnect();

		if(bAuto) {
			ui.DeviceCombo->setCurrentIndex(0);
			device = progifc->SetDevice(0);
			bAuto = false;
		}
		progifc = 0;

		ui.ProgrammerCombo->setEnabled(true);
		ui.InterfaceCombo->setEnabled(true);
		ui.PClockCombo->setItemText(0,"Default");
		ui.pushButton_ApplyP->setEnabled(false);
		ui.EClockCombo->setItemText(0,"Default");
		ui.pushButton_ApplyE->setEnabled(false);
		ui.PortCombo->setEnabled(true);
		ui.pushButton_Refresh->setEnabled(true);
		ui.pushButton_Connect->setText("&Connect");

		ui.SigEdit->setText("");
		ui.SerialEdit->setText("");
		ui.OsccalCombo->clear();
		ui.pushButton_Refresh_AVR->setEnabled(false);
		ui.lineEdit_Fuses->setText("");
		ui.DeviceCombo->setEnabled(true);
	}else{
		if(!progif) {
			puts("RavrProgQt::Connect progif == 0");
			return;
		}
		QString n,s = ui.PortCombo->currentText();
		char c[300];
		strcpy(c,s.toLatin1().data());
		printf("Connecting to ->%s\n",c);
		if(progif->Connect(c)) {
			progifc = progif;
			puts("connect OK");
			ui.pushButton_Connect->setText("&Disconnect");
			ui.ProgrammerCombo->setEnabled(false);
			ui.InterfaceCombo->setEnabled(false);
			ui.pushButton_ApplyP->setEnabled(true);
			ui.pushButton_ApplyE->setEnabled(true);
			ui.PortCombo->setEnabled(false);
			ui.pushButton_Refresh->setEnabled(false);
			ui.pushButton_Refresh_AVR->setEnabled(true);
			ui.DeviceCombo->setEnabled(false);

			ApplyP();
			ApplyE();
			RefreshAVR();
		}else{
			puts("connect fail");
		}
	}
}

//---------------------------------------------------------

void RavrProgQt::RefreshAVR()
{
	//auto detect avr
	int i = ui.DeviceCombo->currentIndex();
	if(!i || bAuto) {
		bAuto = true;
		device = progifc->SetDevice(0);
		ui.DeviceCombo->setCurrentIndex(device->i);
	}else{
		device = progifc->SetDevice(i);
	}


//	QString s,t,n;

/*
	if(!Enter()) {
		ui.SigEdit->setText("Failed to read");
		Leave();
		return;
	}

	//signature and jtag id
	u32 sig = progifc->ReadSignature();
	n.setNum(sig,16);
	s = '<' + n + ">  <";
	u32 id = progifc->ReadJtagID();
	n.setNum(id,16);
	s += n + ">";
	ui.SigEdit->setText(s);*/


/*	//serial
	s = "";
	u8 buf[10];
	progifc->ReadSerial(buf);
	for(i=0; i<10; i++) {
		s += tohex[(buf[i]>>4)&0xF];
		s += tohex[(buf[i]>>0)&0xF];
		s += ' ';
	}
	s.chop(1);
	ui.SerialEdit->setText(s);

	//osccal
	ui.OsccalCombo->clear();
	for(i=0; i<4; i++) {
		u8 u = progifc->ReadCal(i);
		s = "0x";
		s += tohex[(u>>4)&0xF];
		s += tohex[(u>>0)&0xF];
		ui.OsccalCombo->addItem(s);
	}
	Leave();*/
}
//---------------------------------------------------------

void RavrProgQt::DeviceChanged(int i)
{
	if(i < 0) { // ignore -1 sent by clear
		ign = true;
		return;
	}
	if(ign) { //ignore 0 after -1
		ign = false;
		return;
	}

	if(!bAuto) {
		device = progif->GetDevice(i);
		devname = device->name;
	}
	printf("Device changed %i  %s\n",i, device ? device->name : "xx");
}

//Programmer Tab
//-------------------------------------------------------------------------------------------------
//Flash Tab

void RavrProgQt::ChipErase()
{
	if(Enter()) {
		progifc->ChipErase();
	}
	Leave();
}

//---------------------------------------------------------

void RavrProgQt::ReadFlash()
{
	QFileDialog dlg;
	QString s = dlg.getSaveFileName(this);
	if(s == "") {
		printf("Reading Flash Cancelled\n");
		return;
	}
	char c[300];
	strcpy(c,s.toLatin1().data());
	printf("Reading Flash: %s\n",c);

	if(Enter()) {
		progifc->ReadFlash(c);
	}
	Leave();
	ui.progressBar->setValue(0);
}

//---------------------------------------------------------

void RavrProgQt::WriteFlash()
{
	QString s = ui.lineEdit_Flash->text();
	if(s == "") {
		QFileDialog dlg;
		s = dlg.getOpenFileName(this);
		if(s == "") {
			printf("Writing Flash Cancelled\n");
			return;
		}
	}
	char c[300];
	strcpy(c,s.toLatin1().data());
	printf("Writing Flash %s\n",c);

	if(Enter()) {
		if(ui.checkBox_Erase->checkState()) {
			progifc->ChipErase();
		}
		progifc->WriteFlash(c);
		if(ui.checkBox_Verify->checkState()) {
			progifc->VerifyFlash(c);
		}
	}
	Leave();
	ui.progressBar->setValue(0);
}

//---------------------------------------------------------

void RavrProgQt::VerifyFlash()
{
	QString s = ui.lineEdit_Flash->text();
	if(s == "") {
		QFileDialog dlg;
		s = dlg.getOpenFileName(this);
		if(s == "") {
			printf("Verifying Flash Cancelled\n");
			return;
		}
	}
	char c[300];
	strcpy(c,s.toLatin1().data());
	printf("Verifying Flash %s\n",c);

	if(Enter()) {
		progifc->VerifyFlash(c);
	}
	Leave();
	ui.progressBar->setValue(0);
}

//---------------------------------------------------------

void RavrProgQt::SelectFlash()
{
	QFileDialog dlg;
	QString s = dlg.getOpenFileName(this);
	if(s == "") {
		printf("Selecting Flash File Cancelled\n");
		return;
	}
	ui.lineEdit_Flash->setText(s);
	char c[300];
	strcpy(c,s.toLatin1().data());
	printf("Selecting Flash File: %s\n",c);
}

//-----------------------------------------------------------------------------

void RavrProgQt::ReadEeprom()
{
	QFileDialog dlg;
	QString s = dlg.getSaveFileName(this);
	if(s == "") {
		printf("Reading Eeprom Cancelled\n");
		return;
	}
	char c[300];
	strcpy(c,s.toLatin1().data());
	printf("Reading Eeprom: %s\n",c);

	if(Enter()) {
		progifc->ReadEeprom(c);
	}
	Leave();
	ui.progressBar->setValue(0);
}

//---------------------------------------------------------

void RavrProgQt::WriteEeprom()
{
	QString s = ui.lineEdit_Eeprom->text();
	if(s == "") {
		QFileDialog dlg;
		s = dlg.getOpenFileName(this);
		if(s == "") {
			printf("Writing Eeprom Cancelled\n");
			return;
		}
	}
	char c[300];
	strcpy(c,s.toLatin1().data());
	printf("Writing Eeprom %s\n",c);

	if(Enter()) {
		progifc->WriteEeprom(c);
		if(ui.checkBox_Verify->checkState()) {
			progifc->VerifyEeprom(c);
		}
	}
	Leave();
	ui.progressBar->setValue(0);
}

//---------------------------------------------------------

void RavrProgQt::VerifyEeprom()
{
	QString s = ui.lineEdit_Eeprom->text();
	if(s == "") {
		QFileDialog dlg;
		s = dlg.getOpenFileName(this);
		if(s == "") {
			printf("Verifying Eeprom Cancelled\n");
			return;
		}
	}
	char c[300];
	strcpy(c,s.toLatin1().data());
	printf("Verifying Eeprom %s\n",c);

	if(Enter()) {
		progifc->VerifyEeprom(c);
	}
	Leave();
	ui.progressBar->setValue(0);
}

//---------------------------------------------------------

void RavrProgQt::SelectEeprom()
{
	QFileDialog dlg;
	QString s = dlg.getOpenFileName(this);
	if(s == "") {
		printf("Selecting Eeprom Cancelled\n");
		return;
	}
	ui.lineEdit_Eeprom->setText(s);
	const char *c = s.toLatin1().data();
	printf("Selecting Eeprom File: %s\n",c);
}

//Flash Tab
//-------------------------------------------------------------------------------------------------
//Fuse Tab

void RavrProgQt::TabChanged(int i)
{
	printf("TabChanged %i\n",i);

	if(i == 2 && device) {
		if(!device->config) {
			device->Load();
		}
		SetupFuseBox(device);
		ReadFuse();
	}
}

//---------------------------------------------------------

void RavrProgQt::ReadFuse()
{
	if(Enter()) {
//		puts("Reading Fuses");
		progifc->ReadFuses();
	}
	Leave();

	UpdateFuseBox();
	SetFuseEdit();
}

//---------------------------------------------------------

void RavrProgQt::WriteFuse()
{
	if(Enter()) {
//		puts("Writing Fuses");
		progifc->WriteFuses();
	}
	Leave();
}

//---------------------------------------------------------

void RavrProgQt::VerifyFuse()
{
	if(Enter()) {
//		puts("Verifying Fuses");
		progifc->VerifyFuses();
	}
	Leave();
}

//---------------------------------------------------------

void RavrProgQt::DefaultFuse()
{
	if(device) {
		device->SetDefaultFuses();
		UpdateFuseBox();
		SetFuseEdit();
	}
}

//---------------------------------------------------------

void RavrProgQt::FuseChecked(int i)
{
	if(bIgnore) {
		return;
	}
	QVariant qv = sender()->property("fuse");
	if(qv.isValid()) {
		void *v = qv.value<void*>();
		AvrFuse *f = (AvrFuse*)v;
		f->Set(i == Qt::Checked);
		SetFuseEdit();
	}else{
		printf("FuseChecked Invalid pointer\n");
	}
}

//---------------------------------------------------------

void RavrProgQt::FuseSelected(int i)
{
	if(bIgnore) {
		return;
	}
	QVariant qv = sender()->property("fuse");
	if(qv.isValid()) {
		void *v = qv.value<void*>();
		AvrFuse *f = (AvrFuse*)v;
		f->Select(i);
		SetFuseEdit();
	}else{
		printf("FuseSelected Invalid pointer\n");
	}
}

//---------------------------------------------------------

void RavrProgQt::FuseEdited(const QString &s)
{
	u8 fusebuf[32];
	QStringList l = s.split(" "); //XXX only for tiny/mega... not xm/avr32
	fusebuf[3] = l.at(0).toUShort(0,16);
	fusebuf[2] = l.at(1).toUShort(0,16);
	fusebuf[1] = l.at(2).toUShort(0,16);
	fusebuf[0] = l.at(3).toUShort(0,16);
	device->SetFuseBuf(fusebuf);

	bIgnore = true;
	int i = ui.lineEdit_Fuses->cursorPosition();
	UpdateFuseBox();
	ui.lineEdit_Fuses->setCursorPosition(i);
	bIgnore = false;

//	const char *c = s.toLatin1().data();
//	printf("---%s---\n",s.toLatin1().data());
}

//---------------------------------------------------------

void RavrProgQt::FuseEditFinished() //lost focus so set reserved fuses to 1
{
	int i = ui.lineEdit_Fuses->cursorPosition();
	SetFuseEdit(); //reset invalid fuses
	ui.lineEdit_Fuses->setCursorPosition(i);
}

//---------------------------------------------------------

const char *tohex = "0123456789ABCDEF";

void RavrProgQt::SetFuseEdit()
{
	QString s = "";

	u8 fuses[32];
	u8 u = device->GetFuseBuf(fuses);

	//mega/tiny
	do{
		u--;
		s+= tohex[fuses[u]>>4];
		s+= tohex[fuses[u]&0xF];
		s+= ' ';
	}while(u);
	s.chop(1);

	ui.lineEdit_Fuses->setText(s);
}

//---------------------------------------------------------

void RavrProgQt::SetupFuseBox(Device *d)
{
	if(!d) {
		//XXX
		return;
	}
	bIgnore = true;

	QWidget *ww = new QWidget();
	QVBoxLayout *vb = new QVBoxLayout(ww);
	vb->setSpacing(4);
	vb->setMargin(6);

	AvrFuse *c,*f = d->GetFuses();
	for(f = f ? f->child : 0; f; f = f->next) {
		if(!f->mask) {
			QLabel *l = new QLabel(f->name,ww);
			vb->addWidget(l);
		}else
		if(f->child) {
			QComboBox *cb = new QComboBox(ww);
			cb->setProperty("fuse",QVariant::fromValue((void*)f));
			QObject::connect(cb,SIGNAL(currentIndexChanged(int)),this,SLOT(FuseSelected(int)));
			cb->setMinimumWidth(445);
			cb->setMaximumWidth(445);
			cb->setMaxVisibleItems(28);
			vb->addWidget(cb);
			for(c = f->child; c; c = c->next) {
				cb->addItem((const char *)c->name);
			}
		}else{
			QCheckBox *cb = new QCheckBox((const char *)f->name,ww);
			cb->setProperty("fuse",QVariant::fromValue((void*)f));
			QObject::connect(cb,SIGNAL(stateChanged(int)),this,SLOT(FuseChecked(int)));
			cb->setMinimumWidth(445);
			cb->setMaximumWidth(445);
			vb->addWidget(cb);
		}
	}
	fusebox->setWidget(ww);
	
	bIgnore = false;
	UpdateFuseBox();
}

//---------------------------------------------------------

void RavrProgQt::UpdateFuseBox()
{
	QWidget *w = fusebox->widget();
	if(w) {
		QObjectList l = w->children();
		int c = l.count();
		for(int i = 0; i < c; i++) {
			QObject *o = l.at(i);
			if(o->inherits("QCheckBox")) {
				QVariant qv = o->property("fuse");
				if(qv.isValid()) {
					void *v = qv.value<void*>();
					AvrFuse *f = (AvrFuse*)v;
					QCheckBox *cb = (QCheckBox*)o;
					cb->setCheckState(f->Get() ? Qt::Checked : Qt::Unchecked);
				}else{
					printf("ReadFuse Invalid pointer\n");
				}
			}else
			if(o->inherits("QComboBox")) {
				QVariant qv = o->property("fuse");
				if(qv.isValid()) {
					void *v = qv.value<void*>();
					AvrFuse *f = (AvrFuse*)v;
					QComboBox *cb = (QComboBox*)o;
					cb->setCurrentIndex(f->GetSelect());
				}else{
					printf("ReadFuse Invalid pointer\n");
				}
			}else
			if(o->inherits("QLabel")) {
			}else{
				printf("ReadFuse unknown widget\n");
			}
		}	
	}
}

//Fuse Tab
//-------------------------------------------------------------------------------------------------

bool RavrProgQt::Enter()
{
	printf("Entering programming mode: ");

	if(!progifc) {
		puts("NOT CONNECTED");
		return false;
	}

	if(progifc->Enter()) {
		puts("OK");
		return true;
	}else{
		puts("FAILED");
		return false;
	}
}

//---------------------------------------------------------

void RavrProgQt::Leave()
{
	printf("Leaving  Programming mode: ");

	if(!progifc) {
		puts("NOT CONNECTED");
		return;
	}

	if(progifc->Leave()) {
		puts("OK");
	}else{
		puts("FAILED");
	}
}

//-------------------------------------------------------------------------------------------------
//Setup

RavrProgQt::RavrProgQt()
{
    ui.setupUi(this);

//---------------------------------------------------------
// Programmer Tab

	prog_list = GetProgrammerList();
	progif_list = prog_list->interface;
	progifc = 0;
	progif = 0;
	prog = 0;
	device = 0;
	bAuto = false;
	bIgnore = false;
	ign = false;
	devname = "xx";

	//Programmer
	for(Programmer *p = prog_list; p; p = p->next) {
		ui.ProgrammerCombo->addItem(p->name());
	}

	fusebox = new QScrollArea(ui.tab_fuse);
	fusebox->setGeometry(QRect(9, 13, 480, 301));


	ProgChanged(0);

	QObject::connect(ui.ProgrammerCombo,SIGNAL(currentIndexChanged(int)),this,SLOT(ProgChanged(int)));
	QObject::connect(ui.InterfaceCombo, SIGNAL(currentIndexChanged(int)),this,SLOT(IfChanged(int)));

	QObject::connect(ui.PClockCombo,SIGNAL(currentIndexChanged(int)),this,SLOT(PClockChanged(int)));
	QObject::connect(ui.EClockCombo,SIGNAL(currentIndexChanged(int)),this,SLOT(EClockChanged(int)));
	QObject::connect(ui.pushButton_ApplyP,SIGNAL(clicked()),this,SLOT(ApplyP()));
	QObject::connect(ui.pushButton_ApplyE,SIGNAL(clicked()),this,SLOT(ApplyE()));

	QObject::connect(ui.pushButton_Refresh,SIGNAL(clicked()),this,SLOT(Refresh()));
	QObject::connect(ui.pushButton_Connect,SIGNAL(clicked()),this,SLOT(Connect()));
	QObject::connect(ui.pushButton_Refresh_AVR,SIGNAL(clicked()),this,SLOT(RefreshAVR()));
	QObject::connect(ui.DeviceCombo,SIGNAL(currentIndexChanged(int)),this,SLOT(DeviceChanged(int)));

//---------------------------------------------------------
//Flash Tab

	QObject::connect(ui.pushButton_ChipErase,SIGNAL(clicked()),this,SLOT(ChipErase()));

	QObject::connect(ui.pushButton_Read,SIGNAL(clicked()),this,SLOT(ReadFlash()));
	QObject::connect(ui.pushButton_Write,SIGNAL(clicked()),this,SLOT(WriteFlash()));
	QObject::connect(ui.pushButton_Verify,SIGNAL(clicked()),this,SLOT(VerifyFlash()));
	QObject::connect(ui.pushButton_Select,SIGNAL(clicked()),this,SLOT(SelectFlash()));

	QObject::connect(ui.pushButton_Read_2,SIGNAL(clicked()),this,SLOT(ReadEeprom()));
	QObject::connect(ui.pushButton_Write_2,SIGNAL(clicked()),this,SLOT(WriteEeprom()));
	QObject::connect(ui.pushButton_Verify_2,SIGNAL(clicked()),this,SLOT(VerifyEeprom()));
	QObject::connect(ui.pushButton_Select_2,SIGNAL(clicked()),this,SLOT(SelectEeprom()));

//---------------------------------------------------------
//Fuse Tab

	QObject::connect(ui.tabWidget,SIGNAL(currentChanged(int)),this,SLOT(TabChanged(int)));

	QObject::connect(ui.pushButton_ReadFuse,SIGNAL(clicked()),this,SLOT(ReadFuse()));
	QObject::connect(ui.pushButton_WriteFuse,SIGNAL(clicked()),this,SLOT(WriteFuse()));
	QObject::connect(ui.pushButton_VerifyFuse,SIGNAL(clicked()),this,SLOT(VerifyFuse()));
	QObject::connect(ui.pushButton_DefaultFuse,SIGNAL(clicked()),this,SLOT(DefaultFuse()));

	ui.lineEdit_Fuses->setInputMask(">HH HH HH HH"); //XXX xm avr32
	QObject::connect(ui.lineEdit_Fuses,SIGNAL(textEdited(const QString&)),this,SLOT(FuseEdited(const QString&)));
	QObject::connect(ui.lineEdit_Fuses,SIGNAL(editingFinished()),this,SLOT(FuseEditFinished()));
}

//---------------------------------------------------------

RavrProgQt::~RavrProgQt()
{
	if(progifc) {
		Connect(); //Disconnect
	}
	FreeProgrammerList();
}

//Setup
//-------------------------------------------------------------------------------------------------

