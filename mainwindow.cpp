#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Начальное состояние
    bookID=0;
    bShelfID=0;
    shelfID=0;
    ui->groupBox_Books->setEnabled(false);
    ui->groupBox_Shelf->setEnabled(false);
    ui->pushButton_delBShelf->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_addBShelf_clicked()
{
    //Создать шкаф
    BookShelf bs;
    //Добавить шкаф в список
    bookShelfs.push_back(bs);
    ui->listWidget_BShelfs->
            addItem(QString::number(bookShelfs.size()));
}

void MainWindow::on_listWidget_BShelfs_itemClicked(QListWidgetItem *item)
{
    //Получить ID шкафа
    bShelfID = item->text().toInt();
    //активировать элементы интерфейса
    ui->pushButton_delBShelf->setEnabled(true);
    ui->groupBox_Shelf->setEnabled(true);
    ui->pushButton_delShelf->setEnabled(false);
    //получить кол-во полок
    int shelfN = bookShelfs[bShelfID-1].getShelfsNumber();
    //Очистить список
    ui->listWidget_Shelfs->clear();
    ui->listWidget_Books->clear();
    //Наполнить список полок
    if(shelfN>0){
        for(int i=1;i<=shelfN;i++){
            ui->listWidget_Shelfs->
                    addItem(QString::number(i));
        }
    }
}

void MainWindow::on_pushButton_addSelf_clicked()
{
    //Создать полку добавить полку в шкаф
    bookShelfs[bShelfID-1].addShelf();
    //Обновить список
    int shelfN = bookShelfs[bShelfID-1].getShelfsNumber();
    ui->listWidget_Shelfs->addItem(QString::number(shelfN));
}

void MainWindow::on_listWidget_Shelfs_itemClicked(QListWidgetItem *item)
{
    //Активация списка книг
    ui->groupBox_Books->setEnabled(true);
    //Номер полки
    shelfID = item->text().toInt();
    //Активация кнопки удаления полки
    ui->pushButton_delShelf->setEnabled(true);
    //Обновление списка книг
    updateBookList();
}
//Обновление списка книг
void MainWindow::updateBookList(){
    //Очистка списка полок
    ui->listWidget_Books->clear();
    //Получение содержимого полки
    Shelf shelf = bookShelfs[bShelfID-1].getShelf(shelfID-1);
    //Получить количество книг
    int bookN = shelf.getBookN();
    if(bookN>0){
        //Отображение списка книг
        for (int i=1;i<=bookN;i++) {
            ui->listWidget_Books->addItem(QString::number(i));
        }
    }
}

void MainWindow::on_pushButton_addBook_clicked()
{
    //Получение параметров книги
    QString name = ui->lineEdit_name->text();
    QString author = ui->lineEdit_author->text();
    int pages = ui->spinBox_pages->value();
    //Создание объекта книги
    PrintBook pb;
    pb.setName(name.toStdString());
    pb.setPages(pages);
    //Добавить книгу в шкаф
    bookShelfs[bShelfID-1].addBook(pb,shelfID-1);
    //Обновить список книг
    updateBookList();
}

void MainWindow::on_listWidget_Books_itemClicked(QListWidgetItem *item)
{
    //Получаем ID книги
    bookID = item->text().toInt();
    //Получение книги
    PrintBook pb =
            bookShelfs[bShelfID-1].getBook(shelfID-1,bookID-1);
    //Обновление полей интерфейса
    ui->lineEdit_name->
            setText(QString::fromStdString(pb.getName()));
    ui->spinBox_pages->setValue(pb.getPages());
}

void MainWindow::on_pushButton_delBShelf_clicked()
{
    //Удалить шкаф
    bookShelfs.erase(bookShelfs.begin()+bShelfID-1);
    //Обновить список
    ui->listWidget_BShelfs->clear();//очистка
    int N = bookShelfs.size();//кол-во шкафов
    for (int i=1;i<=N;i++) {//добавление элементов
        ui->listWidget_BShelfs->addItem(QString::number(i));
    }
    //"Скрыть" списки книг и полок
    ui->groupBox_Books->setEnabled(false);
    ui->groupBox_Shelf->setEnabled(false);
}

void MainWindow::on_pushButton_delShelf_clicked()
{
    //Удаление полки
    bookShelfs[bShelfID-1].delShelf(shelfID-1);
    //Обновление списка
    //получить кол-во полок
    int shelfN = bookShelfs[bShelfID-1].getShelfsNumber();
    //Очистить список
    ui->listWidget_Shelfs->clear();
    ui->listWidget_Books->clear();
    //Наполнить список полок
    if(shelfN>0){
        for(int i=1;i<=shelfN;i++){
            ui->listWidget_Shelfs->
                    addItem(QString::number(i));
        }
    }
    //"Скрыть" список книг
    ui->groupBox_Books->setEnabled(false);
}

void MainWindow::on_action_triggered()
{
    QFile file("data.txt");
    if(file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out<<"BOOKSHELF DATA";
        //перебор всех шкафов
        for(int i=0; bookShelfs.size();i++){
            // Сохранить шкаф (ID; I)
            out <<1<<"\n";
            // Получить кол-во
            int shelfN = bookShelfs[i].getShelfsNumber();
                    //перебор всех полок
                    for (int j=0;j<shelfN; j++) {
                //Сохранить полку (ID: 2)
                out<<2<<"\n";
                // получить кол-во книг
                int bookN=bookShelfs[i].getShelf(j).getBookN();
                // Перебор всех книг
                for (int k=0;k<bookN; k++) {
                    // Сохранить книгу (ID: 2)
                   out<<3<<"\n";
                    PrintBook pb=bookShelfs[i].getBook(j,k);
                   out<<"\t"<<QString::fromStdString(pb.getName())<<"\n";
                   out<<"\t"<<QString::number(pb.getPages())<<"\n";
                }

            }
        }
    }
}

void MainWindow::on_action_2_triggered()
{
   QFile file("data.txt");
   if(file.open(QIODevice::ReadOnly)){
       QTextStream in(&file);
       QString line;
       bShelfID=0;
       shelfID=0;

       while (in.readLineInto(&line)){
           int id=line.toInt();
           BookShelf bs;
           Shelf shelf;
           PrintBook pb;


           switch(id){
           case 1:
               bookShelfs.push_back(bs);
               bShelfID+=1;
               break;
           case 2:
               bookShelfs[bShelfID-1].addShelf();
               shelfID+=1;
               break;
           case 3:
           pb.setName(in.readLine().toStdString());
           pb.setPages(in.readLine().toInt());
           bookShelfs[bShelfID-1].addBook(pb,shelfID-1);
           break;

           }

       }
           // Закрыть файл
           file.close();
           ui->listWidget_Books->clear();
            ui->listWidget_Shelfs->clear();
           ui->listWidget_BShelfs->clear();
           for (int i=1;1<=bookShelfs.size(); i++){
              ui->listWidget_BShelfs->addItem(QString::number(i));
           }
           ui->groupBox_Books->setEnabled(false);
           ui->groupBox_Shelf->setEnabled(false);
           }
   }

