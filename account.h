#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>
#include "User.h"

namespace Ui {
class Account;
}

class Account : public QDialog
{
    Q_OBJECT

public:
    explicit Account(QWidget *parent = nullptr, User u = User());
    ~Account();

private:
    Ui::Account *ui;
    User user;
};

#endif // ACCOUNT_H
