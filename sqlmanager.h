#ifndef SQLMANAGER_H
#define SQLMANAGER_H

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QComboBox>
#include <QListWidget>
#include <QDebug>


class SqlManager
{
private:
    QSqlDatabase db_main;
    QSqlQuery * query;
    void Load_Client_Information(const QString &client_name);
    void Load_Client_Time_Clock(const QString &client_name);
    QString time_0, name_0;
public:
    SqlManager();
    ~SqlManager();
    QVector<QString> CI_ColumnsX;
    QVector<QString> TC_ColumnsX;
    QVector<QString> N_ColumnsX;
    bool Connect(const QString &user, const QString &pw, const QString &host = "localhost");
    void LoadClientList(QComboBox * cmb);
    void ClockIn(const QString &client_name);
    void ClockOut(const QString &client_name);
    void AddNote(const QString &client_name, const QString &note);
    void LoadListWidget(QListWidget * lw, const QString &client_name);
};

#endif // SQLMANAGER_H
