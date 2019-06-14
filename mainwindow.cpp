#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	setWindowTitle(QString::fromLocal8Bit("ЭВМ, выбор варианта, версия 1.1"));

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(calculate()));

	/*QPixmap pm1("i1.bmp");
	ui.image_1->setPixmap(pm1);

	QPixmap pm2("i2.bmp");
	ui.image_2->setPixmap(pm2);*/

	// отключаем скролл у ComboBox'ов
	ui.adr_calc->installEventFilter(this);
	ui.adr_var->installEventFilter(this);
	ui.alu_ops->installEventFilter(this);
	ui.commands->installEventFilter(this);
	ui.com_adr->installEventFilter(this);
	ui.logic->installEventFilter(this);
	ui.sh_type->installEventFilter(this);
	ui.comboBox_6->installEventFilter(this);
	
	for (int i = 0; i < ADR_CALC_SIZE; i++)
		ui.adr_calc->addItem(ADR_CALC[i]);

	for (int i = 0; i < ADR_VAR_SIZE; i++)
		ui.adr_var->addItem(ADR_VAR[i]);

	for (int i = 0; i < ALU_OPS_SIZE; i++)
		ui.alu_ops->addItem(ALU_OPS[i]);

	for (int i = 0; i < COMMANDS_SIZE; i++)
		ui.commands->addItem(COMMANDS[i]);

	for (int i = 0; i < COM_ADR_SIZE; i++)
		ui.com_adr->addItem(COM_ADR[i]);

	for (int i = 0; i < LOGIC_SIZE; i++)
		ui.logic->addItem(LOGIC[i]);

	for (int i = 0; i < SH_TYPE_SIZE; i++)
		ui.sh_type->addItem(SH_TYPE[i]);

}

mainWindow::~mainWindow()
{

}

bool mainWindow::eventFilter (QObject * o,QEvent * e)
{
    if(e->type() == QEvent::Wheel)
    {
        return true;
    }
    return false; 
}

void mainWindow::calculate()
{
	if (ui.format->text().isEmpty())
		return;
	
	QString format = ui.format->text();
	int2 num(0,0);
	if (ui.comboBox_6->currentText() == QString::fromLocal8Bit("Вариант по номеру"))
	{
		num = int2(ui.variant_num_e1->value(), ui.variant_num_e2->value());
		setVariant(Variant::fromInt2(num, format));
	}
	else if (ui.comboBox_6->currentText() == QString::fromLocal8Bit("Номер по варианту"))
	{
		num = getVariant().toInt2(format);
		ui.variant_num_e1->setValue(num.first);
		ui.variant_num_e2->setValue(num.second);
	}
	int f = 0, s = 0;
	int index = 0;
	for (; index < format.size() && format.at(index) != ' '; index++)
		f += PARAMS[format.at(index).digitValue()].size==2?1:2;

	index++;
	for (; index < format.size() ; index++)
		s += PARAMS[format.at(index).digitValue()].size==2?1:2;

	ui.binary_output->setText(intToBin(num.first, f) +QString(" ")+ intToBin(num.second, s));
}

Variant mainWindow::getVariant()
{
	Variant res;
	res.adr_calc = ui.adr_calc->currentText();
	res.adr_var = ui.adr_var->currentText();
	res.alu_ops = ui.alu_ops->currentText();
	res.commands = ui.commands->currentText();
	res.com_adr = ui.com_adr->currentText();
	res.logic = ui.logic->currentText();
	res.sh_type = ui.sh_type->currentText();
	return res;
}

void mainWindow::setVariant(Variant var)
{
	ui.adr_calc->setCurrentText(var.adr_calc);
	ui.adr_var->setCurrentText(var.adr_var);
	ui.alu_ops->setCurrentText(var.alu_ops);
	ui.commands->setCurrentText(var.commands);
	ui.com_adr->setCurrentText(var.com_adr);
	ui.logic->setCurrentText(var.logic);
	ui.sh_type->setCurrentText(var.sh_type);
}

QString intToBin(int number, int digits)
{
	QString res;
	for (int i = 0; i < digits; i++)
	{
		res = QString::number(number&1) + res;
		number = number>>1;
	}
	return res;
}