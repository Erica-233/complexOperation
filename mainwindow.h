#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QIntValidator>
#include <QMessageBox>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    QString addStrings(const QString &num1, const QString &num2);
    QString subStrings(const QString &num1, const QString &num2);
    QString mulStrings(const QString &num1, const QString &num2);
    QString divStrings(const QString &num1, const QString &num2, int decimalPlaces);
    int compareStrings(const QString &num1, const QString &num2);

    QLineEdit *num1Edit;
    QLineEdit *num2Edit;
    QLineEdit *decimalPlacesEdit;
    QTextEdit *resultEdit;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void performAddition();
    void performSubtraction();
    void performMultiplication();
    void performDivision();
    void performOperation(const QString &operation);

};
#endif // MAINWINDOW_H
