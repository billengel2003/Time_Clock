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
    ui->lineEdit_3->setText("127.0.0.1");
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_2->setInputMethodHints(Qt::ImhHiddenText|
                                        Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);
    this->setWindowTitle("Time Clock");

    ui->comboBox->addItem("");
}

MainWindow::~MainWindow()
{
    delete sql;
    delete ui;
}
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
{
    if(checked){

    } else{
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

    }
}

void MainWindow::on_pushButton_3_clicked()
{
    sql->AddNote(ui->listWidget_2, ui->comboBox->currentText(), ui->te_notes_Main->toPlainText());
    ui->te_notes_Main->setText("");
}

void MainWindow::on_pushButton_4_clicked()
{
    if(sql->Connect(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text())){
        Connected = true;
        ui->stackedWidget->setCurrentIndex(0);
        sql->LoadClientList(ui->comboBox);
        sql->LoadClientList(ui->cmb_name_Edit);
        ui->comboBox->setCurrentIndex(0);
    } else{
        qDebug()<<"Did not Connect to SQL";
    }
}

void MainWindow::on_actionEdit_Client_triggered()
{
    if(Connected){
        ui->stackedWidget->setCurrentIndex(1);
    }
}



void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->listWidget->clear();
    if(Connected){
        sql->LoadClientInfo(ui->listWidget, arg1);
        sql->LoadNotes(ui->listWidget_2, arg1);
        if(Clocked_In){
            this->on_pushButton_clicked();
        }

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
    }
}


void MainWindow::on_listWidget_2_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(Connected){
        ui->te_notes_Main->setText(current->text().split('\n')[1]);
    }
}
