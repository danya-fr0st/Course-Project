#pragma once
#include "Header.h"
#include "Byte.h"
#include "Registers.h"

class saver_registers
/*! в классе содержатся параметры регистров
*/
{
	registers EAX;
	registers EBX;

public:
	byte &return_by_string(const std::string &title); 
	/*! возврат по строке
	*/

	registers &return_reg_by_string(const std::string &title); 
	/*! возврат регистра по строке
	*/

	registers mov_reg(const std::string &in, const std::string &out); 
	/*! пересылка данных из источника в приемник
	*/

	byte mov(const std::string &in, const std::string &out); 
	/*! команда MOV
	*/
	byte mov(const std::string &in, int out);

	byte add(const std::string &in, const std::string &out); 
	/*! команда ADD
	*/
	byte add(const std::string &in, int out);

	byte sub(const std::string &in, const std::string &out); 
	/*! команда SUB
	*/
	byte sub(const std::string &in, int out);

	bool cmp(const std::string &in, const std::string &out); 
	/*! команда CMP
	*/
	bool parser(const std::string &input); 
	/*! парсер для распознавания команд
	*/
};



