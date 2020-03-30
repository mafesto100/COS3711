#ifndef WIDGET_H
#define WIDGET_H

#include "colordelegate.h"

#include <QWidget>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
    QStandardItemModel *model;
    QSortFilterProxyModel *proxyModel;
    ColorDelegate* colorDelagate;
};
#endif // WIDGET_H
