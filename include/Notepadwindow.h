#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QEvent>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QPrintDialog>
#include <QIcon>

#include "DocumentState.h"


namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionClose_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

private:
    Ui::MainWindow *ui;

    QString curFile = QString();

    DocumentState documentState;
};
#endif // MAINWINDOW_H
