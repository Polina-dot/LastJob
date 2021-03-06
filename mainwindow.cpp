#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    com = new Communicator();
    connect(com,&Communicator::resp_countries,this,&MainWindow::resp_countries);
    connect(com,&Communicator::resp_summary,this,&MainWindow::resp_summary);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_request_clicked()
{
    //com->getCountries();
     com->getSummary();
}

//Слот получения списка стран
void MainWindow::resp_countries(QByteArray resp)
{
    // То создаём объект Json Document, считав в него все данные из ответа
      QJsonDocument document = QJsonDocument::fromJson(resp);

      // Забираем из документа корневой объект
      QJsonObject root = document.object();
      /* Находим объект "departament", который располагается самым первым в корневом объекте.
       * С помощью метода keys() получаем список всех объектов и по первому индексу
       * забираем название объекта, по которому получим его значение
       * */
      ui->textEdit->clear();

          ui->textEdit->setText(document.toJson(QJsonDocument::Indented));

      }

}

void MainWindow::resp_summary(QByteArray resp)
{
    // То создаём объект Json Document, считав в него все данные из ответа
      QJsonDocument document = QJsonDocument::fromJson(resp);

      // Забираем из документа корневой объект
      QJsonObject root = document.object();
      /* Находим объект "departament", который располагается самым первым в корневом объекте.
       * С помощью метода keys() получаем список всех объектов и по первому индексу
       * забираем название объекта, по которому получим его значение
       * */
    ui->textEdit->clear();
    // Проверка входный данных
    if (root.keys().size()>1){
        QJsonObject global=root ["Global"].toObject();
        ui->textEdit->setText(document.toJson(QJsonDocument::Indented));
        int wrld_issues=global.value("NewConfirmed").toInt();
        QJsonObject a= global.value("NewConfirmed").toObject();
        ui->lcdNumber_world->display(world_issues);
}
