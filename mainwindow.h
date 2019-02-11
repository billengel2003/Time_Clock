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

    void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_3_clicked();

    void on_actionAllPro_toggled(bool arg1);

    void on_pushButton_4_clicked();

    void on_actionEdit_Client_triggered();

    void on_pushButton_2_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pb_Update_Client_clicked();

private:
    // Members
    Ui::MainWindow * ui;
    SqlManager * sql;
    // Methods
    void LoadClient(const QString &name);
    bool Connected;
};

#endif // MAINWINDOW_H
