#include "colordelegate.h"

ColorDelegate::ColorDelegate()
{

}

void ColorDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QDate redDate = QDate::currentDate().addYears(-10);
    QDate greenDate = QDate::currentDate().addYears(-5);

    QModelIndex yearIndex = index.sibling(index.row(), 1);
    int journalDate = yearIndex.data().toInt();

    if(journalDate < redDate.year())
    {
        painter->fillRect(option.rect, QColor(255, 0, 0)); //older than 10 years, highlight red
    }
    else if(journalDate >= greenDate.year() && journalDate <= QDate::currentDate().year())
    {
        painter->fillRect(option.rect, QColor(0, 255, 0)); //within last 5 years, highliht green
    }

    QStyledItemDelegate::paint(painter, option, index);
}
