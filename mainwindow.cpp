#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("大数四则运算计算器");
    setFixedSize(500, 400);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // 第一个数字输入
    QHBoxLayout *num1Layout = new QHBoxLayout();
    QLabel *num1Label = new QLabel("第一个大数：", this);
    num1Edit = new QLineEdit(this);
    num1Layout->addWidget(num1Label);
    num1Layout->addWidget(num1Edit);
    mainLayout->addLayout(num1Layout);

    // 第二个数字输入
    QHBoxLayout *num2Layout = new QHBoxLayout();
    QLabel *num2Label = new QLabel("第二个大数：", this);
    num2Edit = new QLineEdit(this);
    num2Layout->addWidget(num2Label);
    num2Layout->addWidget(num2Edit);
    mainLayout->addLayout(num2Layout);

    // 小数位数输入
    QHBoxLayout *decimalLayout = new QHBoxLayout();
    QLabel *decimalLabel = new QLabel("保留小数位数：", this);
    decimalPlacesEdit = new QLineEdit(this);
    decimalPlacesEdit->setValidator(new QIntValidator(0, 20, this));
    decimalLayout->addWidget(decimalLabel);
    decimalLayout->addWidget(decimalPlacesEdit);
    mainLayout->addLayout(decimalLayout);

    // 按钮区域
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *addButton = new QPushButton("加法 (+)", this);
    QPushButton *subButton = new QPushButton("减法 (-)", this);
    QPushButton *mulButton = new QPushButton("乘法 (*)", this);
    QPushButton *divButton = new QPushButton("除法 (/)", this);
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(subButton);
    buttonLayout->addWidget(mulButton);
    buttonLayout->addWidget(divButton);
    mainLayout->addLayout(buttonLayout);

    // 结果显示区域
    QLabel *resultLabel = new QLabel("结果：", this);
    resultEdit = new QTextEdit(this);
    resultEdit->setReadOnly(true);
    mainLayout->addWidget(resultLabel);
    mainLayout->addWidget(resultEdit);

    // 连接按钮信号到槽函数
    connect(addButton, &QPushButton::clicked, this, &MainWindow::performAddition);
    connect(subButton, &QPushButton::clicked, this, &MainWindow::performSubtraction);
    connect(mulButton, &QPushButton::clicked, this, &MainWindow::performMultiplication);
    connect(divButton, &QPushButton::clicked, this, &MainWindow::performDivision);
}

MainWindow::~MainWindow() {}

void MainWindow::performAddition() {
    performOperation("add");
}

void MainWindow::performSubtraction() {
    performOperation("subtract");
}

void MainWindow::performMultiplication() {
    performOperation("multiply");
}

void MainWindow::performDivision() {
    performOperation("divide");
}

void MainWindow::performOperation(const QString &operation) {
    QString num1 = num1Edit->text().trimmed();
    QString num2 = num2Edit->text().trimmed();
    QString decimalStr = decimalPlacesEdit->text().trimmed();
    int decimalPlaces = decimalStr.isEmpty() ? 0 : decimalStr.toInt();

    if (num1.isEmpty() || num2.isEmpty()) {
        QMessageBox::warning(this, "错误", "请输入两个大数！");
        return;
    }

    if ((operation == "divide") && (num2 == "0")) {
        QMessageBox::warning(this, "错误", "除数不能为零！");
        return;
    }

    QString result;

    if (operation == "add") {
        result = addStrings(num1, num2);
    }
    else if (operation == "subtract") {
        result = subStrings(num1, num2);
    }
    else if (operation == "multiply") {
        result = mulStrings(num1, num2);
    }
    else if (operation == "divide") {
        if (decimalStr.isEmpty()) {
            QMessageBox::warning(this, "错误", "请输入保留的小数位数！");
            return;
        }
        result = divStrings(num1, num2, decimalPlaces);
    }

    resultEdit->setText(result);
}

