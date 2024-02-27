#ifndef SUBMISSION_H
#define SUBMISSION_H

#include <QDialog>
#include "UserCoordinator.h"

namespace Ui {
class Submission;
}

class Submission : public QDialog
{
    Q_OBJECT

public:
    explicit Submission(QWidget *parent = nullptr, UserCoordinator* us = nullptr);
    ~Submission();

private slots:
    void on_checkBox_male_stateChanged(int arg1);

    void on_checkBox_female_stateChanged(int arg1);

    void on_pushButton_submit_clicked();

private:
    Ui::Submission *ui;
    UserCoordinator* m_us;
};

#endif // SUBMISSION_H
