#include "include/Notepadwindow.h"
#include "ui_Notepadwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

    QIcon mainWindowIcon;
    mainWindowIcon.addFile(QString::fromUtf8(":/icons/notepad.ico"), QSize(), QIcon::Normal, QIcon::Off);
    this->setWindowTitle("Notepad");
    this->setWindowIcon(mainWindowIcon);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClose_triggered()
{
    this->documentState.setSavedFlag(false);
    this->documentState.setSavedFilename(QString());

    curFile.clear();
}


void MainWindow::on_actionNew_triggered()
{
    this->documentState.setSavedFlag(false);
    this->documentState.setSavedFilename(QString());

    this->setWindowTitle("New File");
    curFile.clear();
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(filename);

    curFile = filename;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"Warning","Error while opening file. " + file.errorString());
        return;
    }

    this->documentState.setSavedFlag(true);
    this->documentState.setSavedFilename(filename);

    this->setWindowTitle(filename);
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());

    file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,"Save the file as");
    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"Warning","Error while saving file. " + file.errorString());
        return;
    }

    this->documentState.setSavedFlag(true);
    this->documentState.setSavedFilename(filename);

    this->setWindowTitle(filename);

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();

    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    if (documentState.getSavedFlag())
    {

        QFile file(this->documentState.getSavedFilename());

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::OpenModeFlag::Truncate))
        {
            QMessageBox::warning(this,"Warning","Error while saving file. " + file.errorString());
            return;
        }

        QTextStream out(&file);
        out << ui->textEdit->toPlainText();

        file.close();
    }
    else
    {
        MainWindow::on_actionSave_As_triggered();
    }
}
