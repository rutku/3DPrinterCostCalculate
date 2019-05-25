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

#include "about.h"
#include <QtWidgets>

About::About(QWidget *parent)
    : QDialog(parent)
{
    btn_close = new QPushButton(tr("Kapat"));
    QString appName = tr("3B Yazıcı Baskı Ücreti Hesaplama");
    QString uygulamaSurumu = "0.1";
    QString aboutUs = tr("Bu uygulama 3 boyutlu yazıcılarda maliyet"
                                "\nhesabı yapmak için geliştirilmiştir."
                                "\ngüncellemeler ve yeni uygulamalar için"
                                "\nlütfen takipte kalınız."
                                "\nBu uygulama BSD lisansı ile lisanslanmıştır."
                                "\n\n                  2019 - "
                                "\n                                            Ramazan Utku");

    lbl_appName = new QLabel(appName,this);
    lbl_appName->setStyleSheet("font-weight: bold");
    lbl_appName->setFixedWidth(200);
    lbl_appName->setFixedHeight(20);

    lbl_appVer = new QLabel(uygulamaSurumu,this);
    lbl_appVer->setFixedWidth(20);
    lbl_appVer->setFixedHeight(20);

    lbl_about = new QLabel(aboutUs,this);
    lbl_about->setFixedHeight(200);
    QFont myFont;
    myFont.setPixelSize(12);
    lbl_about->setFont(myFont);

    btn_close = new QPushButton(tr("Kapat"),this);
    btn_close->setFixedWidth(70);
    btn_gitHub = new QToolButton(this);
    btn_gitHub->setIcon(QIcon(":/icons/github.png"));
    btn_gitHub->setIconSize(QSize(50,50));

    btn_twitter = new QToolButton(this);
    btn_twitter->setIcon(QIcon(":/icons/twitter.png"));
    btn_twitter->setIconSize(QSize(50,50));

    btn_linkEdin= new QToolButton(this);
    btn_linkEdin->setIcon(QIcon(":/icons/linkedin.png"));
    btn_linkEdin->setIconSize(QSize(50,50));

    btn_webSite = new QToolButton(this);
    btn_webSite->setIcon(QIcon(":/icons/website.png"));
    btn_webSite->setIconSize(QSize(50,50));

    btn_eMail = new QToolButton(this);
    btn_eMail->setIcon(QIcon(":/icons/email.png"));
    btn_eMail->setIconSize(QSize(50,50));

    QVBoxLayout *buttonLayer = new QVBoxLayout();
    buttonLayer->addWidget(btn_gitHub);
    buttonLayer->addWidget(btn_twitter);
    buttonLayer->addWidget(btn_linkEdin);
    buttonLayer->addWidget(btn_webSite);
    buttonLayer->addWidget(btn_eMail);

    QHBoxLayout *appTitle = new QHBoxLayout();
    appTitle->addItem(new QSpacerItem(30,10,QSizePolicy::Expanding,QSizePolicy::Expanding));
    appTitle->addWidget(lbl_appName);
    appTitle->addWidget(lbl_appVer);
    appTitle->addItem(new QSpacerItem(40,10,QSizePolicy::Expanding,QSizePolicy::Expanding));

    QHBoxLayout *buttonCloseLayer = new QHBoxLayout();
    buttonCloseLayer->addItem(new QSpacerItem(40,10,QSizePolicy::Expanding,QSizePolicy::Expanding));
    buttonCloseLayer->addWidget(btn_close);

    QVBoxLayout *writeLayer = new QVBoxLayout();
    writeLayer->addLayout(appTitle);
    writeLayer->addWidget(lbl_about);
    writeLayer->addLayout(buttonCloseLayer);

    QHBoxLayout *mainLayer = new QHBoxLayout(this);
    mainLayer->addLayout(buttonLayer);
    mainLayer->addLayout(writeLayer);

    connect(btn_gitHub, SIGNAL(clicked(bool)),this,SLOT(btn_GitHubClicked()));
    connect(btn_twitter, SIGNAL(clicked(bool)),this,SLOT(btn_TwitterClicked()));
    connect(btn_linkEdin, SIGNAL(clicked(bool)),this,SLOT(btn_LinkEdinClicked()));
    connect(btn_webSite, SIGNAL(clicked(bool)),this,SLOT(btn_WebSiteClicked()));
    connect(btn_eMail, SIGNAL(clicked(bool)),this,SLOT(btn_EMailClicked()));

    connect(btn_close, SIGNAL(clicked(bool)),this,SLOT(close()));

    setLayout(mainLayer);
    setWindowTitle(tr("Hakkında"));
    setFixedHeight(350);
    setFixedWidth(340);
}
About::~About()
{

}

void About::btn_GitHubClicked()
{
    QString adres = "https://github.com/rutku";
    QDesktopServices::openUrl(QUrl(adres));
}

void About::btn_WebSiteClicked()
{
    QString adres = "https://rmznutku.blogspot.com.tr/";
    QDesktopServices::openUrl(QUrl(adres));
}

void About::btn_EMailClicked()
{
    QString adres = "mailto:ramazanutku@gmail.com";
    QDesktopServices::openUrl(QUrl(adres));

}

void About::btn_LinkEdinClicked()
{
    QString adres = "https://www.linkedin.com/in/ramazan-utku-78a767a8/";
    QDesktopServices::openUrl(QUrl(adres));
}

void About::btn_TwitterClicked()
{
    QString adres = "https://twitter.com/rmznutku";
    QDesktopServices::openUrl(QUrl(adres));

}
