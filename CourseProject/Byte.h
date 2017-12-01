#pragma once

class byte
{
private:
	unsigned char array_of_bytes;
public:
	void setbit(int, bool); 
	/*! установка определенного бита в требуемое значение
	*/
	byte(int); 
	/*! пользовательский конструктор
	*/
	byte(); 
	/*! конструктор
	*/
	byte &operator =(const byte&); 
	/*! оператор присваивания к байту
	*/
	byte &operator =(int); 
	/*! присваивания к числу
	*/
	bool getbit(int) const; 
	/*! получение определенного бита
	*/
	void reset(); 
	/*! обнуление байтов
	*/
	void flip(); 
	/*! инверсия байта
	*/
	void flip(size_t); 
	/*! инверсия определенного бита
	*/
	bool operator== (const byte&) const; 
	/*! оператор сравнения
	*/
	bool operator!= (const byte&) const; 
	/*! оператор сравнения
	*/
	byte &operator += (const byte&); 
	/*! оператор увеличения левостороннего значения байта
	*/
	byte &operator += (int); 
	/*! оператор увеличения левостороннего значения числа
	*/
	byte &operator -= (const byte&); 
	/*! оператор уменьшения левостороннего значения байта
	*/
	byte &operator -= (int); 
	/*! оператор уменьшения левостороннего значения числа
	*/
	int to_int() const; 
	/*! функция приведения к int
	*/
	~byte(); 
	/*! деструктор
	*/
};

