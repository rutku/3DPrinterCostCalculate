#include "mainwindow.h"
#include "about.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createMenu();
    setup();
    printerInformation();
    electricInformation();
    filamentInformation();
    workerInformation();
    printingInformation();
    calculateInformation();
    resultInformation();
    loadSettings();


    mainLayout = new QGridLayout;
    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(printerInformationGridGroupBox,0,0);
    mainLayout->addWidget(electricInformationGridGroupBox,0,1);
    mainLayout->addWidget(filamentInformationGridGroupBox,1,0);
    mainLayout->addWidget(workerInformaitonGridGroupBox,2,0);
    mainLayout->addWidget(printingInformationGridGroupBox,1,1);
    mainLayout->addWidget(calculateGroupBox,3,0);
    mainLayout->addWidget(resultGroupBox,3,1);

    QWidget *widget = new QWidget;
    widget->setLayout(mainLayout);

    setCentralWidget(widget);
    setWindowTitle(tr("3B Yazıcı Baskı Ücreti Hesaplama"));

    connect(rb_weight,SIGNAL(clicked()),this,SLOT(rb_weight_clicked()));
    connect(rb_lenght,SIGNAL(clicked()),this,SLOT(rb_lenght_clicked()));
    connect(btn_calculate,SIGNAL(clicked()),this,SLOT(btn_calculate_clicked()));
    connect(cmb_filamentType,SIGNAL(currentIndexChanged(int)),this,SLOT(cmb_filamentTypeChanged()));
}

MainWindow::~MainWindow()
{
    saveSettings();
}

void MainWindow::rb_weight_clicked()
{
    spn_printingWeight->setEnabled(true);
    spn_printingLenght->setEnabled(false);
}

void MainWindow::rb_lenght_clicked()
{
    spn_printingWeight->setEnabled(false);
    spn_printingLenght->setEnabled(true);
}

void MainWindow::btn_calculate_clicked()
{
    //Yazıcı Amortismanı = Baskı Süresi x ( Yazıcı Fiyatı / Yazıcı Ömrü)
    double printerAmortization = spn_printingTime->value() * (spn_printerCost->value()/ (double)spn_printerLife->value());
    //Elektrik Ücreti = Baskı Süresi x Birim Elektrik Ücreti x Elektrik Tüketimi
    double electricityFee = spn_printingTime->value() * spn_electricityUsageFee->value() * spn_printerElectricityUsage->value();
    double filamentFee = (spn_filamentFee->value() / (spn_filamentWeight->value() * 1000));
    if (rb_weight->isChecked()) {
        //Filament Ücreti = (Filament Ücreti / (Filament Ağırlığı x 1000gr)) * Baskı Ağırlığı
        filamentFee *= spn_printingWeight->value();
    }else{
        double materialDensity = lbl_selectedFilamentDensity->text().toDouble() / 1000; // g/cm3 -> g/mm3
        double diameterOfFilament = cmb_diameterOfFilament->currentText().toDouble();
        double lengthOfFilamentUsed = spn_printingLenght->value();
        double pi = M_PI;
        double pow = qPow((diameterOfFilament/2),2);
        filamentFee *=  materialDensity * pi * pow * lengthOfFilamentUsed;
    }

    //İşçi Ücreti = Saatlik Ücret x Baskı Süresi
    double workerFee = spn_workerHourlyRate->value() * spn_printingTime->value();

    double result = printerAmortization + electricityFee + filamentFee + workerFee;

    txt_result->clear();
    txt_result->append(QString("Yazıcı Amortismanı : %1").arg(printerAmortization));
    txt_result->append(QString("Elektrik Ücreti : %1").arg(electricityFee));
    txt_result->append(QString("Filament Ücreti : %1").arg(filamentFee));
    txt_result->append(QString("İşçi Ücreti : %1").arg(workerFee));
    txt_result->append(QString("Ücret : %1").arg(result));
}

void MainWindow::cmb_filamentTypeChanged()
{
    lbl_selectedFilamentDensity->setText(filamentDensityList.at(cmb_filamentType->currentIndex()));
}

