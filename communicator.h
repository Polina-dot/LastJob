#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H
#include <qstring.h>
#include <QObject>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

class Communicator:public QObject
{
   Q_OBJECT
   QString base_url;
   int reqID=0;
public:

   /**
   /** * @brief Communicator конструктор класса без параметра
   /** */Communicator();
   /**
    /** * @brief Communicator конструктор класса с параметром
    /** * @param url
    /** */
   Communicator(QString url);

public slots:
    void getCountries();
void getSummary();
void getResponse(QNetworkReply *reply);
signals:
    void resp_countries(QByteArray str);
     void resp_summary(QByteArray str);
};


#endif // COMMUNICATOR_H
