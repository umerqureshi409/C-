#include "Calculator.h"
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent), leftOperand(0.0), waitingForOperand(true) {
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    mainLayout->addWidget(display, 0, 0, 1, 4);

    const QString digitButtons[10] = {
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
    };

    for (int i = 0; i < 10; ++i) {
        QPushButton *button = new QPushButton(digitButtons[i]);
        connect(button, &QPushButton::clicked, this, &Calculator::onDigitPressed);
        mainLayout->addWidget(button, 1 + i / 3, i % 3);
    }

    const QString operatorButtons[5] = {
        "+", "-", "*", "/", "%"
    };

    for (int i = 0; i < 5; ++i) {
        QPushButton *button = new QPushButton(operatorButtons[i]);
        connect(button, &QPushButton::clicked, this, &Calculator::onOperatorPressed);
        mainLayout->addWidget(button, 1 + i, 3);
    }

    QPushButton *equalButton = new QPushButton("=");
    connect(equalButton, &QPushButton::clicked, this, &Calculator::onEqualPressed);
    mainLayout->addWidget(equalButton, 4, 2, 1, 2);

    QPushButton *clearButton = new QPushButton("C");
    connect(clearButton, &QPushButton::clicked, this, &Calculator::onClearPressed);
    mainLayout->addWidget(clearButton, 4, 0, 1, 2);

    setLayout(mainLayout);
    setWindowTitle("Calculator");
}

void Calculator::onDigitPressed() {
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    int digitValue = clickedButton->text().toInt();

    if (display->text() == "0" && digitValue == 0.0)
        return;

    if (waitingForOperand) {
        display->clear();
        waitingForOperand = false;
    }

    display->setText(display->text() + QString::number(digitValue));
}

void Calculator::onOperatorPressed() {
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    if (!pendingOperator.isEmpty()) {
        if (!calculate(operand)) {
            clear();
            display->setText("####");
            return;
        }
        display->setText(QString::number(leftOperand));
    } else {
        leftOperand = operand;
    }

    pendingOperator = clickedOperator;
    waitingForOperand = true;
}

void Calculator::onEqualPressed() {
    double operand = display->text().toDouble();

    if (!pendingOperator.isEmpty()) {
        if (!calculate(operand)) {
            clear();
            display->setText("####");
            return;
        }
        pendingOperator.clear();
    }

    display->setText(QString::number(leftOperand));
    waitingForOperand = true;
}

void Calculator::onClearPressed() {
    clear();
    display->setText("0");
    waitingForOperand = true;
}

void Calculator::clear() {
    leftOperand = 0.0;
    pendingOperator.clear();
}

bool Calculator::calculate(double rightOperand) {
    if (pendingOperator == "+") {
        leftOperand += rightOperand;
    } else if (pendingOperator == "-") {
        leftOperand -= rightOperand;
    } else if (pendingOperator == "*") {
        leftOperand *= rightOperand;
    } else if (pendingOperator == "/") {
        if (rightOperand == 0.0)
            return false;
        leftOperand /= rightOperand;
    } else if (pendingOperator == "%") {
        if (rightOperand == 0.0)
            return false;
        leftOperand = static_cast<int>(leftOperand) % static_cast<int>(rightOperand);
    }
    return true;
}
