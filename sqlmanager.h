#ifndef SQLMANAGER_H
#define SQLMANAGER_H

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QComboBox>
#include <QListWidget>
#include <QDebug>
#include <QUuid>


class SqlManager
{
private:
    QSqlDatabase db_main;
    QSqlQuery * query;
    void Load_Client_Information(const QString &client_name);
    void Load_Client_Time_Clock(const QString &client_name);
    QString time_0, name_0;
    QUuid guid;
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
    void EditClient(const QString &phone, const QString &email,
                    const QString &addy, const QString &city, const QString &state,
                    const QString &zip, const QString &contact,
                    const QString &website, const QString &rateD, const QString &rateS,
                    const QString &rateI, const QString &rateDB, const QString &name);
};

#endif // SQLMANAGER_H
