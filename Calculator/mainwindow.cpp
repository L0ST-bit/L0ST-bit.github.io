#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_facButt_released()
{
    ui->facFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_perButt_released()
{
    ui->perFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_degreeButt_released()
{
    ui->degreeFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_sqrtButt_released()
{
    ui->sqrtFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_logButt_released()
{
    ui->logFrame->setStyleSheet(defaultFrameStyle);
}

bool MainWindow::isFirstSymbol()
{
    readInput();
    if (expString.length() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool MainWindow::symbolCanPePlaced()
{
    readInput();
    QChar latestCharacter = expString.at(expString.length() - 1);
    switch (latestCharacter.unicode()) {
    case u'+':
        return false;
    case u'-':
        return false;
    case u'*':
        return false;
    case u'/':
        return false;
    case u'.':
        return false;
        break;
    default:
        return true;
        break;
    }
}

void MainWindow::on_piButt_released()
{
    if (isFirstSymbol())
    {
        ui->expLine->insert(QString::number(M_PI));
    }
    else
    {
        if (!symbolCanPePlaced())
        {
            ui->expLine->insert(QString::number(M_PI));
        }
    }
    ui->piFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_expButt_released()
{
    if (isFirstSymbol())
    {
        ui->expLine->insert(QString::number(M_E));
    }
    else
    {
        if (!symbolCanPePlaced())
        {
            ui->expLine->insert(QString::number(M_E));
        }
    }
    ui->expFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_sinButt_released()
{
    ui->sinFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_cosButt_released()
{
    ui->cosFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_tanButt_released()
{
    ui->tanFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_cotButt_released()
{
    ui->cotFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_plusButt_released()
{
    ui->expLine->insert("+");
    ui->plusFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_minusButt_released()
{
    ui->expLine->insert("-");
    ui->minusFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_multButt_released()
{
    ui->expLine->insert("*");
    ui->multFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_divButt_released()
{
    ui->expLine->insert("/");
    ui->divFrame->setStyleSheet(defaultFrameStyle);
}





void MainWindow::on_equalButt_released()
{
    ui->equalFrame->setStyleSheet(defaultFrameStyle);
}




void MainWindow::on_reverseButt_released()
{
    ui->reverseFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_clearAllButt_released()
{
    ui->expLine->clear();
    ui->clearAllFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_clearButt_released()
{
    ui->expLine->backspace();
    ui->clearFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_numButt_1_released()
{
    ui->expLine->insert("1");
    ui->numFrame_1->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_numButt_2_released()
{
    ui->expLine->insert("2");
    ui->numFrame_2->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_numButt_3_released()
{
    ui->expLine->insert("3");
    ui->numFrame_3->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_numButt_4_released()
{
    ui->expLine->insert("4");
    ui->numFrame_4->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_numButt_5_released()
{
    ui->expLine->insert("5");
    ui->numFrame_5->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_numButt_6_released()
{
    ui->expLine->insert("6");
    ui->numFrame_6->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_numButt_7_released()
{
    ui->expLine->insert("7");
    ui->numFrame_7->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_numButt_8_released()
{
    ui->expLine->insert("8");
    ui->numFrame_8->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_numButt_9_released()
{
    ui->expLine->insert("9");
    ui->numFrame_9->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_numButt_0_released()
{
    ui->expLine->insert("0");
    ui->numFrame_0->setStyleSheet(defaultFrameStyle);
}

bool MainWindow::valueHasDot(QString lastValue)
{
    for (int i = 0; i < lastValue.length(); ++i)
    {
        if (lastValue.at(i) == '.')
        {
            return true;
        }
    }
    return false;
}

QString MainWindow::getLastValue()
{
    int lenght = expString.length();
    if (lenght == 0)
    {
        return "";
    }
    int indexOfLastSymbol = 0;
    for (int i = 0; i < lenght; ++i)
    {
        if (expString.at(i) == '+' or
            expString.at(i) == '-' or
            expString.at(i) == '*' or
            expString.at(i) == '/')
        {
            indexOfLastSymbol = i;
        }
    }
    QString lastValue = "";
    for (int i = indexOfLastSymbol; i < lenght; ++i)
    {
        lastValue += (expString.at(i));
    }
    return lastValue;
}

void MainWindow::on_dotButt_released()
{
    readInput();
    if (!isFirstSymbol() and symbolCanPePlaced() and !valueHasDot(getLastValue()))
    {
        ui->expLine->insert(".");
    }
    ui->dotFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_facButt_pressed()
{
    ui->facFrame->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_perButt_pressed()
{
    ui->perFrame->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_degreeButt_pressed()
{
    ui->degreeFrame->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_sqrtButt_pressed()
{
    ui->sqrtFrame->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_logButt_pressed()
{
    ui->logFrame->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_piButt_pressed()
{

    ui->piFrame->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_expButt_pressed()
{
    ui->expFrame->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_sinButt_pressed()
{
    ui->sinFrame->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_cosButt_pressed()
{
    ui->cosFrame->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_tanButt_pressed()
{
    ui->tanFrame->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_cotButt_pressed()
{
    ui->cotFrame->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_plusButt_pressed()
{
    ui->plusFrame->setStyleSheet(commandsButtonFrameFocusStyle);
}


void MainWindow::on_minusButt_pressed()
{
    ui->minusFrame->setStyleSheet(commandsButtonFrameFocusStyle);
}


void MainWindow::on_multButt_pressed()
{
    ui->multFrame->setStyleSheet(commandsButtonFrameFocusStyle);
}


void MainWindow::on_divButt_pressed()
{
    ui->divFrame->setStyleSheet(commandsButtonFrameFocusStyle);
}


void MainWindow::on_equalButt_pressed()
{
    ui->equalFrame->setStyleSheet(equalButtonFrameFocusStyle);
}


void MainWindow::on_reverseButt_pressed()
{
    ui->reverseFrame->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_clearAllButt_pressed()
{
    ui->clearAllFrame->setStyleSheet(clearButtonFrameFocusStyle);
}


void MainWindow::on_clearButt_pressed()
{

    ui->clearFrame->setStyleSheet(clearButtonFrameFocusStyle);
}


void MainWindow::on_numButt_1_pressed()
{
    ui->numFrame_1->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_numButt_2_pressed()
{
    ui->numFrame_2->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_numButt_3_pressed()
{
    ui->numFrame_3->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_numButt_4_pressed()
{
    ui->numFrame_4->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_numButt_5_pressed()
{
    ui->numFrame_5->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_numButt_6_pressed()
{
    ui->numFrame_6->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_numButt_7_pressed()
{
    ui->numFrame_7->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_numButt_8_pressed()
{
    ui->numFrame_8->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_numButt_9_pressed()
{
    ui->numFrame_9->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_numButt_0_pressed()
{
    ui->numFrame_0->setStyleSheet(enginButtonFrameFocusStyle);
}


void MainWindow::on_dotButt_pressed()
{
    ui->dotFrame->setStyleSheet(enginButtonFrameFocusStyle);
}

