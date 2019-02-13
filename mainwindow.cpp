#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Connected = false;
    Clocked_In = false;
    sql = new SqlManager();
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(2);
    ui->le_host_Login->setText("127.0.0.1");
    ui->le_pw_Login->setEchoMode(QLineEdit::Password);
    ui->le_pw_Login->setInputMethodHints(Qt::ImhHiddenText|
                                        Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);
    this->setWindowTitle("Time Clock");

    ui->cmb_name_Edit->addItem("");
    ui->cmb_name_Notes->addItem("");
    ui->cmb_name_Delete->addItem("");
}

MainWindow::~MainWindow()
{
    delete sql;
    delete ui;
}
<<<<<<< HEAD
void MainWindow::on_pushButton_clicked()
{
    QPalette pal = ui->pushButton_2->palette();
    pal.setColor(QPalette::Button, QColor(Qt::white));
    ui->pushButton_2->setAutoFillBackground(true);
    ui->pushButton_2->setPalette(pal);
    ui->pushButton_2->update();
    QPalette pal1 = ui->pushButton->palette();
    pal1.setColor(QPalette::Button, QColor(Qt::red));
    ui->pushButton->setAutoFillBackground(true);
    ui->pushButton->setPalette(pal1);
    ui->pushButton->update();
    //
    ui->listWidget_2->addItem("Clocked out: ");
    sql->ClockOut(ui->comboBox->currentText());
    Clocked_In = false;
}
void MainWindow::on_pushButton_2_clicked(bool checked)
=======


void MainWindow::on_pb_connect_Login_clicked()
>>>>>>> 518fa2a255a233a3931f035f64372590ca09ee7d
{
    if(sql->Connect(ui->le_user_Login->text(), ui->le_pw_Login->text(), ui->le_host_Login->text())){
        Connected = true;

        sql->LoadClientList(ui->cmb_name_Edit);
        sql->LoadClientList(ui->cmb_name_Delete);
        sql->LoadClientList(ui->cmb_name_Notes);
        // Order important.
        ui->stackedWidget->setCurrentIndex(0);
        ui->cmb_name_Notes->setCurrentIndex(0);
        ui->cmb_name_Edit->setCurrentIndex(0);

    } else{
<<<<<<< HEAD
        QPalette pal = ui->pushButton_2->palette();
        pal.setColor(QPalette::Button, QColor(Qt::blue));
        ui->pushButton_2->setAutoFillBackground(true);
        ui->pushButton_2->setPalette(pal);
        ui->pushButton_2->update();
        QPalette pal1 = ui->pushButton->palette();
        pal1.setColor(QPalette::Button, QColor(Qt::white));
        ui->pushButton->setAutoFillBackground(true);
        ui->pushButton->setPalette(pal1);
        ui->pushButton->update();
        //
        ui->listWidget_2->addItem("Clocked In: ");
        sql->ClockIn(ui->comboBox->currentText());
        Clocked_In = true;

=======
        qDebug()<<"Did not Connect to SQL";
>>>>>>> 518fa2a255a233a3931f035f64372590ca09ee7d
    }
}

//Edit = 1;
//Notes = 0;
//Add = 3;
//Login = 2;
//

