#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QRegExp>
#include <Message.h>
#include <QDateTime>
#include <QByteArray>
#include <myparser.h>

namespace Ui {
    class MainWindow;
}

struct BoardElement {
    QString id;
};

struct FrameElement {
    QList<BoardElement *> boardElements;
};

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
//    QString theme;
//    QString title;
//    QString body;
//    QDateTime dateTime;
//    QString sender;
//    QString receiver;

private slots:
    void startParsing();

private:
    Message msg;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
