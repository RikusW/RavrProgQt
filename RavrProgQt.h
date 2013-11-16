// RavrProgQt.h
// vim:ts=4 sts=0 sw=4

#ifndef RavrProgQt_H
#define RavrProgQt_H

#include <QDialog>
#include "ui_RavrProgQt.h"
#include "../Rtk/rtypes.h"
#include <RavrProg.h>
#include <QScrollArea>


class Programmer;
class ProgIF;

class RavrProgQt : public QDialog
{
	Q_OBJECT

public:
	RavrProgQt();
	~RavrProgQt();

public slots:
//----Programmer Tab----

	void ProgChanged(int);
	void IfChanged(int);
	void PClockChanged(int i);
	void EClockChanged(int i);
	void ApplyP();
	void ApplyE();
	void Refresh(); //Port
	void Connect();
	void RefreshAVR();
	void DeviceChanged(int);

//-------Flash Tab------

	void ChipErase();

	void ReadFlash();
	void WriteFlash();
	void VerifyFlash();
	void SelectFlash();

	void ReadEeprom();
	void WriteEeprom();
	void VerifyEeprom();
	void SelectEeprom();

//-------Fuse Tab-------

	void TabChanged(int);

	void FuseChecked(int);
	void FuseSelected(int);
	void FuseEdited(const QString&);
	void FuseEditFinished();

	void ReadFuse();
	void WriteFuse();
	void VerifyFuse();
	void DefaultFuse();

//----------------------

private:

	bool Enter();
	void Leave();

	Device *device;
	void SetupFuseBox(Device *);
	void UpdateFuseBox();

	void SetFuseEdit();

	Ui_RavrProgQt ui;

//	u8 fcnt;
//	u8 fuses[32];

	Programmer *prog_list;
	Programmer *prog; //selected programmer
	ProgIF *progif_list;
	ProgIF *progif;  //selected if
	ProgIF *progifc; //connected if

	bool bAuto,bIgnore;

	bool ign;
	const char *devname;
	
	QScrollArea *fusebox;
};


#endif //RavrProgQt_H
