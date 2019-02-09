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
    if(query->exec()){
        while(query->next()){
            for(int n = 1; n < CI_ColumnsX.size(); ++n){
                QString s =CI_ColumnsX[n] + ": " + query->value(n).toString();
                lw->addItem(s);
            }
        }
    }
}
