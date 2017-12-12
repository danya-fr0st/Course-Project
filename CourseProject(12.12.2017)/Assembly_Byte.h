#pragma once
#include "iostream"
#include "string"
#include "vector"
#include <iomanip> 
#include <fstream>
/*!
\brief ����

���������� �����
*/
class Assembly_Byte
{
private:
	unsigned char bytes_arrangement; ///< ������������� ��������� �����
public:
	/*!
	\brief ������� ����������� ������	
	*/
	Assembly_Byte();
	/*!
	\brief ���������������� �����������
	\param val ������������� ���� ���� ������
	*/
	Assembly_Byte(int);

	~Assembly_Byte();
	/*!
	\brief �������� �������� � ���������.
	���������� �� ��������� ������������ ����� � ����������� ��������
	\param in ����������� ������ �� ������, � ������� ����� ��������� ��������
	*/
	Assembly_Byte &operator += (const Assembly_Byte&);
	/*!
	\brief �������� ������������.
	���������� �� ��������� ���������� � ����������� �������� �����
	\param in �����, � ������� ����� ��������� �������� 
	*/
	Assembly_Byte &operator += (int);
	/*!
	\brief �������� ��������� � ���������.
	�������� �������� ������������ ����� � ����������� ��������
	\param in ����������� ������ �� ������, � ������� ����� ��������� ���������
	*/
	Assembly_Byte &operator -= (const Assembly_Byte&);
	/*!
	\brief �������� ��������� � ���������.
	�������� �������� ����������� ���������� � ����������� �������� �����
	\param in �����, � ������� ����� ��������� ���������
	*/
	Assembly_Byte &operator -= (int);
	/*!
	\brief �������� ������������.
	����������� �������� ������� �����
	\param in ����������� ������ �� ������, �������� �������� ����� �������� �������� �����
	*/
	Assembly_Byte& operator &=(const Assembly_Byte&);
	/*!
	\brief �������� XOR.
	��������� �������� XOR ��� ���� ������, ���������� �������� � ������� ����, ����������� �������� �� ��������
	\param in ����������� ������ �� ������
	*/
	Assembly_Byte &operator =(const Assembly_Byte&);
	/*!
	\brief �������� ������������.
	����������� �������� ���������� �����
	\param in �����, �������� �������� ����� �������� �������� �����
	*/
	Assembly_Byte &operator =(int);
	/*!
	\brief �������� and.
	��������� �������� and ��� ���� ������, ���������� �������� � ������� ����, ����������� �� ��������
	\param in ����������� ������ �� ������
	*/
	Assembly_Byte& operator ^=(const Assembly_Byte&);
	/*!
	\brief ����������.
	���������� � int
	*/
	int convert_into_int() const;
	/*!
	\brief ��������.
	����������� ����
	*/
	void flip();
	/*!
	\brief ��������.
	����������� ��������� ���
	\param index �������� ������� ���� ����� �������������
	*/
	void flip(size_t);
	/*!
	\brief �����.
	��������� �����
	*/
	void reset();
	/*!
	\brief ��������� ����.
	������������� ��������� ��� � 0 ��� 1
	\param index ����� ������������� ����
	*/
	void setbit(int, bool);
	/*!
	\brief ��������� ����.
	���������� ��������� ���
	\param index ����� ������������� ����
	\return �������� ������������� ����
	*/
	bool getbit(int) const;
	/*!
	\brief �������� ���������.
	���������� 1, ���� ������� ����� � 0, ���� ���
	\param in ����������� ������ �� ������, � ������� ����� ��������� ���������
	*/
	bool operator== (const Assembly_Byte&) const;
	/*!
	\brief ������� ������� � ������
	*/
	unsigned char return_array() const;
	/*!
	\brief ������� ������� � ������.
	������� ��� ��������� �� ������
	*/
	unsigned char &return_array();
};
/*!
\brief �������� ������.
������� �������� �����
*/
std::ostream & operator<<(std::ostream &out, Assembly_Byte &rhs);