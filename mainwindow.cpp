#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Connected = false;
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
void MainWindow::on_pushButton_clicked(bool checked)
{
    if(checked){

    } else{
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
        ui->textEdit->setText("OWED");
        ui->textEdit->setText("HISTORY");

    }
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
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->listWidget_2->addItem("NOTE");
    //ui->label_2->setText(Master_recordX[0]->NoteDateAt(0));
    ui->textEdit->setText("");
}

void MainWindow::on_pushButton_4_clicked()
{
    if(sql->Connect(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text())){
        Connected = true;
        ui->stackedWidget->setCurrentIndex(0);
        sql->LoadClientList(ui->comboBox);
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
        sql->LoadListWidget(ui->listWidget, arg1);
    }
}
