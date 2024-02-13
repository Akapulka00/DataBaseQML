#include "database.h"
#include <QFileDialog>

DataBase::DataBase(QObject *parent) : QObject(parent)
{
    // Подключаемся к базе данных
    this->connectToDataBase();
    /* После чего производим наполнение таблицы базы данных
     * контентом, который будет отображаться в TableView
     * */

}

DataBase::~DataBase()
{

}

/* Методы для подключения к базе данных
 * */
void DataBase::connectToDataBase()
{

    if(!QFile("C:/example/" DATABASE_NAME).exists()){
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

/* Методы восстановления базы данных
 * */
bool DataBase::restoreDataBase()
{
    return false;
}

/* Метод для открытия базы данных
 * */
void DataBase::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName("D:/ModelViveh/" DATABASE_NAME);
    if(db.open()){

    } else {

    }
}

/* Методы закрытия базы данных
 * */
void DataBase::closeDataBase()
{
    db.close();

}
void DataBase::fileDialog()
{
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Open Database File", "", "Database Files (*.sqlite *.db)");
    if (!filePath.isEmpty()) {
         // здесь можно выполнить дополнительные действия с выбранным файлом, например, подключиться к нему
         db = QSqlDatabase::addDatabase("QSQLITE");
         db.setHostName(DATABASE_HOSTNAME);
         db.setDatabaseName(filePath);
         if(db.open()){

            emit databaseChanged();
         } else {

         }
    }
}
