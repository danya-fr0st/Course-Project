#pragma once
#include "iostream"
#include "string"
#include "vector"
#include <iomanip> 
#include <fstream>
/*!
\brief Байт

Реализация байта
*/
class Assembly_Byte
{
private:
	unsigned char bytes_arrangement; ///< Интерпритация машинного байта
public:
	/*!
	\brief Базовый конструктор класса	
	*/
	Assembly_Byte();
	/*!
	\brief Пользовательский конструктор
	\param val Устанавливает байт этим числом
	*/
	Assembly_Byte(int);

	~Assembly_Byte();
	/*!
	\brief Оператор сложения и равенства.
	Складывает со значением принимаемого байта и присваивает текущему
	\param in Константную ссылку на объект, с которым будет проходить сложение
	*/
	Assembly_Byte &operator += (const Assembly_Byte&);
	/*!
	\brief Оператор присваивания.
	Складывает со значением переменной и присваивает текущему байту
	\param in Число, с которым будет проходить сложение 
	*/
	Assembly_Byte &operator += (int);
	/*!
	\brief Оператор вычитания и равенства.
	Вычитает значение принимаемого байта и присваивает текущему
	\param in Константную ссылку на объект, с которым будет проходить вычитание
	*/
	Assembly_Byte &operator -= (const Assembly_Byte&);
	/*!
	\brief Оператор вычитания и равенства.
	Вычитает значение принимаемой переменной и присваивает текущему байту
	\param in Число, с которым будет проходить вычитание
	*/
	Assembly_Byte &operator -= (int);
	/*!
	\brief Оператор присваивания.
	Присваивает значение другого байта
	\param in Константную ссылку на объект, значение которого будет привоено текущему байту
	*/
	Assembly_Byte& operator &=(const Assembly_Byte&);
	/*!
	\brief Операция XOR.
	Выполняет операцию XOR для двух байтов, записывает значение в текущий байт, принимаемое значение не изменяет
	\param in Константную ссылку на объект
	*/
	Assembly_Byte &operator =(const Assembly_Byte&);
	/*!
	\brief Оператор присваивания.
	Присваивает значение переменной байту
	\param in Число, значение которого будет привоено текущему байту
	*/
	Assembly_Byte &operator =(int);
	/*!
	\brief Операция and.
	Выполняет операцию and для двух байтов, записывает значение в текущий байт, принимаемый не изменяет
	\param in Константную ссылку на объект
	*/
	Assembly_Byte& operator ^=(const Assembly_Byte&);
	/*!
	\brief Приведение.
	Приведение к int
	*/
	int convert_into_int() const;
	/*!
	\brief Инверсия.
	Инвертирует байт
	*/
	void flip();
	/*!
	\brief Инверсия.
	Инвертирует выбранный бит
	\param index Значение данного бита будет инвертировано
	*/
	void flip(size_t);
	/*!
	\brief Сброс.
	Обнуление байта
	*/
	void reset();
	/*!
	\brief Установка бита.
	Устанавливает выбранный бит в 0 или 1
	\param index Номер интересуемого бита
	*/
	void setbit(int, bool);
	/*!
	\brief Получение бита.
	Возвращает выбранный бит
	\param index Номер интересуемого бита
	\return Значение интересуемого бита
	*/
	bool getbit(int) const;
	/*!
	\brief Оператор сравнения.
	Возвращает 1, если объекты равны и 0, если нет
	\param in Константную ссылку на объект, с которым будет проходить сравнение
	*/
	bool operator== (const Assembly_Byte&) const;
	/*!
	\brief Возврат массива с байтом
	*/
	unsigned char return_array() const;
	/*!
	\brief Возврат массива с байтом.
	Возврат для изменения по ссылке
	*/
	unsigned char &return_array();
};
/*!
\brief Оператор вывода.
Выводит значение байта
*/
std::ostream & operator<<(std::ostream &out, Assembly_Byte &rhs);