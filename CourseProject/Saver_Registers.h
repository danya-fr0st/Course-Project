#pragma once
#include "Header.h"
#include "Byte.h"
#include "Registers.h"

class saver_registers
/*! � ������ ���������� ��������� ���������
*/
{
	registers EAX;
	registers EBX;

public:
	byte &return_by_string(const std::string &title); 
	/*! ������� �� ������
	*/

	registers &return_reg_by_string(const std::string &title); 
	/*! ������� �������� �� ������
	*/

	registers mov_reg(const std::string &in, const std::string &out); 
	/*! ��������� ������ �� ��������� � ��������
	*/

	byte mov(const std::string &in, const std::string &out); 
	/*! ������� MOV
	*/
	byte mov(const std::string &in, int out);

	byte add(const std::string &in, const std::string &out); 
	/*! ������� ADD
	*/
	byte add(const std::string &in, int out);

	byte sub(const std::string &in, const std::string &out); 
	/*! ������� SUB
	*/
	byte sub(const std::string &in, int out);

	bool cmp(const std::string &in, const std::string &out); 
	/*! ������� CMP
	*/
	bool parser(const std::string &input); 
	/*! ������ ��� ������������� ������
	*/
};



