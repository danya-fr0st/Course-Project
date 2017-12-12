#pragma once
#include "iostream"
#include "string"
#include "vector"
#include <iomanip> 
#include <fstream>
#include "Assembly_Byte.h"
#include "word.h"
#include "Double_Word.h"

class RAM 
{
	Assembly_Byte *data;
	int size;
	Assembly_Byte *elector;
	int size_elector;
	public:
		RAM();
		void inc_electors();
		void inc_data(int);
		void push(const Assembly_Byte &);
		void push(const Double_Word &);
		void push(const Word &);
		int pop();
		void print_stack();
		int elections(int);
		void kill_electors();
		void kill_elector(int);
		void dec_data(int);
		void print_electors();
		int make_double_word();
		int make_word();
		int make_byte();
};
