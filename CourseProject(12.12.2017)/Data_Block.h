#pragma once
#include "iostream"
#include "string"
#include "vector"
#include <iomanip> 
#include <fstream>
#include "Assembly_Byte.h"
#include "Word.h"
#include "Double_Word.h"

class Data_Block 
{
	Double_Word  *data;
	char **title;
	int size;
	int count;
public:
	Data_Block();
	void inc_data();
	void dec_data();
	void push(const Double_Word &, const std::string &);
	void print_stack();
	int size_char(char*);
	bool validator(const std::string &);
	Double_Word &return_by_string(const std::string &);
	int return_size();
	Double_Word pop();
};
