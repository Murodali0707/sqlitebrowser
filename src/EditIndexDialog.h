#ifndef EDITINDEXDIALOG_H
#define EDITINDEXDIALOG_H

#include "sqlitetypes.h"

#include <QDialog>
#include <QModelIndex>

class DBBrowserDB;

namespace Ui {
class EditIndexDialog;
}

class EditIndexDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditIndexDialog(DBBrowserDB& db, const QString& indexName, bool createIndex, QWidget* parent = 0);
    ~EditIndexDialog();

private slots:
    void accept();
    void tableChanged(const QString& new_table, bool initialLoad = false);
    void checkInput();
    void addToIndex(const QModelIndex& idx = QModelIndex());
    void removeFromIndex(const QModelIndex& idx = QModelIndex());

private:
    DBBrowserDB& pdb;
    QString curIndex;
    sqlb::Index index;
    bool newIndex;
    Ui::EditIndexDialog* ui;

    void updateColumnLists();
    void updateSqlText();
};

#endif
