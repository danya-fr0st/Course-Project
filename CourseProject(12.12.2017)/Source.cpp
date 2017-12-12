#include "iostream"
#include "string"
#include "vector"
#include <iomanip> 
#include <fstream>
#include "ROM.h"
#include "Word.h"
#include "Double_Word.h"
#include "Data_Block.h"

std::ostream & operator<<(std::ostream &out, Word &rhs)
{
	for (int i = 15; i >= 0; --i)
	{
		out << rhs.getbit(i);
	}
	return out;
}

int main()
{
	ROM one;
	std::string input;
	while (input != "exit") 
	{
		std::cout << "List of avaible commands: MOV, ADD, SUB, CMP, POP, PUSH, XOR, OUT, AND, DEC, INC, OPEN, JNE, JMP" << std::endl;
		std::cin >> input;
		one.parser(input);
		system("pause");
		system("cls");
	}

	/*data_block a;
	dword b(7);
	a.push(b, "first");
	a.push(b, "second");
	a.push(b, "3");
	a.push(b, "4");
	a.print_stack();*/
	
	
	
}