void MainWindow::aboutClicked()
{
    aboutWindow->exec();
}

void MainWindow::createMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&Dosya"),this);
    exitAction = fileMenu->addAction(tr("Çıkış"));

    aboutMenu = new QMenu(tr("Hakkında"),this);
    act_about = aboutMenu->addAction(tr("Uygulama Hakkında"));
    act_qtAbout = aboutMenu->addAction(tr("Qt Hakkında"));

    statusBar()->showMessage(tr("3B Yazıcı Baskı Ücreti Hesaplama V0.1 / Ramazan Utku ramazanutku@gmail.com "));

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(aboutMenu);



    connect(exitAction, &QAction::triggered,this,&MainWindow::close);
    connect(act_about,&QAction::triggered,this,&MainWindow::aboutClicked);
    connect(act_qtAbout,&QAction::triggered,qApp,&QApplication::aboutQt);
}

void MainWindow::setup()
{
    settingsFile = QApplication::applicationDirPath() + "/settings.ini";

    aboutWindow = new About(this);

    filamentTypeList.append("PLA");
    filamentTypeList.append("ABS");
    filamentTypeList.append("TPU");
    filamentTypeList.append("PETG");
    filamentTypeList.append("PETT");
    filamentTypeList.append("HIPS");

    diameterOfFilamentList.append("1.75");
    diameterOfFilamentList.append("2.85");
    diameterOfFilamentList.append("3.0");

    filamentDensityList.append("1.27");
    filamentDensityList.append("1.05");
    filamentDensityList.append("1.30");
    filamentDensityList.append("1.25");
    filamentDensityList.append("1.45");
    filamentDensityList.append("1.04");
}

void MainWindow::printerInformation()
{
    printerInformationGridGroupBox = new QGroupBox(tr("Yazıcı Bilgileri"));
    printerInformationGridGroupBox->setFixedSize(240,100);
    printerLayout = new QGridLayout;

    lbl_printerCost = new QLabel(tr("Yazıcı Fiyatı"));
    lbl_printerLife = new QLabel(tr("Yazıcı Ömrü (Saat)"));
    spn_printerCost = new QDoubleSpinBox;
    spn_printerCost->setMinimum(1.0);
    spn_printerCost->setMaximum(100000);
    spn_printerLife = new QSpinBox;
    spn_printerLife->setMinimum(1);
    spn_printerLife->setMaximum(1000000);

    printerLayout->addWidget(lbl_printerCost,0,0);
    printerLayout->addWidget(spn_printerCost,0,1);
    printerLayout->addWidget(lbl_printerLife,1,0);
    printerLayout->addWidget(spn_printerLife,1,1);

    printerInformationGridGroupBox->setLayout(printerLayout);


}

void MainWindow::electricInformation()
{
    electricInformationGridGroupBox = new QGroupBox(tr("Elektrik Kullanım Bilgileri"));
    electricInformationGridGroupBox->setFixedSize(240,100);
    electricLayout = new QGridLayout;

    lbl_printerElectricityUsage = new QLabel(tr("Yazıcı Elektrik Kullanımı (kWh)"));
    lbl_electricityUsageFee = new QLabel(tr("Elektrik Birim Fiyatı (krş/kWh)"));
    spn_printerElectricityUsage = new QDoubleSpinBox;
    spn_printerElectricityUsage->setMinimum(0);
    spn_printerElectricityUsage->setMaximum(10000);
    spn_electricityUsageFee = new QDoubleSpinBox;
    spn_electricityUsageFee->setMinimum(0);
    spn_electricityUsageFee->setMaximum(100);


    electricLayout->addWidget(lbl_printerElectricityUsage,0,0);
    electricLayout->addWidget(spn_printerElectricityUsage,0,1);
    electricLayout->addWidget(lbl_electricityUsageFee,1,0);
    electricLayout->addWidget(spn_electricityUsageFee,1,1);

    electricInformationGridGroupBox->setLayout(electricLayout);

}

