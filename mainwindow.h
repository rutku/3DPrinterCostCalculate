/****************************************************************************
**
** Copyright (C) 2019 Ramazan Utku
** Contact: ramazanutku@gmail.com
**
** This file is part of the examples of the Qt Toolkit.
**
** $3DPRINTERCOSTCALCULATER_BEGIN_LICENSE:BSD$
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** TURKISH
** Her hakkı saklıdır.
** Değişiklik yapılarak veya yapılmaksızın, yeniden dağıtmak veya kaynak ve ikili biçimlerde
** kullanmak, aşağıdaki koşullar yerine getirildiği takdirde serbesttir:
**
**  * Kaynak kodun yeniden dağıtımı; yukarıdaki telif hakkı uyarısını, şartlar listesini ve
**    aşağıdaki ret yazısını muhafaza etmelidir.
**  * İkili biçimde yeniden dağıtımında; yukarıdaki telif hakkı uyarısı, şartlar listesi ve
**    aşağıdaki ret yazısı dağıtımla birlikte gelen belgelendirmede ve/veya diğer materyallerde
**    tekrarlanmalıdır.
**
** İŞBU YAZILIM TELİF HAKKI SAHİPLERİ VE KATKIDA BULUNANLAR TARAFINDAN OLDUĞU GİBİ” SAĞLANMIŞTIR
** VE TİCARETE ELVERİŞLİLİK VE ÖZEL BİR AMACA UYGUNLUK İÇİN KAPALI BİR TAAHHÜT DE DAHİL OLMAK ÜZERE
** VE BUNUNLA KISITLI OLMAKSIZIN HER TÜRLÜ AÇIK YA DA KAPALI TAAHHÜT REDDEDİLMİŞTİR.
** HİÇBİR KOŞULDA TELİF HAKKI SAHİPLERİ VE KATKIDA BULUNANLAR; HER NE SEBEPLE OLUŞMUŞSA VE SÖZLEŞMEDE,
** KUSURSUZ SORUMLULUKTA, VEYA TAZMİNAT YÜKÜMLÜLÜĞÜNDE OLMAK ÜZERE HANGİ YÜKÜMLÜLÜK KURAMINDA
** YER ALIRSA ALSIN,İŞBU YAZILIMIN KULLANIMIYLA ORTAYA ÇIKAN DOĞRUDAN, DOLAYLI, TESADÜFİ, ÖZEL,
** CEZAİ VEYA BİR SEBEP SONUCUNDA OLUŞAN (YEDEK PARÇA VEYA HİZMETLERİN TEMİNİ; KULLANIM,
** VERİ VEYA RANDIMAN KAYBI; YA DA İŞ KESİNTİSİ DE DAHİL OLMAK ÜZERE VE BUNUNLA KISITLI KALMAKSIZIN)
** HERHANGİ BİR ZARAR İÇİN, BU GİBİ HASARLARIN OLASILIĞI HAKKINDA UYARILMIŞ OLSALAR BİLE, SİZE KARŞI
** SORUMLU DEĞİLLERDİR.
**
** $3DPRINTERCOSTCALCULATER_END_LICENSE$
**
****************************************************************************/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class About;

QT_BEGIN_NAMESPACE
class QAction;
class QDialogButtonBox;
class QGroupBox;
class QGridLayout;
class QVBoxLayout;
class QLabel;
class QLineEdit;
class QSpinBox;
class QDoubleSpinBox;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;
class QComboBox;
class QRadioButton;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void rb_weight_clicked();
    void rb_lenght_clicked();
    void btn_calculate_clicked();
    void cmb_filamentTypeChanged();


private:
    void createMenu();
    void printerInformation();
    void electricInformation();
    void filamentInformation();
    void workerInformation();
    void printingInformation();
    void calculateInformation();
    void resultInformation();
    void setup();
    void loadSettings();
    void saveSettings();
    void aboutClicked();

    About *aboutWindow;

    QString settingsFile;

    QGridLayout *mainLayout;

    //Printer Information
    QGridLayout *printerLayout;
    QLabel *lbl_printerCost;
    QLabel *lbl_printerLife;

    QDoubleSpinBox *spn_printerCost;
    QSpinBox *spn_printerLife;

    //Electric Information
    QGridLayout *electricLayout;
    QLabel *lbl_printerElectricityUsage;
    QLabel *lbl_electricityUsageFee;
    QDoubleSpinBox *spn_printerElectricityUsage;
    QDoubleSpinBox *spn_electricityUsageFee;

    //Filament Information
    QGridLayout *filamentLayout;
    QLabel *lbl_filamentType;
    QLabel *lbl_diameterOfFilament;
    QLabel *lbl_filamentDensity;
    QLabel *lbl_selectedFilamentDensity;
    QLabel *lbl_filamentWeight;
    QLabel *lbl_filamentFee;

    QComboBox *cmb_diameterOfFilament;
    QComboBox *cmb_filamentType;
    QDoubleSpinBox *spn_filamentWeight;
    QDoubleSpinBox *spn_filamentFee;

    //Worker Information
    QGridLayout *workerLayout;
    QLabel *lbl_workerHourlyRate;
    QDoubleSpinBox *spn_workerHourlyRate;

    //Printing Information
    QGridLayout *printingLayout;
    QGroupBox *box_weightOrLength;
    QRadioButton *rb_weight;
    QRadioButton *rb_lenght;
    QLabel *lbl_printingTime;
    QSpinBox *spn_printingTime;
    QDoubleSpinBox *spn_printingWeight;
    QSpinBox *spn_printingLenght;


    //Calculate
    QGridLayout *calculateLayout;
    QPushButton *btn_calculate;

    //Result
    QGridLayout *resultLayout;
    QTextEdit *txt_result;


    QMenuBar *menuBar;
    QGroupBox *printerInformationGridGroupBox;
    QGroupBox *electricInformationGridGroupBox;
    QGroupBox *workerInformaitonGridGroupBox;
    QGroupBox *filamentInformationGridGroupBox;
    QGroupBox *printingInformationGridGroupBox;
    QGroupBox *calculateGroupBox;
    QGroupBox *resultGroupBox;

    QMenu *fileMenu;
    QMenu *aboutMenu;
    QAction *exitAction;
    QAction *act_about;
    QAction *act_qtAbout;

    //Filaments
    QStringList filamentTypeList;
    QStringList diameterOfFilamentList;
    QStringList filamentDensityList;


};

#endif // MAINWINDOW_H
