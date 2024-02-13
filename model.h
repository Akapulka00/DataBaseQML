#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QSqlQueryModel>
#include <QColor>
class Model : public QSqlQueryModel
{
   Q_OBJECT
   public:
    Q_INVOKABLE float prevPurchase;
    Q_INVOKABLE  float prevSell;
     int modelIndex;
   // Перечисляем все роли, которые будут использоваться в TableView
   enum Roles {
      DateTimeRole = Qt::UserRole + 1,    // дата
      PricePurchaseRole,                     // псевдослучаное число
      PriceSellRole                     // сообщение
   };
   // объявляем конструктор класса
   explicit Model(QObject *parent = 0);
   // Переопределяем метод, который будет возвращать данные
   QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
   protected:
   QHash<int, QByteArray> roleNames() const;
   void BranA();
   signals:

   public slots:
};

#endif // MODEL_H
