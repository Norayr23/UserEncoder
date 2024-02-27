#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"
#include "UserCoordinator.h"
#include "Validator.h"
#include <QLabel>
#include <QString>
#include "submission.h"
#include "account.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    auto userName  = ui->lineEdit_UserName->text().toStdString();
    removeSpaces(userName);
    if (userName.empty()) {
         QMessageBox::warning(this, "Warning", "Please input your user name");
        return;
    }
    auto password = ui->lineEdit_Password->text().toStdString();
    removeSpaces(password);
    if (password.empty()) {
        QMessageBox::warning(this, "Warning", "Please input your password");
        return;
    }
    auto user = m_us.getUser(userName, password);
    if (!user) {
         QMessageBox::warning(this, "Warning", "Wrong user name or password");
        return;
    }
    auto ac = new Account(this, *user);
    ac->setAttribute(Qt::WA_DeleteOnClose);  // Set to delete the widget when closed
    connect(ac, &QDialog::finished, ac, &QObject::deleteLater);
    ac->show();
}

void MainWindow::on_pushButton_register_clicked()
{
    auto sw = new Submission(this, &m_us);
    sw->setAttribute(Qt::WA_DeleteOnClose);  // Set to delete the widget when closed
    connect(sw, &QDialog::finished, sw, &QObject::deleteLater);
    sw->show();
}

