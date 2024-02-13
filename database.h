#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>


/* Директивы имен таблицы, полей таблицы и базы данных */
#define DATABASE_HOSTNAME   "GoldDatabase"
#define DATABASE_NAME       "data.sqlite"

class DataBase : public QObject
{
   Q_OBJECT

   public:
   explicit DataBase(QObject *parent = 0);
   ~DataBase();
    Q_INVOKABLE void fileDialog();
   void connectToDataBase();
   bool inserIntoTable(const QVariantList &data);
   Q_INVOKABLE  void closeDataBase();
    Q_INVOKABLE void openDataBase();
   signals:
   void databaseChanged();
   private:
   // Сам объект базы данных, с которым будет производиться работа
   QSqlDatabase    db;

   private:
   /* Внутренние методы для работы с базой данных
     * */

   bool restoreDataBase();
   bool createTable();
};

#endif // DATABASE_H