void MainWindow::on_actionEdit_Client_triggered()
{
<<<<<<< HEAD
    sql->AddNote(ui->listWidget_2, ui->comboBox->currentText(), ui->te_notes_Main->toPlainText());
    ui->te_notes_Main->setText("");
=======
    if(Connected){
        ui->stackedWidget->setCurrentIndex(1);
    }
>>>>>>> 518fa2a255a233a3931f035f64372590ca09ee7d
}
void MainWindow::on_actionNotes_triggered()
{
    if(Connected){
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void MainWindow::on_actionAdd_Client_triggered()
{
    if(Connected){
        ui->stackedWidget->setCurrentIndex(3);
    }
}

<<<<<<< HEAD


void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
=======
void MainWindow::on_actionRemove_Client_triggered()
>>>>>>> 518fa2a255a233a3931f035f64372590ca09ee7d
{
    if(Connected){
<<<<<<< HEAD
        sql->LoadClientInfo(ui->listWidget, arg1);
        sql->LoadNotes(ui->listWidget_2, arg1);
        if(Clocked_In){
            this->on_pushButton_clicked();
        }

=======
        ui->stackedWidget->setCurrentIndex(4);
>>>>>>> 518fa2a255a233a3931f035f64372590ca09ee7d
    }
}

void MainWindow::on_pb_Update_Client_clicked()
{
    if(Connected){
        sql->EditClient(ui->le_phone_Edit->text(), ui->le_email_Edit->text(), ui->le_addy_Edit->text(),
                        ui->le_city_Edit->text(), ui->le_state_Edit->text(), ui->le_zip_Edit->text(),
                        ui->le_contact_Edit->text(), ui->le_website_Edit->text(), ui->le_rateD_Edit->text(),
                        ui->le_rateS_Edit->text(), ui->le_rateI_Edit->text(), ui->le_rateDB_Edit->text(),
                        ui->cmb_name_Edit->currentText());
        ui->le_phone_Edit_2->clear();
        ui->le_email_Edit_2->clear();
        ui->le_addy_Edit_2->clear();
        ui->le_city_Edit_2->clear();
        ui->le_state_Edit_2->clear(); ui->le_zip_Edit_2->clear();
        ui->le_contact_Edit_2->clear();
        ui->le_website_Edit_2->clear();
        ui->le_rateD_Edit_2->clear();
        ui->le_rateS_Edit_2->clear();
        ui->le_rateI_Edit_2->clear();
        ui->le_rateDB_Edit_2->clear();
    }
}


void MainWindow::on_listWidget_2_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(Connected){
        ui->te_notes_Main->setText(current->text().split('\n')[1]);
    }
}

<<<<<<< HEAD

void MainWindow::on_listWidget_2_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(Connected){
        ui->te_notes_Main->setText(current->text().split('\n')[1]);
    }
}
=======
void MainWindow::on_pb_Update_Client_2_clicked()
{
    if(Connected){
        sql->AddClient(ui->le_phone_Edit_2->text(), ui->le_email_Edit_2->text(), ui->le_addy_Edit_2->text(),
                       ui->le_city_Edit_2->text(), ui->le_state_Edit_2->text(), ui->le_zip_Edit_2->text(),
                       ui->le_contact_Edit_2->text(), ui->le_website_Edit_2->text(), ui->le_rateD_Edit_2->text(),
                       ui->le_rateS_Edit_2->text(), ui->le_rateI_Edit_2->text(), ui->le_rateDB_Edit_2->text(),
                       ui->le_name_Edit_2->text());

        ui->le_phone_Edit_2->clear();
        ui->le_email_Edit_2->clear();
        ui->le_addy_Edit_2->clear();
        ui->le_city_Edit_2->clear();
        ui->le_state_Edit_2->clear(); ui->le_zip_Edit_2->clear();
        ui->le_contact_Edit_2->clear();
        ui->le_website_Edit_2->clear();
        ui->le_rateD_Edit_2->clear();
        ui->le_rateS_Edit_2->clear();
        ui->le_rateI_Edit_2->clear();
        ui->le_rateDB_Edit_2->clear();
        ui->le_name_Edit_2->clear();
    }

}

void MainWindow::on_cmb_name_Notes_currentIndexChanged(const QString &arg1)
{
    if(Connected){
        sql->LoadClientInfo(ui->listWidget, arg1);
        sql->LoadNotes(ui->listWidget_2, arg1);
        if(Clocked_In){
            this->on_pb_clockout_Notes_clicked(1);
        }

    }
}

void MainWindow::on_pb_delete_Delete_clicked()
{
    sql->RemoveClient(ui->pb_delete_Delete->text());
}

void MainWindow::on_pb_clockin_Notes_clicked(bool checked)
{
    if(checked){

    } else{
        QPalette pal = ui->pb_clockin_Notes->palette();
        pal.setColor(QPalette::Button, QColor(Qt::blue));
        ui->pb_clockin_Notes->setAutoFillBackground(true);
        ui->pb_clockin_Notes->setPalette(pal);
        ui->pb_clockin_Notes->update();
        QPalette pal1 = ui->pb_clockout_Notes->palette();
        pal1.setColor(QPalette::Button, QColor(Qt::white));
        ui->pb_clockout_Notes->setAutoFillBackground(true);
        ui->pb_clockout_Notes->setPalette(pal1);
        ui->pb_clockout_Notes->update();
        //
        ui->listWidget_2->addItem("Clocked In: ");
        sql->ClockIn(ui->cmb_name_Notes->currentText());
        Clocked_In = true;

    }
}

void MainWindow::on_pb_clockout_Notes_clicked(bool checked)
{
    if(checked){

    } else {
        QPalette pal = ui->pb_clockin_Notes->palette();
        pal.setColor(QPalette::Button, QColor(Qt::white));
        ui->pb_clockin_Notes->setAutoFillBackground(true);
        ui->pb_clockin_Notes->setPalette(pal);
        ui->pb_clockin_Notes->update();
        QPalette pal1 = ui->pb_clockout_Notes->palette();
        pal1.setColor(QPalette::Button, QColor(Qt::red));
        ui->pb_clockout_Notes->setAutoFillBackground(true);
        ui->pb_clockout_Notes->setPalette(pal1);
        ui->pb_clockout_Notes->update();
        //
        ui->listWidget_2->addItem("Clocked out: ");
        sql->ClockOut(ui->cmb_name_Notes->currentText());
        Clocked_In = false;
    }
}

void MainWindow::on_pb_submit_Notes_clicked()
{
    sql->AddNote(ui->listWidget_2, ui->cmb_name_Notes->currentText(), ui->te_notes_Main->toPlainText());
    ui->te_notes_Main->setText("");
}

>>>>>>> 518fa2a255a233a3931f035f64372590ca09ee7d
