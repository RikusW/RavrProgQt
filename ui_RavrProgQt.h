/********************************************************************************
** Form generated from reading UI file 'RavrProgQt.ui'
**
** Created: Sun Nov 3 04:26:03 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAVRPROGQT_H
#define UI_RAVRPROGQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RavrProgQt
{
public:
    QTextEdit *textEdit;
    QTabWidget *tabWidget;
    QWidget *tab_prog;
    QWidget *verticalLayout_5;
    QGridLayout *gridLayout;
    QComboBox *InterfaceCombo;
    QLineEdit *SigEdit;
    QLabel *label_14;
    QLabel *label_3;
    QLabel *label_18;
    QSpacerItem *spacerItem;
    QComboBox *ProgrammerCombo;
    QComboBox *DeviceCombo;
    QLabel *label_16;
    QLineEdit *SerialEdit;
    QPushButton *pushButton_Connect;
    QLabel *label_8;
    QLabel *label;
    QPushButton *pushButton_Refresh;
    QComboBox *OsccalCombo;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_Refresh_AVR;
    QLabel *label_2;
    QComboBox *PortCombo;
    QSpacerItem *spacerItem1;
    QComboBox *PClockCombo;
    QComboBox *EClockCombo;
    QPushButton *pushButton_ApplyP;
    QPushButton *pushButton_ApplyE;
    QWidget *tab_flash;
    QWidget *verticalLayout_2;
    QVBoxLayout *vboxLayout;
    QSpacerItem *spacerItem2;
    QPushButton *pushButton_ChipErase;
    QSpacerItem *spacerItem3;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem4;
    QCheckBox *checkBox_Erase;
    QSpacerItem *spacerItem5;
    QCheckBox *checkBox_Verify;
    QSpacerItem *spacerItem6;
    QSpacerItem *spacerItem7;
    QGroupBox *groupBox_2;
    QWidget *verticalLayout_4;
    QVBoxLayout *vboxLayout1;
    QLineEdit *lineEdit_Flash;
    QHBoxLayout *hboxLayout1;
    QPushButton *pushButton_Read;
    QPushButton *pushButton_Write;
    QPushButton *pushButton_Verify;
    QPushButton *pushButton_Select;
    QGroupBox *groupBox;
    QWidget *verticalLayout_6;
    QVBoxLayout *vboxLayout2;
    QLineEdit *lineEdit_Eeprom;
    QHBoxLayout *hboxLayout2;
    QHBoxLayout *hboxLayout3;
    QPushButton *pushButton_Read_2;
    QPushButton *pushButton_Write_2;
    QPushButton *pushButton_Verify_2;
    QPushButton *pushButton_Select_2;
    QProgressBar *progressBar;
    QWidget *tab_fuse;
    QWidget *horizontalLayout_7;
    QHBoxLayout *hboxLayout4;
    QLabel *label_10;
    QLineEdit *lineEdit_Fuses;
    QWidget *horizontalLayout_5;
    QHBoxLayout *hboxLayout5;
    QPushButton *pushButton_ReadFuse;
    QPushButton *pushButton_WriteFuse;
    QPushButton *pushButton_VerifyFuse;
    QPushButton *pushButton_DefaultFuse;

    void setupUi(QDialog *RavrProgQt)
    {
        if (RavrProgQt->objectName().isEmpty())
            RavrProgQt->setObjectName(QString::fromUtf8("RavrProgQt"));
        RavrProgQt->resize(519, 560);
        RavrProgQt->setMinimumSize(QSize(519, 560));
        RavrProgQt->setMaximumSize(QSize(519, 560));
        textEdit = new QTextEdit(RavrProgQt);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 440, 501, 111));
        QFont font;
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferDefault);
        textEdit->setFont(font);
        textEdit->setUndoRedoEnabled(false);
        textEdit->setReadOnly(true);
        textEdit->setAcceptRichText(false);
        tabWidget = new QTabWidget(RavrProgQt);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 501, 421));
        tab_prog = new QWidget();
        tab_prog->setObjectName(QString::fromUtf8("tab_prog"));
        verticalLayout_5 = new QWidget(tab_prog);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setGeometry(QRect(10, 10, 471, 371));
        gridLayout = new QGridLayout(verticalLayout_5);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        InterfaceCombo = new QComboBox(verticalLayout_5);
        InterfaceCombo->setObjectName(QString::fromUtf8("InterfaceCombo"));
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InterfaceCombo->sizePolicy().hasHeightForWidth());
        InterfaceCombo->setSizePolicy(sizePolicy);

        gridLayout->addWidget(InterfaceCombo, 1, 1, 1, 2);

        SigEdit = new QLineEdit(verticalLayout_5);
        SigEdit->setObjectName(QString::fromUtf8("SigEdit"));
        SigEdit->setReadOnly(true);

        gridLayout->addWidget(SigEdit, 10, 1, 1, 2);

        label_14 = new QLabel(verticalLayout_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 3, 0, 1, 1);

        label_3 = new QLabel(verticalLayout_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_18 = new QLabel(verticalLayout_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout->addWidget(label_18, 1, 0, 1, 1);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 6, 0, 1, 3);

        ProgrammerCombo = new QComboBox(verticalLayout_5);
        ProgrammerCombo->setObjectName(QString::fromUtf8("ProgrammerCombo"));
        sizePolicy.setHeightForWidth(ProgrammerCombo->sizePolicy().hasHeightForWidth());
        ProgrammerCombo->setSizePolicy(sizePolicy);
        ProgrammerCombo->setMaxVisibleItems(15);

        gridLayout->addWidget(ProgrammerCombo, 0, 1, 1, 2);

        DeviceCombo = new QComboBox(verticalLayout_5);
        DeviceCombo->setObjectName(QString::fromUtf8("DeviceCombo"));
        DeviceCombo->setMaxVisibleItems(15);

        gridLayout->addWidget(DeviceCombo, 9, 1, 1, 2);

        label_16 = new QLabel(verticalLayout_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 0, 0, 1, 1);

        SerialEdit = new QLineEdit(verticalLayout_5);
        SerialEdit->setObjectName(QString::fromUtf8("SerialEdit"));
        SerialEdit->setReadOnly(true);

        gridLayout->addWidget(SerialEdit, 11, 1, 1, 2);

        pushButton_Connect = new QPushButton(verticalLayout_5);
        pushButton_Connect->setObjectName(QString::fromUtf8("pushButton_Connect"));

        gridLayout->addWidget(pushButton_Connect, 5, 0, 1, 3);

        label_8 = new QLabel(verticalLayout_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 11, 0, 1, 1);

        label = new QLabel(verticalLayout_5);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 10, 0, 1, 1);

        pushButton_Refresh = new QPushButton(verticalLayout_5);
        pushButton_Refresh->setObjectName(QString::fromUtf8("pushButton_Refresh"));
        pushButton_Refresh->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(pushButton_Refresh, 4, 2, 1, 1);

        OsccalCombo = new QComboBox(verticalLayout_5);
        OsccalCombo->setObjectName(QString::fromUtf8("OsccalCombo"));
        OsccalCombo->setMaxVisibleItems(8);

        gridLayout->addWidget(OsccalCombo, 12, 1, 1, 1);

        label_7 = new QLabel(verticalLayout_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 12, 0, 1, 1);

        label_4 = new QLabel(verticalLayout_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 9, 0, 1, 1);

        label_5 = new QLabel(verticalLayout_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(5));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        pushButton_Refresh_AVR = new QPushButton(verticalLayout_5);
        pushButton_Refresh_AVR->setObjectName(QString::fromUtf8("pushButton_Refresh_AVR"));
        pushButton_Refresh_AVR->setEnabled(false);
        pushButton_Refresh_AVR->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(pushButton_Refresh_AVR, 12, 2, 1, 1);

        label_2 = new QLabel(verticalLayout_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 7, 0, 1, 3);

        PortCombo = new QComboBox(verticalLayout_5);
        PortCombo->setObjectName(QString::fromUtf8("PortCombo"));
        PortCombo->setEnabled(true);
        PortCombo->setMinimumSize(QSize(200, 0));
        PortCombo->setEditable(true);

        gridLayout->addWidget(PortCombo, 4, 1, 1, 1);

        spacerItem1 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(spacerItem1, 8, 0, 1, 3);

        PClockCombo = new QComboBox(verticalLayout_5);
        PClockCombo->setObjectName(QString::fromUtf8("PClockCombo"));
        PClockCombo->setEditable(false);
        PClockCombo->setMaxVisibleItems(20);

        gridLayout->addWidget(PClockCombo, 2, 1, 1, 1);

        EClockCombo = new QComboBox(verticalLayout_5);
        EClockCombo->setObjectName(QString::fromUtf8("EClockCombo"));
        EClockCombo->setEditable(false);
        EClockCombo->setMaxVisibleItems(22);

        gridLayout->addWidget(EClockCombo, 3, 1, 1, 1);

        pushButton_ApplyP = new QPushButton(verticalLayout_5);
        pushButton_ApplyP->setObjectName(QString::fromUtf8("pushButton_ApplyP"));
        pushButton_ApplyP->setEnabled(false);

        gridLayout->addWidget(pushButton_ApplyP, 2, 2, 1, 1);

        pushButton_ApplyE = new QPushButton(verticalLayout_5);
        pushButton_ApplyE->setObjectName(QString::fromUtf8("pushButton_ApplyE"));
        pushButton_ApplyE->setEnabled(false);

        gridLayout->addWidget(pushButton_ApplyE, 3, 2, 1, 1);

        tabWidget->addTab(tab_prog, QString());
        tab_flash = new QWidget();
        tab_flash->setObjectName(QString::fromUtf8("tab_flash"));
        verticalLayout_2 = new QWidget(tab_flash);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setGeometry(QRect(10, 10, 471, 371));
        vboxLayout = new QVBoxLayout(verticalLayout_2);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacerItem2);

        pushButton_ChipErase = new QPushButton(verticalLayout_2);
        pushButton_ChipErase->setObjectName(QString::fromUtf8("pushButton_ChipErase"));

        vboxLayout->addWidget(pushButton_ChipErase);

        spacerItem3 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacerItem3);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacerItem4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem4);

        checkBox_Erase = new QCheckBox(verticalLayout_2);
        checkBox_Erase->setObjectName(QString::fromUtf8("checkBox_Erase"));
        checkBox_Erase->setChecked(true);

        hboxLayout->addWidget(checkBox_Erase);

        spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem5);

        checkBox_Verify = new QCheckBox(verticalLayout_2);
        checkBox_Verify->setObjectName(QString::fromUtf8("checkBox_Verify"));
        checkBox_Verify->setChecked(true);

        hboxLayout->addWidget(checkBox_Verify);

        spacerItem6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem6);


        vboxLayout->addLayout(hboxLayout);

        spacerItem7 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout->addItem(spacerItem7);

        groupBox_2 = new QGroupBox(verticalLayout_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_4 = new QWidget(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setGeometry(QRect(9, 19, 451, 92));
        vboxLayout1 = new QVBoxLayout(verticalLayout_4);
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        lineEdit_Flash = new QLineEdit(verticalLayout_4);
        lineEdit_Flash->setObjectName(QString::fromUtf8("lineEdit_Flash"));

        vboxLayout1->addWidget(lineEdit_Flash);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        pushButton_Read = new QPushButton(verticalLayout_4);
        pushButton_Read->setObjectName(QString::fromUtf8("pushButton_Read"));

        hboxLayout1->addWidget(pushButton_Read);

        pushButton_Write = new QPushButton(verticalLayout_4);
        pushButton_Write->setObjectName(QString::fromUtf8("pushButton_Write"));

        hboxLayout1->addWidget(pushButton_Write);

        pushButton_Verify = new QPushButton(verticalLayout_4);
        pushButton_Verify->setObjectName(QString::fromUtf8("pushButton_Verify"));

        hboxLayout1->addWidget(pushButton_Verify);

        pushButton_Select = new QPushButton(verticalLayout_4);
        pushButton_Select->setObjectName(QString::fromUtf8("pushButton_Select"));

        hboxLayout1->addWidget(pushButton_Select);


        vboxLayout1->addLayout(hboxLayout1);


        vboxLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(verticalLayout_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_6 = new QWidget(groupBox);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setGeometry(QRect(10, 20, 451, 92));
        vboxLayout2 = new QVBoxLayout(verticalLayout_6);
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        lineEdit_Eeprom = new QLineEdit(verticalLayout_6);
        lineEdit_Eeprom->setObjectName(QString::fromUtf8("lineEdit_Eeprom"));

        vboxLayout2->addWidget(lineEdit_Eeprom);

        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        hboxLayout3 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        pushButton_Read_2 = new QPushButton(verticalLayout_6);
        pushButton_Read_2->setObjectName(QString::fromUtf8("pushButton_Read_2"));

        hboxLayout3->addWidget(pushButton_Read_2);

        pushButton_Write_2 = new QPushButton(verticalLayout_6);
        pushButton_Write_2->setObjectName(QString::fromUtf8("pushButton_Write_2"));

        hboxLayout3->addWidget(pushButton_Write_2);

        pushButton_Verify_2 = new QPushButton(verticalLayout_6);
        pushButton_Verify_2->setObjectName(QString::fromUtf8("pushButton_Verify_2"));

        hboxLayout3->addWidget(pushButton_Verify_2);

        pushButton_Select_2 = new QPushButton(verticalLayout_6);
        pushButton_Select_2->setObjectName(QString::fromUtf8("pushButton_Select_2"));

        hboxLayout3->addWidget(pushButton_Select_2);


        hboxLayout2->addLayout(hboxLayout3);


        vboxLayout2->addLayout(hboxLayout2);


        vboxLayout->addWidget(groupBox);

        progressBar = new QProgressBar(verticalLayout_2);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);
        progressBar->setOrientation(Qt::Horizontal);

        vboxLayout->addWidget(progressBar);

        tabWidget->addTab(tab_flash, QString());
        tab_fuse = new QWidget();
        tab_fuse->setObjectName(QString::fromUtf8("tab_fuse"));
        horizontalLayout_7 = new QWidget(tab_fuse);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setGeometry(QRect(9, 319, 471, 31));
        hboxLayout4 = new QHBoxLayout(horizontalLayout_7);
#ifndef Q_OS_MAC
        hboxLayout4->setSpacing(6);
#endif
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(horizontalLayout_7);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        hboxLayout4->addWidget(label_10);

        lineEdit_Fuses = new QLineEdit(horizontalLayout_7);
        lineEdit_Fuses->setObjectName(QString::fromUtf8("lineEdit_Fuses"));
        lineEdit_Fuses->setReadOnly(false);

        hboxLayout4->addWidget(lineEdit_Fuses);

        horizontalLayout_5 = new QWidget(tab_fuse);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setGeometry(QRect(10, 350, 471, 31));
        hboxLayout5 = new QHBoxLayout(horizontalLayout_5);
#ifndef Q_OS_MAC
        hboxLayout5->setSpacing(6);
#endif
        hboxLayout5->setContentsMargins(0, 0, 0, 0);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        hboxLayout5->setContentsMargins(0, 0, 0, 0);
        pushButton_ReadFuse = new QPushButton(horizontalLayout_5);
        pushButton_ReadFuse->setObjectName(QString::fromUtf8("pushButton_ReadFuse"));

        hboxLayout5->addWidget(pushButton_ReadFuse);

        pushButton_WriteFuse = new QPushButton(horizontalLayout_5);
        pushButton_WriteFuse->setObjectName(QString::fromUtf8("pushButton_WriteFuse"));

        hboxLayout5->addWidget(pushButton_WriteFuse);

        pushButton_VerifyFuse = new QPushButton(horizontalLayout_5);
        pushButton_VerifyFuse->setObjectName(QString::fromUtf8("pushButton_VerifyFuse"));

        hboxLayout5->addWidget(pushButton_VerifyFuse);

        pushButton_DefaultFuse = new QPushButton(horizontalLayout_5);
        pushButton_DefaultFuse->setObjectName(QString::fromUtf8("pushButton_DefaultFuse"));

        hboxLayout5->addWidget(pushButton_DefaultFuse);

        tabWidget->addTab(tab_fuse, QString());

        retranslateUi(RavrProgQt);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RavrProgQt);
    } // setupUi

    void retranslateUi(QDialog *RavrProgQt)
    {
        RavrProgQt->setWindowTitle(QApplication::translate("RavrProgQt", "RavrProgQt", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("RavrProgQt", "Clock Generator:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RavrProgQt", "Programming Clock:", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("RavrProgQt", "Select Interface:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("RavrProgQt", "Select Programmer:", 0, QApplication::UnicodeUTF8));
        pushButton_Connect->setText(QApplication::translate("RavrProgQt", "&Connect", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("RavrProgQt", "AVR Serial Number:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RavrProgQt", "Signature + JTAG ID:", 0, QApplication::UnicodeUTF8));
        pushButton_Refresh->setText(QApplication::translate("RavrProgQt", "&Refresh", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("RavrProgQt", "Osccal Values:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("RavrProgQt", "Select Device:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("RavrProgQt", "Select Port:", 0, QApplication::UnicodeUTF8));
        pushButton_Refresh_AVR->setText(QApplication::translate("RavrProgQt", "&Refresh", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RavrProgQt", "Device Information", 0, QApplication::UnicodeUTF8));
        pushButton_ApplyP->setText(QApplication::translate("RavrProgQt", "&Apply", 0, QApplication::UnicodeUTF8));
        pushButton_ApplyE->setText(QApplication::translate("RavrProgQt", "A&pply", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_prog), QApplication::translate("RavrProgQt", "Programmer", 0, QApplication::UnicodeUTF8));
        pushButton_ChipErase->setText(QApplication::translate("RavrProgQt", "&Chip Erase", 0, QApplication::UnicodeUTF8));
        checkBox_Erase->setText(QApplication::translate("RavrProgQt", "Erase &before writing flash", 0, QApplication::UnicodeUTF8));
        checkBox_Verify->setText(QApplication::translate("RavrProgQt", "Verify &after writing", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("RavrProgQt", "Flash", 0, QApplication::UnicodeUTF8));
        pushButton_Read->setText(QApplication::translate("RavrProgQt", "&Read", 0, QApplication::UnicodeUTF8));
        pushButton_Write->setText(QApplication::translate("RavrProgQt", "&Write", 0, QApplication::UnicodeUTF8));
        pushButton_Verify->setText(QApplication::translate("RavrProgQt", "&Verify", 0, QApplication::UnicodeUTF8));
        pushButton_Select->setText(QApplication::translate("RavrProgQt", "&Select File", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("RavrProgQt", "Eeprom", 0, QApplication::UnicodeUTF8));
        pushButton_Read_2->setText(QApplication::translate("RavrProgQt", "Rea&d", 0, QApplication::UnicodeUTF8));
        pushButton_Write_2->setText(QApplication::translate("RavrProgQt", "Writ&e", 0, QApplication::UnicodeUTF8));
        pushButton_Verify_2->setText(QApplication::translate("RavrProgQt", "Verif&y", 0, QApplication::UnicodeUTF8));
        pushButton_Select_2->setText(QApplication::translate("RavrProgQt", "Selec&t File", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_flash), QApplication::translate("RavrProgQt", "Flash", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("RavrProgQt", "Fuses:", 0, QApplication::UnicodeUTF8));
        pushButton_ReadFuse->setText(QApplication::translate("RavrProgQt", "&Read", 0, QApplication::UnicodeUTF8));
        pushButton_WriteFuse->setText(QApplication::translate("RavrProgQt", "&Write", 0, QApplication::UnicodeUTF8));
        pushButton_VerifyFuse->setText(QApplication::translate("RavrProgQt", "&Verify", 0, QApplication::UnicodeUTF8));
        pushButton_DefaultFuse->setText(QApplication::translate("RavrProgQt", "&Default", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_fuse), QApplication::translate("RavrProgQt", "Fuses", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RavrProgQt: public Ui_RavrProgQt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAVRPROGQT_H
