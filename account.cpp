#include "account.h"
#include "ui_account.h"

Account::Account(QWidget *parent, User u)
    : QDialog(parent)
    , ui(new Ui::Account), user(u)
{
    ui->setupUi(this);
    ui->label_name->setText(QString::fromStdString(user.getName()));
    ui->label_userName->setText(QString::fromStdString(user.getUserName()));
    if (user.getGender() == User::Gender::Male) {
        ui->label_gender->setText("Male");
    }
    else {
        ui->label_gender->setText("Female");
    }
    ui->label_age->setText(QString::fromStdString(std::to_string(user.getAge())));
}

Account::~Account()
{
    delete ui;
}