void MainWindow::filamentInformation()
{
    filamentInformationGridGroupBox = new QGroupBox(tr("Filament Bilgileri"));
    filamentLayout = new QGridLayout;

    lbl_filamentType = new QLabel(tr("Filament Tipi"));
    lbl_diameterOfFilament = new QLabel(tr("Filament Çapı (mm)"));
    lbl_filamentDensity = new QLabel(tr("Filament Yoğunluğu (g/cm3)"));
    lbl_selectedFilamentDensity = new QLabel("0.0");
    lbl_filamentWeight = new QLabel(tr("Filament Ağırlığı (kg)"));
    lbl_filamentFee = new QLabel(tr("Filament Ücreti"));

    cmb_filamentType = new QComboBox;
    cmb_filamentType->addItems(filamentTypeList);
    cmb_diameterOfFilament = new QComboBox;
    cmb_diameterOfFilament->addItems(diameterOfFilamentList);

    spn_filamentWeight = new QDoubleSpinBox;
    spn_filamentWeight->setMinimum(0);
    spn_filamentWeight->setMaximum(1000000);
    spn_filamentFee = new QDoubleSpinBox;
    spn_filamentFee->setMinimum(0);
    spn_filamentFee->setMaximum(100);


    filamentLayout->addWidget(lbl_filamentType,0,0);
    filamentLayout->addWidget(cmb_filamentType,0,1);
    filamentLayout->addWidget(lbl_diameterOfFilament,1,0);
    filamentLayout->addWidget(cmb_diameterOfFilament,1,1);
    filamentLayout->addWidget(lbl_filamentDensity,2,0);
    filamentLayout->addWidget(lbl_selectedFilamentDensity,2,1);
    filamentLayout->addWidget(lbl_filamentWeight,3,0);
    filamentLayout->addWidget(spn_filamentWeight,3,1);
    filamentLayout->addWidget(lbl_filamentFee,4,0);
    filamentLayout->addWidget(spn_filamentFee,4,1);

    filamentInformationGridGroupBox->setLayout(filamentLayout);
}

void MainWindow::workerInformation()
{
    workerInformaitonGridGroupBox = new QGroupBox(tr("İşçi Bilgileri"));
    workerLayout = new QGridLayout;

    lbl_workerHourlyRate = new QLabel(tr("İşçi Ücreti (Saat)"));
    spn_workerHourlyRate = new QDoubleSpinBox;

    workerLayout->addWidget(lbl_workerHourlyRate,0,0);
    workerLayout->addWidget(spn_workerHourlyRate,0,1);

    workerInformaitonGridGroupBox->setLayout(workerLayout);

}

void MainWindow::printingInformation()
{
    printingInformationGridGroupBox = new QGroupBox(tr("Baskı Bilgileri"));
    printingInformationGridGroupBox->setFixedSize(240,200);
    printingLayout = new QGridLayout;

    lbl_printingTime = new QLabel(tr("Baskı Süresi (Saat)"));
    box_weightOrLength = new QGroupBox();
    rb_weight = new QRadioButton(tr("Baskı Ağırlığı (gr)"));
    rb_weight->setChecked(true);
    rb_lenght = new QRadioButton(tr("Uzunluk (mm)"));

    spn_printingTime = new QSpinBox;
    spn_printingTime->setMinimum(0);
    spn_printingTime->setMaximum(1000000);
    spn_printingWeight = new QDoubleSpinBox;
    spn_printingWeight->setMinimum(0);
    spn_printingWeight->setMaximum(1000000);
    spn_printingLenght = new QSpinBox;
    spn_printingLenght->setMinimum(0);
    spn_printingLenght->setMaximum(100000000);
    spn_printingLenght->setEnabled(false);


    printingLayout->addWidget(lbl_printingTime,0,0);
    printingLayout->addWidget(spn_printingTime,0,1);
    printingLayout->addWidget(rb_weight,1,0);
    printingLayout->addWidget(spn_printingWeight,1,1);
    printingLayout->addWidget(rb_lenght,2,0);
    printingLayout->addWidget(spn_printingLenght,2,1);

    printingInformationGridGroupBox->setLayout(printingLayout);
}

