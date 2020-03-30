#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new QStandardItemModel();
    proxyModel = new QSortFilterProxyModel(this);

    proxyModel->setSourceModel(model);
    ui->tableView->setModel(proxyModel);


    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Author")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Year")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Title")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QString("Journal")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QString("Volume")));
    model->setHorizontalHeaderItem(5, new QStandardItem(QString("Issue")));
    model->setHorizontalHeaderItem(6, new QStandardItem(QString("Pages")));

    //populate the combobox with fileds
    ui->comboBox->insertItem(0, "Author", ui->author->text());
    ui->comboBox->insertItem(1, "Year", ui->year->text());
    ui->comboBox->insertItem(2, "Title", ui->title->text());
    ui->comboBox->insertItem(3, "Journal", ui->journal->text());
    ui->comboBox->insertItem(4, "Volume", ui->volume->text());
    ui->comboBox->insertItem(5, "Issue", ui->issue->text());

    colorDelagate = new ColorDelegate();

    //enable sorting by column
    ui->tableView->setSortingEnabled(true);

}

void Widget::on_pushButton_clicked() //adds references to the list
{

    QList<QStandardItem*> row;

    if(ui->year->value() <= QDate::currentDate().year())
    {
        row.append(new QStandardItem(ui->author->text()));
        row.append(new QStandardItem(ui->year->text()));
        row.append(new QStandardItem(ui->title->text()));
        row.append(new QStandardItem(ui->journal->text()));
        row.append(new QStandardItem(ui->volume->text()));
        row.append(new QStandardItem(ui->issue->text()));
        row.append(new QStandardItem(ui->pages->text()));

        model->appendRow(row);
        ui->tableView->setItemDelegateForRow(model->rowCount() - 1, colorDelagate);
    }
    else
    {
        QMessageBox::warning(0, "Invalid Year", "Entered year is later than current year!");
    }
        //clears the fields after adding an entry
    ui->author->clear();
    ui->year->setValue(0);
    ui->title->clear();
    ui->journal->clear();
    ui->volume->setValue(0);
    ui->issue->setValue(0);
    ui->pages->clear();
}

void Widget::on_pushButton_2_clicked() //removes a reference from the table
{
    QModelIndexList indexList = ui->tableView->selectionModel()->selectedRows();

    for(int i = 0; i < indexList.length(); i++)
    {
        QModelIndex index = indexList.at(i);
        int row = index.row();

        model->removeRow(row);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_3_clicked() //filters the references
{
    proxyModel->setFilterRegExp(QRegExp(ui->wildcard->text(), Qt::CaseInsensitive, QRegExp::FixedString));
    proxyModel->setFilterKeyColumn(ui->comboBox->currentIndex());
}

void Widget::on_pushButton_4_clicked() //clears the filter
{
    proxyModel->setFilterFixedString("");
}
