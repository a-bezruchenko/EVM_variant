#ifndef CONFIG_H
#define CONFIG_H

#include <math.h>
#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"



struct Parameter
{
	int size;
	QString options[4];

	Parameter(const int s, const QString ops[]) 
	{
		size = s;
		for (int i = 0; i < size; i++)
			options[i] = ops[i];
	}
};

// �������� ����������
const int ADR_CALC_SIZE = 2;
const QString ADR_CALC [2] = {
	QString::fromLocal8Bit("�� ����� ���"),
	QString::fromLocal8Bit("�� �������� ���")
};

// �������� ���������
const int ADR_VAR_SIZE = 4;
const QString ADR_VAR [ADR_VAR_SIZE] = { 
	QString::fromLocal8Bit("��������� �����������, ����������������"), 
	QString::fromLocal8Bit("��������� �����������, ��������� ����������� �� ����"),
	QString::fromLocal8Bit("����������������, ��������� ����������� �� ���� � ���������������� ���������"),
	QString::fromLocal8Bit("��������� ����������� �� ���� � �������������� ����� � ���������������� ���������")
};

// ���������� ������
const int COM_ADR_SIZE = 2;
const QString COM_ADR [COM_ADR_SIZE] = {
	QString::fromLocal8Bit("������������"), 
	QString::fromLocal8Bit("������������")
};

// �������� ���
const int ALU_OPS_SIZE = 4;
const QString ALU_OPS [ALU_OPS_SIZE] = {
	QString::fromLocal8Bit("SHL, NAND, INC"),
	QString::fromLocal8Bit("SHRA, NAND, SET"),
	QString::fromLocal8Bit("SHLA, NOR, DEC"),
	QString::fromLocal8Bit("SHR, NOR, EQU")
};

// ��� ����������
const int SH_TYPE_SIZE = 4;
const QString SH_TYPE [SH_TYPE_SIZE] = {
	QString::fromLocal8Bit("�������������� �� ����� ����� �������� � ���� �������"),
	QString::fromLocal8Bit("��������� �� ���� ������ � ��� �������"),
	QString::fromLocal8Bit("��������� �� ���� ������ � ���� �������"),
	QString::fromLocal8Bit("�������������� �� ����� ����� �������� � ��� �������")
};

// ������ ������
const int COMMANDS_SIZE = 4;
const QString COMMANDS [COMMANDS_SIZE] = {
	QString::fromLocal8Bit("JZ, NAND, JMP, SHL"),
	QString::fromLocal8Bit("JC, NOR, INC, SLC"),
	QString::fromLocal8Bit("JN, NAND, SUB, DEC"),
	QString::fromLocal8Bit("JE, NOR, JMP, XCH")
};

// ������ ��������� ������ �������� ������
const int LOGIC_SIZE = 2;
const QString LOGIC [LOGIC_SIZE] = {
	QString::fromLocal8Bit("����������������"),
	QString::fromLocal8Bit("��������������")
};

const Parameter PARAMS[] = 
{
	Parameter(ADR_CALC_SIZE, ADR_CALC),
	Parameter(ADR_VAR_SIZE, ADR_VAR),
	Parameter(COM_ADR_SIZE, COM_ADR),
	Parameter(ALU_OPS_SIZE, ALU_OPS),
	Parameter(SH_TYPE_SIZE, SH_TYPE),
	Parameter(COMMANDS_SIZE, COMMANDS),
	Parameter(LOGIC_SIZE, LOGIC)
};

#endif // CONFIG_H