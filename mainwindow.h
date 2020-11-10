#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <communicator.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Communicator* com;//Объект соединения с сервером
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_request_clicked();
    void resp_countries(QByteArray resp);
void resp_summary(QByteArray resp);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
