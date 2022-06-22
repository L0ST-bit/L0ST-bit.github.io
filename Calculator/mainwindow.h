#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMath>
#include <QtDebug>
#include <QMessageBox>
#include <QStack>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    QString getLastValue();

    bool valueHasDot(QString lastValue);

    long long fact(int N);

    bool symbolCanPePlaced();

    void readInput();

    bool isFirstSymbol();

    void on_facButt_pressed();

    void on_facButt_released();

    void on_perButt_pressed();

    void on_perButt_released();

    void on_degreeButt_released();

    void on_degreeButt_pressed();

    void on_sqrtButt_pressed();

    void on_logButt_pressed();

    void on_piButt_pressed();

    void on_expButt_pressed();

    void on_sinButt_pressed();

    void on_cosButt_pressed();

    void on_tanButt_pressed();

    void on_cotButt_pressed();

    void on_sqrtButt_released();

    void on_logButt_released();

    void on_piButt_released();

    void on_expButt_released();

    void on_sinButt_released();

    void on_cosButt_released();

    void on_tanButt_released();

    void on_cotButt_released();

    void on_clearButt_pressed();

    void on_plusButt_pressed();

    void on_minusButt_pressed();

    void on_multButt_pressed();

    void on_divButt_pressed();

    void on_equalButt_pressed();

    void on_clearButt_released();

    void on_plusButt_released();

    void on_minusButt_released();

    void on_multButt_released();

    void on_divButt_released();

    void on_equalButt_released();

    void on_reverseButt_pressed();

    void on_reverseButt_released();

    void on_clearAllButt_pressed();

    void on_clearAllButt_released();

    void on_numButt_1_released();

    void on_numButt_1_pressed();

    void on_numButt_2_pressed();

    void on_numButt_3_pressed();

    void on_numButt_4_pressed();

    void on_numButt_5_pressed();

    void on_numButt_6_pressed();

    void on_numButt_7_pressed();

    void on_numButt_8_pressed();

    void on_numButt_9_pressed();

    void on_numButt_0_pressed();

    void on_dotButt_pressed();

    void on_numButt_2_released();

    void on_numButt_3_released();

    void on_numButt_4_released();

    void on_numButt_5_released();

    void on_numButt_6_released();

    void on_numButt_7_released();

    void on_numButt_8_released();

    void on_numButt_9_released();

    void on_numButt_0_released();

    void on_dotButt_released();

private:
    Ui::MainWindow *ui;

    QString equalButtonFrameFocusStyle = "QFrame{"
            "border-style: solid;"
            "border-width: 5px;"
            "border-color: rgb(147,190,251);"
            "border-radius: 6px;"
            "background-color: rgb(147,190,251);"
            "}";

    QString clearButtonFrameFocusStyle = "QFrame{"
            "border-style: solid;"
            "border-width: 5px;"
            "border-color: rgb(240, 168, 175);"
            "border-radius: 6px;"
            "background-color: rgb(240, 168, 175);"
            "}";

    QString commandsButtonFrameFocusStyle = "QFrame{"
            "border-style: solid;"
            "border-width: 5px;"
            "border-color: rgb(157, 204, 182);"
            "border-radius: 6px;"
            "background-color: rgb(157, 204, 182);"
            "}";

    QString enginButtonFrameFocusStyle = "QFrame{"
            "border-style: solid;"
            "border-width: 5px;"
            "border-color: rgb(181,185,189);"
            "border-radius: 6px;"
            "background-color: rgb(181,185,189);"
            "}";

    QString defaultFrameStyle = "QFrame{"
            "border: none;"
            "background-color: white;"
            "}";

    QString exitButtonFrameFocusStyle = "QFrame{"
            "border-style: solid;"
            "border-width: 5px;"
            "border-color: rgb(192,196,200);"
            "border-radius: 6px;"
            "background-color: rgb(192,196,200);"
            "}";

};
#endif // MAINWINDOW_H