QString MainWindow::addStrings(const QString &num1, const QString &num2) {
    int end1 = num1.size() - 1, end2 = num2.size() - 1;
    QString res;
    int carry = 0;

    while (end1 >= 0 || end2 >= 0) {
        int a = (end1 >= 0) ? (num1[end1].unicode() - '0') : 0;
        int b = (end2 >= 0) ? (num2[end2].unicode() - '0') : 0;

        int sum = a + b + carry;
        carry = sum / 10;
        res.prepend(QChar('0' + sum % 10));

        end1--;
        end2--;
    }

    if (carry > 0) {
        res.prepend(QChar('0' + carry));
    }

    return res;
}

QString MainWindow::subStrings(const QString &num1, const QString &num2) {
    if (compareStrings(num1, num2) == -1) {
        QString result = subStrings(num2, num1);
        return "-" + result;
    }

    int end1 = num1.size() - 1, end2 = num2.size() - 1;
    QString res;
    int borrow = 0;

    while (end1 >= 0) {
        int a = num1[end1].unicode() - '0';
        int b = (end2 >= 0) ? (num2[end2].unicode() - '0') : 0;

        int diff = a - b - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        res.prepend(QChar('0' + diff));
        end1--;
        end2--;
    }

    // 去掉前导零
    int start = 0;
    while (start < res.size() - 1 && res[start] == '0') {
        start++;
    }
    return res.mid(start);
}

QString MainWindow::mulStrings(const QString &num1, const QString &num2) {
    if (num1 == "0" || num2 == "0") return "0";

    int m = num1.size(), n = num2.size();
    QVector<int> result(m + n, 0);

    for (int i = n - 1; i >= 0; i--) {
        int a = num2[i].unicode() - '0';
        for (int j = m - 1; j >= 0; j--) {
            int b = num1[j].unicode() - '0';
            result[i + j + 1] += a * b;
        }
    }

    int carry = 0;
    for (int i = result.size() - 1; i > 0; i--) {
        carry = result[i] / 10;
        result[i] %= 10;
        result[i - 1] += carry;
    }

    QString res;
    bool leadingZero = true;
    for (int i = 0; i < result.size(); i++) {
        if (result[i] != 0 || !leadingZero) {
            leadingZero = false;
            res += QChar('0' + result[i]);
        }
    }

    return res.isEmpty() ? "0" : res;
}

QString MainWindow::divStrings(const QString &num1, const QString &num2, int decimalPlaces) {
    if (num2 == "0") return "Error: Division by zero";

    QString quotient;
    QString remainder = num1;
    QString divisor = num2;

    // 整数部分
    while (!remainder.isEmpty() && (remainder.size() >= divisor.size() || !remainder.startsWith("0"))) {
        QString temp = remainder.left(divisor.size());
        int count = 0;

        while (compareStrings(temp, divisor) >= 0) {
            temp = subStrings(temp, divisor);
            count++;
        }

        quotient.append(QChar('0' + count));

        if (remainder.size() > divisor.size()) {
            remainder = remainder.mid(1);
            temp += (remainder.isEmpty() ? "0" : QString(remainder[0]));
        } else {
            break;
        }
    }

    // 小数部分
    quotient += ".";
    remainder = subStrings(remainder, "0");

    for (int i = 0; i < decimalPlaces; i++) {
        remainder += "0";
        int count = 0;
        QString temp = remainder;

        while (compareStrings(temp, divisor) >= 0) {
            temp = subStrings(temp, divisor);
            count++;
        }

        quotient.append(QChar('0' + count));
        remainder = temp;
    }

    // 去掉可能多余的点号
    if (quotient == ".") quotient = "0";
    if (quotient.startsWith(".")) quotient.prepend("0");

    return quotient;
}

int MainWindow::compareStrings(const QString &num1, const QString &num2) {
    if (num1.size() > num2.size()) return 1;
    if (num1.size() < num2.size()) return -1;

    for (int i = 0; i < num1.size(); i++) {
        if (num1[i] > num2[i]) return 1;
        if (num1[i] < num2[i]) return -1;
    }

    return 0;
}
