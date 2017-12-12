#include "Data_Block.h"
#include "cstring"

Data_Block::Data_Block() : size(0), count(0) {}

void Data_Block ::inc_data() 
{
		Double_Word *temp_data = new Double_Word[size];
		for (int i = 0; i <= size - 1; ++i)
		{
			temp_data[i] = data[i];
		}
		delete[]data;
		count *= 2;
		data = new Double_Word[count];
		for (int i = 0; i <= size - 1; ++i)
		{
			data[i] = temp_data[i];
		}
		delete[]temp_data;
		char **temp_title = new char*[size];
		for (int i = 0; i <= size - 1; ++i) 
		{
			temp_title[i] = new char[size_char(title[i])];
			temp_title[i] = title[i];
		}
		delete[]title;
		title = new char*[count];
		for (int i = 0; i <= size - 1; ++i) 
		{
			title[i] = new char[size_char(temp_title[i])];
			title[i] = temp_title[i];
		}
		delete[]temp_title;
}
void Data_Block::dec_data() 
{
	Double_Word *temp_data = new Double_Word[size];
	for (int i = 0; i <= size - 1; ++i)
	{
		temp_data[i] = data[i];
	}
	delete[]data;
	count /= 2;
	data = new Double_Word[count];
	for (int i = 0; i <= size - 1; ++i)
	{
		data[i] = temp_data[i];
	}
	delete[]temp_data;
	char **temp_title = new char*[size];
	for (int i = 0; i <= size - 1; ++i) 
	{
		temp_title[i] = new char[size_char(title[i])];
		temp_title[i] = title[i];
	}
	delete[]title;
	title = new char*[count];
	for (int i = 0; i <= size - 1; ++i) 
	{
		title[i] = new char[size_char(temp_title[i])];
		title[i] = temp_title[i];
	}
	delete[]temp_title;
}

int Data_Block ::size_char(char* text) 
{
	int i = 0;
	while (*text++) ++i;
	return i;
}
void Data_Block::push(const Double_Word &value, const std::string& in) 
{
	if (size < 1048000) 
	{
		if (size == 0 && count == 0) 
		{
			++size;
			++count;
			data = new Double_Word[1];
			data[0] = value;
			title = new char*[1];
			title[0] = new char[in.size() + 2];
			strcpy_s(title[0], in.size() + 1, in.c_str());
		}
		else 
		{
			++size;
			if (count <= size) 
			{
				inc_data();
			}
			title[size - 1] = new char[in.size() + 2];
			strcpy_s(title[size - 1], in.size() + 1, in.c_str());
			data[size - 1] = value;
  		}
	}
}

void Data_Block ::print_stack() 
{
	for (int i = size - 1; i >= 0; i--)
	{
		std::cout << "title[" << i << "] : " << title[i] << data[i] << std::endl;
	}
}
bool Data_Block::validator(const std::string &in) 
{
	for (int i = 0; i < size; ++i) 
	{
		if (in == title[i]) 
		{
			return true;
		}
	}
	return false;
}
Double_Word& Data_Block::return_by_string(const std::string &in) 
{
	for (int i = 0; i < size; ++i) 
	{
		if (in == title[i]) 
		{
			return data[i];
		}
	}
}
int Data_Block ::return_size() 
{
	return size;
}
Double_Word Data_Block ::pop() 
{
	--size;
	if (count - size == size)
		dec_data();
	return data[size];
}