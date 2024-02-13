#include "model.h"
#include <QColor>

Model::Model(QObject *parent) :
    QSqlQueryModel(parent)
{
   // Конструктор будет пустой ;-)
}

// Метод для получения данных из модели
QVariant Model::data(const QModelIndex & index, int role) const {
   int columnId = role - Qt::UserRole - 1;
   QModelIndex modelIndex = this->index(index.row(), columnId);
   return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}
QHash<int, QByteArray> Model::roleNames() const {
   QHash<int, QByteArray> roles;
   roles[DateTimeRole] = "date";
   roles[PricePurchaseRole] = "purchase";
   roles[PriceSellRole] = "sell";
   return roles;
}
