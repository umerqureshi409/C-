#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>

class QLineEdit;

class Calculator : public QWidget {
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);

private slots:
    void onDigitPressed();
    void onOperatorPressed();
    void onEqualPressed();
    void onClearPressed();

private:
    QLineEdit *display;
    double leftOperand;
    QString pendingOperator;
    bool waitingForOperand;
};

#endif // CALCULATOR_H
