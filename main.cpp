#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <database.h>
#include <model.h>
#include <QtQml>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QQmlApplicationEngine engine;

   // Инициализируем базу данных
   DataBase *database = new DataBase();
   // Объявляем и инициализируем модель представления данных
   Model *model = new Model();

   model->setQuery("SELECT DateTime, PricePurchase, PriceSell FROM gold");

   engine.rootContext()->setContextProperty("myModel", model);
   engine.rootContext()->setContextProperty("myDatabase", database);

   QObject::connect(database, &DataBase::databaseChanged, [&model](){
      model->setQuery("SELECT DateTime, PricePurchase, PriceSell FROM gold");
   });

   engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

   return app.exec();
}
