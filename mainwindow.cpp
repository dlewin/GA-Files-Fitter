#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   QString sPath = "c:/";
   dirmodel = new QFileSystemModel (this);
   dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);       // Filter to display Folders only
   dirmodel->setRootPath(sPath);
   ui->DirsView->setModel(dirmodel);

   filemodel = new QFileSystemModel(this);
   filemodel->setFilter(QDir::NoDotAndDotDot | QDir::Files);       // Filter to display Folders only
   filemodel->setRootPath(sPath);

   ui->FilesView->setModel(filemodel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_DirsView_clicked(const QModelIndex &index)
{
    QString sPath = dirmodel->fileInfo(index).absoluteFilePath();
    ui->FilesView->setRootIndex(filemodel->setRootPath(sPath));
}

