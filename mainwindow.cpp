#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>

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

#include <QMessageBox>

void MainWindow::on_pushButton_serialize_clicked()
{
    QString name = ui->lineEdit_name->text();
    int age = ui->spinBox_age->value();
    QString birthdayDate = ui->dateEdit->date().toString("yyyy-MM-dd");
    user_file_manager.setName(name.toStdString());
    user_file_manager.setAge(age);
    user_file_manager.setBirthdayDate(birthdayDate.toStdString());
    user_file_manager.serialize();
    if (user_file_manager.isSerialized()) {
        QMessageBox::information(this, "Success", "User data serialized successfully.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to serialize user data.");
    }
}


void MainWindow::on_pushButton_deserialize_clicked()
{
    // Deserialize user data
    if (user_file_manager.deserialize()) {
        // Update UI elements with deserialized user data
        ui->lineEdit_name->setText(QString::fromStdString(user_file_manager.getName()));
        ui->spinBox_age->setValue(user_file_manager.getAge());
        ui->dateEdit->setDate(QDate::fromString(QString::fromStdString(user_file_manager.getBirthdayDate()), "yyyy-MM-dd"));

        QMessageBox::information(this, "Success", "User data deserialized successfully.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to deserialize user data.");
    }
}

