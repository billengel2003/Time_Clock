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
    QString MakeTimeNice(const QString &sArg);
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
    void AddNote(QListWidget * lw, const QString &client_name, QString note);
    void LoadClientInfo(QListWidget * lw, const QString &client_name);
    void LoadNotes(QListWidget * lw, const QString &client_name);
<<<<<<< HEAD
    void EditClient(const QString &phone, const QString &email,
=======
    bool EditClient(const QString &phone, const QString &email,
>>>>>>> 518fa2a255a233a3931f035f64372590ca09ee7d
                    const QString &addy, const QString &city, const QString &state,
                    const QString &zip, const QString &contact,
                    const QString &website, const QString &rateD, const QString &rateS,
                    const QString &rateI, const QString &rateDB, const QString &name);
    bool AddClient(const QString &phone, const QString &email,
                               const QString &addy, const QString &city, const QString &state,
                               const QString &zip, const QString &contact,
                               const QString &website, const QString &rateD, const QString &rateS,
                               const QString &rateI, const QString &rateDB, const QString &name);
    bool RemoveClient(const QString &client_name);
};

#endif // SQLMANAGER_H
