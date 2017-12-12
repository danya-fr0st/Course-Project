#pragma once
#include "iostream"
#include "string"
#include "vector"
#include <iomanip> 
#include <fstream>
#include "Assembly_Byte.h"
#include "word.h"
#include "Double_Word.h"
#include "data_block.h"
#include "RAM.h"
/*!
	\brief ����� ���������

	���������� ������ � ���������� � ��������� �������� ������
	*/
class ROM
{
	Double_Word EAX;
	Double_Word EBX;
	Double_Word ECX;
	Double_Word EDX;
	RAM Stack;
	Data_Block data;
public:
	/*!
	\brief ������� ��������.
	���������� ���� �� ������
	\param title ���������� ������ �� ���� ��� �����������
	*/
	Assembly_Byte &return_by_string(const std::string &);
	/*!
	\brief ������� ��������.
	���������� ������� �� ������
	\param title ���������� ������ �� dword ��� �����������
	*/
	Double_Word &return_reg_by_string(const std::string &);
	/*!
	\brief ��������� ������.
	mov ��������, ��������. 
	������� ������� ��������� ������. �������� ���������� ��������� � ��������, �������� �� ����������.
	\param in ��������
	\param out ��������
	*/
	void MOV(const std::string &, const std::string &);
	/*!
	\brief �������� ������.
	add ��������, ��������.
	���������� ���������� ��������� � ���������, ��������� ������������ � ��������, �������� �� ����������.
	\param in ��������
	\param out ��������
	*/
	void ADD(const std::string &, const std::string &);
	/*!
	\brief ��������� ������.
	sub ��������, ��������.
	�������� ���������� ��������� �� ���������, ��������� ������������ � ��������, �������� �� ����������.
	\param in ��������
	\param out ��������
	*/
	void SUB(const std::string &, const std::string &);
	/*!
	\brief �������� xor.
	xor ��������, ��������.
	��������� �������� xor ��������� � ���������, ��������� ������������ � ��������, �������� �� ����������.
	\param in ��������
	\param out ��������
	*/
	void XOR(const std::string &, const std::string &);
	/*!
	\brief �������� and.
	and ��������, ��������.
	��������� �������� xor ��������� � ���������, ��������� ������������ � ��������, �������� �� ����������.
	\param in ��������
	\param out ��������
	*/
	void AND(const std::string &, const std::string &);
	/*!
	\brief ��������� ������.
	cmp ��������, ��������.
	��������� �������� ��������� ��������� � ���������, ��������� �� ����������, �������� �� ����������.
	\param in ��������
	\param out ��������
	\return 1 - �����, ����� - 0
	*/
	bool CMP(const std::string &, const std::string &);
	void add_integer(int, const std::string &);
	/*!
	\brief ������ � RAM.
	push ��������.
	���������� �������� �� ��������� ������.
	\param in ��������
	*/
	void PUSH(const std::string &);
	/*!
	\brief ������� �� RAM.
	pop ��������.
	���������� �������� �� ��������� ������.
	\param in ��������
	\return ����, �����, ��� ������� �����
	*/
	void POP(const std::string &);
	int comp(const std::string &);
	bool parser(const std::string &);
	bool file_parser();
	/*!
	\brief �������� �������.
	���������, ������ �� ���������� �������
	\param in 
	*/
	bool validator_parts(const std::string &);
	bool validator_reg(const std::string &);
	bool validator_command_double(const std::string &);
	bool validator_command(const std::string &);
	bool ROM::validator_title(const std::string &);
	bool isint(const std::string &in);
};

std::ostream & operator<<(std::ostream &out, Double_Word &rhs);


