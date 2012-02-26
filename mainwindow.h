#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_DirsView_clicked(const QModelIndex &index);


private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirmodel ;
    QFileSystemModel *filemodel ;
};

#endif // MAINWINDOW_H
