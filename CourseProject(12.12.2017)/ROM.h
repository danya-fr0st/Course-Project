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
	\brief Класс симуляции

	Реализация работы с регистрами и обработка входящих данных
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
	\brief Возврат значения.
	Возвращает байт по строке
	\param title Возвращает ссылку на байт для пользования
	*/
	Assembly_Byte &return_by_string(const std::string &);
	/*!
	\brief Возврат значения.
	Возвращает регистр по строке
	\param title Возвращает ссылку на dword для пользования
	*/
	Double_Word &return_reg_by_string(const std::string &);
	/*!
	\brief Пересылка данных.
	mov приемник, источник. 
	Базовая команда пересылки данных. Копирует содержимое источника в приемник, источник не изменяется.
	\param in приемник
	\param out источник
	*/
	void MOV(const std::string &, const std::string &);
	/*!
	\brief Сложение данных.
	add приемник, источник.
	Складывает содержимое источника и приемника, результат записывается в приемник, источник не изменяется.
	\param in приемник
	\param out источник
	*/
	void ADD(const std::string &, const std::string &);
	/*!
	\brief Вычитание данных.
	sub приемник, источник.
	Вычитает содержимое источника из приемника, результат записывается в приемник, источник не изменяется.
	\param in приемник
	\param out источник
	*/
	void SUB(const std::string &, const std::string &);
	/*!
	\brief Операция xor.
	xor приемник, источник.
	Выполняет операцию xor источника и приемника, результат записывается в приемник, источник не изменяется.
	\param in приемник
	\param out источник
	*/
	void XOR(const std::string &, const std::string &);
	/*!
	\brief Операция and.
	and приемник, источник.
	Выполняет операцию xor источника и приемника, результат записывается в приемник, источник не изменяется.
	\param in приемник
	\param out источник
	*/
	void AND(const std::string &, const std::string &);
	/*!
	\brief Пересылка данных.
	cmp приемник, источник.
	Выполняет операцию сравнения источника и приемника, результат не изменяется, источник не изменяется.
	\param in приемник
	\param out источник
	\return 1 - равны, иначе - 0
	*/
	bool CMP(const std::string &, const std::string &);
	void add_integer(int, const std::string &);
	/*!
	\brief Запись в RAM.
	push источник.
	Записывает значение во временную память.
	\param in источник
	*/
	void PUSH(const std::string &);
	/*!
	\brief Возврат из RAM.
	pop приемник.
	Возвращает значение из временной памяти.
	\param in приемник
	\return Байт, слово, или двйоное слово
	*/
	void POP(const std::string &);
	int comp(const std::string &);
	bool parser(const std::string &);
	bool file_parser();
	/*!
	\brief Проверка наличия.
	Проверяет, введен ли правильный регистр
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


