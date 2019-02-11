#include "sqlmanager.h"

SqlManager::SqlManager() {
    db_main = QSqlDatabase::addDatabase("QMYSQL3");
    db_main.setDatabaseName("PsiPhi");
    query = new QSqlQuery(db_main);

}
SqlManager::~SqlManager() {
    delete query;
}
bool SqlManager::Connect(const QString &user, const QString &pw, const QString &host)
{
    db_main.setHostName(host);
    db_main.setUserName(user);
    db_main.setPassword(pw);
    if(db_main.open()){
        query->exec("SELECT column_name FROM information_schema.columns WHERE table_name = 'Client_Information'");
        while(query->next()){
            CI_ColumnsX.push_back(query->value(0).toString());
        }
        query->exec("SELECT column_name FROM information_schema.columns WHERE table_name = 'Time_Clock'");
        while(query->next()){
            TC_ColumnsX.push_back(query->value(0).toString());
        }
        query->exec("SELECT column_name FROM information_schema.columns WHERE table_name = 'Notes'");
        while(query->next()){
            N_ColumnsX.push_back(query->value(0).toString());
        }
        return true;
    } else {
        qDebug()<<db_main.lastError();
        return false;
    }
}

void SqlManager::LoadClientList(QComboBox *cmb)
{
    QString s("SELECT ");
    s.append(CI_ColumnsX[0]);
    s.append(" FROM Client_Information");
    query->exec(s);
    while(query->next()){
        QString name = query->value(0).toString();
        cmb->addItem(name);
    }
}
void SqlManager::LoadListWidget(QListWidget * lw, const QString &client_name)
{
    query->prepare("SELECT * FROM Client_Information WHERE Name = (:client_name)");
    query->bindValue(":client_name", client_name);
    query->bindValue(":ci", CI_ColumnsX[0]);
    // Make a number for the session.
    guid = QUuid::createUuid();
    if(query->exec()){
        while(query->next()){
            for(int n = 1; n < CI_ColumnsX.size(); ++n){
                QString s =CI_ColumnsX[n] + ": " + query->value(n).toString();
                lw->addItem(s);
            }
        }
    }
}
void SqlManager::ClockIn(const QString &client_name)
{
    QString execute("INSERT INTO Time_Clock (Name, Date, Time_Start, Paid, GUID) VALUES ('");
    execute.append(client_name);
    execute.append("', CURDATE(), NOW(), 0, '");
    execute.append(guid.toString(QUuid::StringFormat::WithoutBraces));
    execute.append("');");
    if(query->exec(execute)){
        qDebug() << "ClockedIn";
    } else {
        qDebug()<<db_main.lastError();
    }
}
void SqlManager::ClockOut(const QString &client_name)
{
    QString execute("UPDATE Time_Clock SET Time_End = NOW() WHERE GUID = '");
    execute.append(guid.toString(QUuid::StringFormat::WithoutBraces));
    execute.append("';");
    qDebug() << execute;
    if(query->exec(execute)){
        qDebug() << "ClockedOut";
        guid = QUuid::createUuid();
    } else {
        qDebug()<<db_main.lastError();
    }
}
void SqlManager::EditClient(const QString &phone, const QString &email,
                            const QString &addy, const QString &city, const QString &state,
                            const QString &zip, const QString &contact,
                            const QString &website, const QString &rateD, const QString &rateS,
                            const QString &rateI, const QString &rateDB, const QString &name)
{
    QString s = QString("UPDATE Client_Information SET Phone = replace('%1', '-', ''),"
                        " Email = '%2', Address = '%3', City = '%4',"
                        " State = '%5', Zip = '%6',"
                        " Main_Contact = '%7', ").arg(phone, email, addy, city, state, zip, contact);

    QString D(rateD), I(rateI), S(rateS), DB(rateDB);
    if(rateD == "") { D = "0.00" ;}
    if(rateS == "") { S = "0.00" ;}
    if(rateI == "") { I = "0.00" ;}
    if(rateDB == "") { DB = "0.00" ;}
    QString s1 = QString("WebSite = '%1', Rate_Default = %2, Rate_Software = %3,"
                        " Rate_IT = %4, Rate_Database = %5 "
                        "WHERE Name = '%6';").arg(website, D, S, I, DB, name);
    QString s2 = s + s1;
    if(query->exec(s2)){
        qDebug() << "Client was updated";
    } else {
        qDebug()<<s2;
        qDebug()<<db_main.lastError();
    }

}