void MainWindow::calculateInformation()
{
    calculateGroupBox = new QGroupBox(tr("Hesapla"));
    calculateLayout = new QGridLayout;

    btn_calculate = new QPushButton(tr("Hesapla"),this);
    btn_calculate->setFixedHeight(50);

    calculateLayout->addWidget(btn_calculate,0,0);


    calculateGroupBox->setLayout(calculateLayout);
}

void MainWindow::resultInformation()
{
    resultGroupBox = new QGroupBox(tr("Sonuç Ekranı"));
    resultGroupBox->setFixedSize(240,100);
    resultLayout = new QGridLayout;

    txt_result = new QTextEdit();
    txt_result->show();

    resultLayout->addWidget(txt_result,0,0);

    resultGroupBox->setLayout(resultLayout);
}

void MainWindow::loadSettings()
{
    QSettings settings(settingsFile,QSettings::IniFormat);
    settings.beginGroup("PrinterInformation");
    spn_printerCost->setValue(settings.value("PrinterCost",double(1.0)).toDouble());
    spn_printerLife->setValue(settings.value("PrinterLife",int(1)).toInt());
    settings.endGroup();
    settings.beginGroup("ElectricInformation");
    spn_electricityUsageFee->setValue(settings.value("ElectricityUsageFee",double(1.0)).toDouble());
    spn_printerElectricityUsage->setValue(settings.value("PrinterElectrictyUsage",double(1.0)).toDouble());
    settings.endGroup();
    settings.beginGroup("FilamentInformation");
    cmb_filamentType->setCurrentIndex(settings.value("FilamentType").toInt());
    cmb_diameterOfFilament->setCurrentIndex(settings.value("DiameterOfFilament").toInt());
    lbl_selectedFilamentDensity->setText(filamentDensityList.at(cmb_filamentType->currentIndex()));
    spn_filamentWeight->setValue(settings.value("FilamentWeight",double(1.0)).toDouble());
    spn_filamentFee->setValue(settings.value("FilamentFee",double(1.0)).toDouble());
    settings.endGroup();
    settings.beginGroup("WorkerInformation");
    spn_workerHourlyRate->setValue(settings.value("WorkerHourlyRate",double(1.0)).toDouble());
    settings.endGroup();
    settings.beginGroup("PrintingInformation");
    spn_printingTime->setValue(settings.value("PrintingTime",int(1)).toInt());
    spn_printingWeight->setValue(settings.value("PrintingWeight",double(1.0)).toDouble());
    spn_printingLenght->setValue(settings.value("PrintingLenght", int(1)).toInt());
    settings.endGroup();

}

void MainWindow::saveSettings()
{
    QSettings settings(settingsFile,QSettings::IniFormat);
    settings.beginGroup("PrinterInformation");
    settings.setValue("PrinterCost",spn_printerCost->value());
    settings.setValue("PrinterLife",spn_printerLife->value());
    settings.endGroup();
    settings.beginGroup("ElectricInformation");
    settings.setValue("ElectricityUsageFee",spn_electricityUsageFee->value());
    settings.setValue("PrinterElectrictyUsage",spn_printerElectricityUsage->value());
    settings.endGroup();
    settings.beginGroup("FilamentInformation");
    settings.setValue("FilamentType",cmb_filamentType->currentIndex());
    settings.setValue("DiameterOfFilament",cmb_diameterOfFilament->currentIndex());
    settings.setValue("FilamentWeight",spn_filamentWeight->value());
    settings.setValue("FilamentFee",spn_filamentFee->value());
    settings.endGroup();
    settings.beginGroup("WorkerInformation");
    settings.setValue("WorkerHourlyRate",spn_workerHourlyRate->value());
    settings.endGroup();
    settings.beginGroup("PrintingInformation");
    settings.setValue("PrintingTime",spn_printingTime->value());
    settings.setValue("PrintingWeight",spn_printingWeight->value());
    settings.setValue("PrintingLenght",spn_printingLenght->value());
    settings.endGroup();

}

