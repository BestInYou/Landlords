#include "gamepanel.h"
#include "ui_gamepanel.h"

GamePanel::GamePanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GamePanel)
{
    ui->setupUi(this);

    ui->btnGroup->initButton();
    ui->btnGroup->selectPanel(ButtonGroup::Start);
}

GamePanel::~GamePanel()
{
    delete ui;
}

