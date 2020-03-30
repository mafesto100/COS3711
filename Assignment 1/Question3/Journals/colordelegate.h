#ifndef COLORDELEGATE_H
#define COLORDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QDate>
#include <QColor>

class ColorDelegate: public QStyledItemDelegate
{
public:
    ColorDelegate();
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // COLORDELEGATE_H
