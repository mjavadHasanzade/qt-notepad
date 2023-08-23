#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(save()));
    connect(ui->actionSave_as,&QAction::triggered,this,&MainWindow::saveAs);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(currentFile);

}


void MainWindow::on_actionOpen_triggered()
{
    QString filename=QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(filename);
    currentFile=filename;
    if(!file.open(QIODevice::ReadOnly| QFile::Text)){
        QMessageBox::warning(this,"Warning","Can not open the file "+filename);
        return;
    }

    setWindowTitle(filename);

    QTextStream in(&file);
    QString text=in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::save()
{
    QString filename;

    if(currentFile.isEmpty()){
        filename=QFileDialog::getSaveFileName(this,"Save the File","","Text files (*.txt)");
        currentFile=filename;
    }else{
        filename=currentFile;
    }

    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly| QFile::Text)){
        QMessageBox::warning(this,"Warning","Can not Save the file "+filename);
        return;
    }

    setWindowTitle(filename);
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    out<<text;
    file.close();
}


void MainWindow::saveAs()
{
    QString filename;

    if(currentFile.isEmpty()){
        filename=QFileDialog::getSaveFileName(this,"Save the File");
        currentFile=filename;
    }else{
        filename=currentFile;
    }

    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly| QFile::Text)){
        QMessageBox::warning(this,"Warning","Can not Save the file "+filename);
        return;
    }

    setWindowTitle(filename);
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    out<<text;
    file.close();
}

