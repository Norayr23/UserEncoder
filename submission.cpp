#include "submission.h"
#include "ui_submission.h"
#include "Validator.h"
#include <string>
#include <QMessageBox>

Submission::Submission(QWidget *parent, UserCoordinator* us)
    : QDialog(parent)
    , ui(new Ui::Submission), m_us(us)
{
    ui->setupUi(this);
}

Submission::~Submission()
{
    delete ui;
}

void Submission::on_checkBox_male_stateChanged(int arg1)
{
    if (ui->checkBox_male->isChecked()) {
        ui->checkBox_female->setChecked(false);
    }
}

void Submission::on_checkBox_female_stateChanged(int arg1)
{
    if (ui->checkBox_female->isChecked()) {
        ui->checkBox_male->setChecked(false);
    }
}


void Submission::on_pushButton_submit_clicked()
{
    auto name = ui->lineEdit_name->text().toStdString();
    if (name.empty()) {
        QMessageBox::warning(this, "Warning", "Please enter your name");
        return;
    }
    if (!Validator::isNameValid(name)) {
         QMessageBox::warning(this, "Warning", "Please enter a name with a length between 2 and 50 characters, comprising only alphabetical characters.");
        return;
    }
    auto lastName = ui->lineEdit_lastName->text().toStdString();
    if (lastName.empty()) {
        QMessageBox::warning(this, "Warning", "Please enter your last name");
        return;
    }
    if (!Validator::isLastNameValid(lastName)) {
        QMessageBox::warning(this, "Warning", "Please enter a last name with a length between 2 and 50 characters, comprising only alphabetical characters.");
        return;
    }
    auto userName = ui->lineEdit_userName->text().toStdString();
    if (userName.empty()) {
        QMessageBox::warning(this, "Warning", "Please enter your user name");
        return;
    }
    if (!Validator::isUserNameValid(userName)) {
        QMessageBox::warning(this, "Warning", "Please enter a user name with a length between 1 and 50 characters.");
        return;
    }
    if (m_us->isUserExist(userName)) {
        QMessageBox::warning(this, "Warning", "Oops! It seems like this username is already taken. Please choose another one.");
        return;
    }
    auto password = ui->lineEdit_password->text().toStdString();
    if (password.empty()) {
        QMessageBox::warning(this, "Warning", "Please enter your passord");
        return;
    }
    if (!Validator::isPasswordValid(password)) {
        QMessageBox::warning(this, "Warning", "Password must be between 8 and 100 characters, and include at least one lowercase letter, one uppercase letter, one digit, and one special character.");
        return;
    }
    if (!ui->checkBox_male->isChecked() && !ui->checkBox_female->isChecked()) {
          QMessageBox::warning(this, "Warning", "Please check your gender");
        return;
    }
    User::Gender gender = ui->checkBox_male->isChecked() ? User::Gender::Male : User::Gender::Female;
    size_t age = ui->spinBox_age->value();
    if (!Validator::isAgeValid(age)) {
        QMessageBox::warning(this, "Warning", "Invalid age. Please enter a non-negative value below 150.");
    }
    m_us->addUser(User(name, lastName, userName, password, gender, age));
    QMessageBox::information(this, "Success", "Your submission was successful. Thank you!");
    close();
}

