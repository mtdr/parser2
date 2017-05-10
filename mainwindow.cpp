#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startParsing();
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(startParsing()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::startParsing()
{
    QFile file("./msg.txt");

    if (!file.open(QFile::ReadOnly))
    {
        qDebug() << "Fail to open file";
        return;
    }
    QTextStream ts(&file);

    QString input;
    input = ts.readAll();

    MyParser mps;
    Message msg;
    msg = mps.parseMail(input);

    qDebug() << "Sender: "<< msg.getSender();
    qDebug() << "Receiver: " << msg.getReceiver();
    qDebug() << "Time: " << msg.getDateTime();
    qDebug() << "Theme: " << msg.getTheme();
    qDebug() << "Body: " << msg.getBody();
    qDebug() << "Title: " << msg.getTitle();



//    qDebug() << input;

//    //    QRegExp big = QRegExp("[^\[\]\r\\]");
//    //    int aa = big.indexIn(input);
//    //    QStringList a = big.capturedTexts();
//    //    qDebug() << QString::number(aa);

//    QStringList allFields = input.split("\\r\\n");
//    //    for(int i=0; i<allFields.count(); i++)
//    //    {
//    //        qDebug()<<""<< i << " Da Value Thing: " << allFields.at(i);
//    //    }


//    // Receiver WORKS
//    QRegExp rReceiver = QRegExp("Delivered-To:\\s*([A-z0-9_\.-]+@[A-z0-9\.]+)");

//    rReceiver.indexIn(allFields.at(0));
//    QStringList qsl = rReceiver.capturedTexts();
//    receiver = qsl.at(1);
//    qDebug()<<"Receiver - " << receiver;
//    msg.setReceiver(receiver);

//    // THEME WORKS
//    QRegExp rTheme = QRegExp("Subject:\\s([A-z0-9=?-]*\\br\\b)");
//    int nrTheme = rTheme.indexIn(input);
//    QStringList stlTheme = rTheme.capturedTexts();
//    QString theme = stlTheme.at(0);
//    theme.remove(theme.size()-2,2);
//    theme.remove(0,9);
//    if (theme.contains("=?UTF-8"))
//    {
//        theme.remove(0,9);
//        QByteArray ba;
//        ba.append(theme);
//        theme = QByteArray::fromBase64(ba);
//    }
//    qDebug() << "Theme - " << theme;
//    msg.setTheme(theme);


//    // SENDER WORKS
//    QRegExp rSender = QRegExp("Return-path:\\s*<([A-z0-9_\.-]+@[A-z0-9\.]+)");
//    int nrSender = rSender.indexIn(input);
//    //    qDebug()<<QString::number(nrSender);
//    QStringList stlSender = rSender.capturedTexts();
//    QString sender = stlSender.at(0);
//    sender.remove(0, 14);
//    qDebug()<<"Sender - "<< sender;
//    msg.setSender(stlSender.at(0));

//    // DATE WORKS
//    QRegExp rDate = QRegExp("Date:\\s([A-z0-9,\\s:+]*\\br\\b)");
//    int nrDate = rDate.indexIn(input);
//    //qDebug()<<"num Date - "<<QString::number(nrDate);
//    QStringList stlDate = rDate.capturedTexts();
//    QString test = stlDate.at(1);
//    test.remove(test.length()-2,2);
//    qDebug()<<"Date - "<<test;
//    QDateTime dt = QDateTime::fromString(stlDate.at(1), Qt::RFC2822Date);
//    msg.setDateTime(dt);
//    qDebug() << dt.toString();



    file.close();
}
