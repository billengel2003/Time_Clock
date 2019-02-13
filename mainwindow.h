#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QStandardItemModel>
#include <QtSql/QSql>
#include <QDebug>
#include "sqlmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionEdit_Client_triggered();

    void on_actionNotes_triggered();

    void on_actionAdd_Client_triggered();

    void on_cmb_name_Notes_currentIndexChanged(const QString &arg1);

    void on_pb_Update_Client_clicked();

    void on_pb_Update_Client_2_clicked();

    void on_pb_connect_Login_clicked();

    void on_pb_delete_Delete_clicked();

    void on_pb_clockin_Notes_clicked(bool checked);

    void on_pb_clockout_Notes_clicked(bool checked);

    void on_pb_submit_Notes_clicked();

    void on_listWidget_2_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_actionRemove_Client_triggered();

private:
    // Members
    Ui::MainWindow * ui;
    SqlManager * sql;
    // Methods
    void LoadClient(const QString &name);
    bool Connected;
    bool Clocked_In;
};

#endif // MAINWINDOW_H
