#include "mainwindow.h"

int2 Variant::toInt2(QString format)
{
	/*
	форматна€ строка:
	* Ч конец строки
	пробел Ч раздел между первым и вторым числом
	0 Ч адресна€ арифметика
	1 Ч варианты адресации
	2 Ч адресность команд
	3 Ч операции јЋ”
	4 Ч тип сдвигател€
	5 Ч состав команд
	6 Ч логика обработки разных форматов команд
	ѕример:
	4320 165*
	0342 165*
	*/
	int2 res(0,0);
	std::string fstr = format.toStdString();
	char* buf = new char;
	int shift = 0;

	int i = fstr.size()-1;

	if (format.contains(' '))
	{
		// второе число
		for (; i>=0; i--)
		{
			*buf = fstr[i];
			if (*buf == ' ')
				break;

			if (atoi(buf)<7)
			{
				for (int j = 0; j < PARAMS[atoi(buf)].size; j++)
				{
					if (((atoi(buf) == 0) && (adr_calc == PARAMS[atoi(buf)].options[j]))||
					((atoi(buf) == 1) && (adr_var == PARAMS[atoi(buf)].options[j]))||
					((atoi(buf) == 2) && (com_adr == PARAMS[atoi(buf)].options[j]))||
					((atoi(buf) == 3) && (alu_ops == PARAMS[atoi(buf)].options[j]))||
					((atoi(buf) == 4) && (sh_type == PARAMS[atoi(buf)].options[j]))||
					((atoi(buf) == 5) && (commands == PARAMS[atoi(buf)].options[j]))||
					((atoi(buf) == 6) && (logic == PARAMS[atoi(buf)].options[j])))
						res.second |= (j<<shift);
				}
			}
			shift += PARAMS[atoi(buf)].size==2?1:2;
		}
		shift = 0;
	}
	
	// первое число
	for (; i>=0; i--)
	{
		*buf = fstr[i];
		if (*buf == ' ')
			continue;

		
		if (atoi(buf)<7)
		{
			for (int j = 0; j < PARAMS[atoi(buf)].size; j++)
			{
				if (((atoi(buf) == 0) && (adr_calc == PARAMS[atoi(buf)].options[j]))||
				((atoi(buf) == 1) && (adr_var == PARAMS[atoi(buf)].options[j]))||
				((atoi(buf) == 2) && (com_adr == PARAMS[atoi(buf)].options[j]))||
				((atoi(buf) == 3) && (alu_ops == PARAMS[atoi(buf)].options[j]))||
				((atoi(buf) == 4) && (sh_type == PARAMS[atoi(buf)].options[j]))||
				((atoi(buf) == 5) && (commands == PARAMS[atoi(buf)].options[j]))||
				((atoi(buf) == 6) && (logic == PARAMS[atoi(buf)].options[j])))
					res.first |= (j<<shift);
			}
		}
		shift += PARAMS[atoi(buf)].size==2?1:2;
	}

	return res;
}

Variant Variant::fromInt2(int2 num, QString format)
{
	Variant res;

	std::string fstr = format.toStdString();
	
	char* buf = new char;
	int shift = 0;
	int i = fstr.size()-1;

	if (format.contains(' '))
	{
		// второе число
		for (; i >=0 ; i--)
		{
			*buf = fstr[i];
			if (*buf==' ')
				break;

		
			if (atoi(buf)<7)
			{
				int mask = PARAMS[atoi(buf)].size==2?1:3;
				for (int j = 0; j < PARAMS[atoi(buf)].size; j++)
					if ((num.second&(mask<<shift)) == (j<<shift))
					{
						if (atoi(buf) == 0)
							res.adr_calc = ADR_CALC[j];
						else if (atoi(buf) == 1)
							res.adr_var = ADR_VAR[j];
						else if (atoi(buf) == 2)
							res.com_adr = COM_ADR[j];
						else if (atoi(buf) == 3)
							res.alu_ops = ALU_OPS[j];
						else if (atoi(buf) == 4)
							res.sh_type = SH_TYPE[j];
						else if (atoi(buf) == 5)
							res.commands = COMMANDS[j];
						else if (atoi(buf) == 6)
							res.logic = LOGIC[j];
					}
				shift += PARAMS[atoi(buf)].size==2?1:2;
			}
		
		}
		shift = 0;
	}
	
	// первое число
	for (; i>=0; i--)
	{
		*buf = fstr[i];
		if (*buf==' ')
			continue;

		if (atoi(buf)<7)
		{
			int mask = PARAMS[atoi(buf)].size==2?1:3;
			for (int j = 0; j < PARAMS[atoi(buf)].size; j++)
				if ((num.first&(mask<<shift)) == (j<<shift))
				{
					if (atoi(buf) == 0)
						res.adr_calc = ADR_CALC[j];
					else if (atoi(buf) == 1)
						res.adr_var = ADR_VAR[j];
					else if (atoi(buf) == 2)
						res.com_adr = COM_ADR[j];
					else if (atoi(buf) == 3)
						res.alu_ops = ALU_OPS[j];
					else if (atoi(buf) == 4)
						res.sh_type = SH_TYPE[j];
					else if (atoi(buf) == 5)
						res.commands = COMMANDS[j];
					else if (atoi(buf) == 6)
						res.logic = LOGIC[j];
				}

			shift += PARAMS[atoi(buf)].size==2?1:2;
		}
	}

	return res;
}