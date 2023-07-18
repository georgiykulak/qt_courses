#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->btnReject, &QPushButton::clicked, this, &Dialog::onRejectBtnClicked);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btnAccept_clicked()
{
    QMessageBox::information(this, "Name", "Hello " + ui->txtName->text());
    std::cout << "Accepted text '" << ui->txtName->text().toStdString() << "', now leaving\n";
    this->accept();
}

void Dialog::onRejectBtnClicked()
{
    auto text = ui->txtName->text();

    std::cout << "Rejected!";

    if (!text.isEmpty())
        std::cout << " Entered text was: '" << text.toStdString() << "'.";

    std::cout << "\n";
}
