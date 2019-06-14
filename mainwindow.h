#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "config.h"

struct int2
{
	int2(int num1, int num2) {first = num1; second = num2;}
	int first, second;
};

struct Variant
{
	QString adr_var; // варианты адресации
	QString com_adr; // адресность команд
	QString alu_ops; // операции АЛУ
	QString sh_type; // тип сдвигателя
	QString adr_calc; // адресная арифметика
	QString commands; // состав команд
	QString logic; // логика обработки разных форматов команд

	int2 toInt2(QString format);

	static Variant fromInt2(int2, QString format);
};

class mainWindow : public QMainWindow
{
	Q_OBJECT

public:
	mainWindow(QWidget *parent = 0);
	~mainWindow();

	Variant getVariant();
	void setVariant(Variant);

public slots:
	void calculate();

private:
	Ui::mainWindowClass ui;

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
};

QString intToBin(int, int digits);

#endif // MAINWINDOW_H
