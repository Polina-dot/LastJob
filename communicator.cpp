#include "communicator.h"



Communicator::Communicator()
{
    base_url = "https://api.covid19api.com/";
}

Communicator::Communicator(QString url)
{
    base_url = url;
}

void Communicator::getCountries()
{
    //Базовый адрес для запроса
    QString url = base_url+"countries";
    reqID=1;
    //Запрос
    QNetworkRequest request =  QNetworkRequest(QUrl(url));
    //Объект доступа - содержит общую конфигурацию и настройки для посылаемых запросов
    QNetworkAccessManager *mngr = new QNetworkAccessManager(this);
    //Связь слотов и сигналов
    connect(mngr, &QNetworkAccessManager::finished,this,&Communicator::getResponse);
    mngr->get(request);
}
void Communicator:: getSummary()
{
    //Базовый адрес для запроса
    QString url = base_url+"summary";
    reqID=2;
    //Запрос
    QNetworkRequest request =  QNetworkRequest(QUrl(url));
    //Объект доступа - содержит общую конфигурацию и настройки для посылаемых запросов
    QNetworkAccessManager *mngr = new QNetworkAccessManager(this);
    //Связь слотов и сигналов
    connect(mngr, &QNetworkAccessManager::finished,this,&Communicator::getResponse);
    mngr->get(request);
}
void Communicator::getResponse(QNetworkReply *reply)
{
    QByteArray str = reply->readAll();
    qDebug() << str;
    switch (reqID) {
    case 1:
        emit resp_countries(str);
        break;
    case 2:
        emit resp_summary(str);
        break;
    }

    //Посылаем сигнал
    emit resp_countries(str);
}

