#pragma once
#include "iostream"
#include "string"
#include "vector"
#include <iomanip> 
#include <fstream>
#include "Assembly_Byte.h"

class Word 
{
	Assembly_Byte bytes_arrangement[2];
		public:
		Word(int);
		Word();
		Word &operator =(const Word&);
		Word &operator =(int);
		void flip(size_t);
		void reset();
		bool operator== (const Word&) const;
		bool operator!= (const Word&) const;
		Word &operator += (const Word&);
		Word &operator += (int);
		Word &operator -= (const Word&);
		Word &operator -= (int);
		int convert_into_int() const;
		~Word();
		void flip();
		bool getbit(int) const;
		void setbit(int, bool);
		Assembly_Byte return_byte(size_t) const;
		Assembly_Byte & return_byte(size_t);
		Word(const Assembly_Byte&, const Assembly_Byte&);
		Word& operator ^=(const Word&);
		Word& operator &=(const Word&);
};