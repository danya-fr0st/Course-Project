#pragma once
#include "iostream"
#include "string"
#include "vector"
#include <iomanip> 
#include <fstream>
#include "Assembly_Byte.h"

class Double_Word 
{
	Assembly_Byte bytes_arrangement[4];
	public:
		Double_Word (int);
		Double_Word ();
		Double_Word &operator =(const Double_Word &);
		Double_Word  &operator =(int);
		void flip(size_t);
		void reset();
		bool operator== (const Double_Word &) const;
		Double_Word &operator += (const Double_Word &);
		Double_Word &operator += (int);
		Double_Word &operator -= (const Double_Word &);
		Double_Word &operator -= (int);
		int convert_into_int() const;
		~Double_Word ();
		void flip();
		bool getbit(int) const;
		void setbit(int, bool);
		Assembly_Byte return_byte(size_t) const;
		Assembly_Byte & return_byte(size_t);
		Double_Word (const Assembly_Byte&, const Assembly_Byte&, const Assembly_Byte&, const Assembly_Byte&);
		Double_Word & operator ^=(const Double_Word &);
		Double_Word & operator &=(const Double_Word &);
};

std::ostream & operator<<(std::ostream &out, Double_Word  &rhs);