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

    //void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_actionEdit_Client_triggered();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pb_Update_Client_clicked();

    void on_pushButton_clicked();

    void on_listWidget_2_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

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
