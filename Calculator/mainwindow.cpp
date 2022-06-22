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


long long MainWindow::fact(int N)
{
    if(N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * fact(N - 1);
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


bool MainWindow::tryParseToInt()
{
    bool ok;
    expString.toInt(&ok);
    return ok;
}


bool MainWindow::tryParseToDouble()
{
    bool ok;
    expString.toDouble(&ok);
    return ok;
}


void MainWindow::readInput()
{
    expString = ui->expLine->text();
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


void MainWindow::on_facButt_released()
{
    readInput();
    if (tryParseToInt())
    {
        int num = expString.toInt();
        if (num <= 20)
        {
            ui->expLine->setText(QString::number(fact(num)));
        }
        else
        {
            QMessageBox::critical(this, "Ошибка", "Слишком большое число");
        }
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Невозможно вычислить");
    }
    ui->facFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_perButt_released()
{
    readInput();
    if (tryParseToDouble())
    {
        double num = expString.toDouble();
        num /= 100;
        ui->expLine->setText(QString::number(num));
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Невозможно вычислить");
    }
    ui->perFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_degreeButt_released()
{
    readInput();
    if (tryParseToDouble())
    {
        double num = expString.toDouble();
        if (num < 1.7e+154 and num > -1.7e+154 )
        {
            num = qPow(num, 2);
            ui->expLine->setText(QString::number(num));
        }
        else
        {
            QMessageBox::critical(this, "Ошибка", "Слишком большой модуль числа");
        }
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Невозможно вычислить");
    }
    ui->degreeFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_sqrtButt_released()
{
    readInput();
    if (tryParseToDouble())
    {
        double num = expString.toDouble();
        if (num < 1.7e+308 and num > 0)
        {
            num = qPow(num, 0.5);
            ui->expLine->setText(QString::number(num));
        }
        else
        {
            QMessageBox::critical(this, "Ошибка", "Слишком большое или отрицательное число");
        }
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Невозможно вычислить");
    }
    ui->sqrtFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_logButt_released()
{
    readInput();
    if (tryParseToDouble())
    {
        double num = expString.toDouble();
        if (num > 0)
        {
            num = qLn(num);
            ui->expLine->setText(QString::number(num));
        }
        else
        {
            QMessageBox::critical(this, "Ошибка", "Невозможно вычислить логарифм числа <0");
        }
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Невозможно вычислить");
    }
    ui->logFrame->setStyleSheet(defaultFrameStyle);
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
    readInput();
    if (tryParseToDouble())
    {
        double num = expString.toDouble();
        num = qSin(num);
       ui->expLine->setText(QString::number(num));
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Невозможно вычислить");
    }
    ui->sinFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_cosButt_released()
{
    readInput();
    if (tryParseToDouble())
    {
        double num = expString.toDouble();
        num = qCos(num);
       ui->expLine->setText(QString::number(num));
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Невозможно вычислить");
    }
    ui->cosFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_tanButt_released()
{
    readInput();
    if (tryParseToDouble())
    {
        double num = expString.toDouble();
        num = qTan(num);
       ui->expLine->setText(QString::number(num));
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Невозможно вычислить");
    }
    ui->tanFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_cotButt_released()
{
    readInput();
    if (tryParseToDouble())
    {
        double num = expString.toDouble();
        if (num != 0)
        {
            num = 1 / qTan(num);
            ui->expLine->setText(QString::number(num));
        }
        else
        {
            QMessageBox::critical(this, "Ошибка", "Невозможно вычислить котангенс числа");
        }
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Невозможно вычислить");
    }
    ui->cotFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_plusButt_released()
{
    if (!isFirstSymbol() and symbolCanPePlaced())
    {
        ui->expLine->insert("+");
    }
    ui->plusFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_minusButt_released()
{
    if (isFirstSymbol())
    {
        ui->expLine->insert("-");
    }
    else
    {
        if (symbolCanPePlaced())
        {
            ui->expLine->insert("-");
        }
    }
    ui->minusFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_multButt_released()
{
    if (!isFirstSymbol() and symbolCanPePlaced())
    {
        ui->expLine->insert("*");
    }
    ui->multFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_divButt_released()
{
    if (!isFirstSymbol() and symbolCanPePlaced())
    {
        ui->expLine->insert("/");
    }
    ui->divFrame->setStyleSheet(defaultFrameStyle);
}

QList<QString> MainWindow::makeRPN()
{
    if (expString.at(0) == '-')
    {
        expString = "0" + expString;
    }
    int lenght = expString.length();
    QList<QString> output;
    QStack<QChar> operators_stack;
    QString tempValue = "";
    for (int i = 0; i < lenght; ++i)
    {
        if((expString.at(i) >= '0' and
                expString.at(i) <= '9') or
                expString.at(i) == '.')
        {
            tempValue += expString.at(i);
        }
        else if (isOperator(expString.at(i)))
        {
            if (tempValue != "")
            {
                output.append(tempValue);
                tempValue = "";
            }
            if (operators_stack.count() == 0)
            {
                operators_stack.push(expString.at(i));
            }
            else
            {
                if (getPriority(operators_stack.top()) >= getPriority(expString.at(i)))
                {
                    output.append(operators_stack.pop());
                    operators_stack.push(expString.at(i));
                }
                else
                {
                    operators_stack.push(expString.at(i));
                }
            }
        }
    }
    if (tempValue != "")
    {
        output.append(tempValue);
        tempValue = "";
    }
    if (operators_stack.count() != 0)
    {
        while (operators_stack.count() != 0)
        {
        output.append(operators_stack.pop());
        }
    }
    return output;
}

double MainWindow::simpleCalc(double a, double b, QChar op)
{
    switch (op.unicode()) {
    case u'+':
        return a + b;
    case u'-':
        return a - b;
    case u'*':
        return a * b;
    case u'/':
        return a / b;
    default:
        return 0;
        break;
    }
}

double MainWindow::calculateRPN(QList<QString> RPNexp)
{
    QStack<double> solutionStack;
    int expLenght = RPNexp.length();
    for (int i = 0; i < expLenght; ++i)
    {
        if (!isOperator(RPNexp[i].back()))
        {
            solutionStack.push(RPNexp[i].toDouble());
        }
        else
        {
            double res = simpleCalc(solutionStack.pop(),
                                    solutionStack.pop(), RPNexp[i].back());
            solutionStack.push(res);
        }
    }
    return solutionStack.pop();
}

void MainWindow::on_equalButt_released()
{
    readInput();
    int lenght = expString.length();
    ui->equalFrame->setStyleSheet(defaultFrameStyle);
    if (lenght == 0 or !symbolCanPePlaced())
    {
        QMessageBox::critical(this, "Ошибка", "Сначала введите выражение");
        return;
    }
    for (int i = 0; i < lenght - 1; ++i)
    {
        if (expString.at(i) == '/' and expString.at(i + 1) == '0')
        {
            QMessageBox::critical(this, "Ошибка", "Деление на 0 недопустимо");
            return;
        }
    }

    QList<QString> output = makeRPN();
    QString answer = QString::number(calculateRPN(output));

    if (answer == "nan" or answer == "inf")
    {
        QMessageBox::critical(this, "Ошибка", "Невозможно вычислить");
        return;
    }
    for (int i = 0; i < answer.length(); ++i)
    {
        if (answer.at(i) == 'e')
        {
            QMessageBox::critical(this, "Ошибка", "Слишком большие числа");
            return;
        }
    }
    ui->expLine->setText(answer);
}

bool MainWindow::isOperator(QChar symbol)
{
    if (symbol == '+' or symbol == '-' or
            symbol == '*' or symbol == '/')
        return true;
    else
        return false;
}

int MainWindow::getPriority(QChar op)
{
    switch (op.unicode()) {
    case u'+':
        return 0;
    case u'-':
        return 0;
    case u'*':
        return 1;
    case u'/':
        return 1;
    default:
        return 2;
        break;
    }
}

void MainWindow::on_reverseButt_released()
{
    readInput();
    if (tryParseToDouble())
    {
        double num = expString.toDouble();
        num = -num;
        ui->expLine->setText(QString::number(num));
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Невозможно вычислить");
        return;
    }
    ui->reverseFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_clearAllButt_released()
{
    ui->expLine->clear();
    ui->clearAllFrame->setStyleSheet(defaultFrameStyle);
}


void MainWindow::on_clearButt_released()
{
    readInput();
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

