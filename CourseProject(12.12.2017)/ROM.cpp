#include "ROM.h"
#include <cstdlib>

Assembly_Byte& ROM::return_by_string(const std::string &title) {
	if (title == "AH") return EAX.return_byte(0);
	else if (title == "AL") return EAX.return_byte(1);
	else if (title == "BH") return EBX.return_byte(0);
	else if (title == "BL") return EBX.return_byte(1);
	else if (title == "CH") return ECX.return_byte(0);
	else if (title == "CL") return ECX.return_byte(1);
	else if (title == "DH") return EDX.return_byte(0);
	else if (title == "DL") return EDX.return_byte(1);
}
Double_Word& ROM::return_reg_by_string(const std::string &title) {
	if (title == "EAX") return EAX;
	else if (title == "EBX") return EBX;
	else if (title == "ECX") return ECX;
	else if (title == "EDX") return EDX;
}
/******************************doublecommand*****************************************/
void ROM::MOV(const std::string &in, const std::string &out) {
	int temp_out(0);
	if (validator_parts(out))
		temp_out = return_by_string(out).convert_into_int();
	else if (validator_reg(out))
		temp_out = return_reg_by_string(out).convert_into_int();
	else if (validator_title(out))
		temp_out = data.return_by_string(out).convert_into_int();
	else if(isint(out))
		temp_out = std::atoi(out.c_str());

	if (validator_parts(in))
		return_by_string(in) = temp_out;
	else if (validator_reg(in))
		return_reg_by_string(in) = temp_out;
	else if (validator_title(in))
		data.return_by_string(in) = temp_out;
	else {}
}
void ROM::ADD(const std::string &in, const std::string &out) {
	int temp_out(0);
	if (validator_parts(out))
		temp_out = return_by_string(out).convert_into_int();
	else if (validator_reg(out))
		temp_out = return_reg_by_string(out).convert_into_int();
	else if (validator_title(out))
		temp_out = data.return_by_string(out).convert_into_int();
	else if(isint(out))
		temp_out = std::atoi(out.c_str());

	if (validator_parts(in)) 
		return_by_string(in) += temp_out;
	else if (validator_reg(in))	 
		return_reg_by_string(in) += temp_out;
	else if (validator_title(in))
		data.return_by_string(in) += temp_out;
	else {}
}
void ROM::SUB(const std::string &in, const std::string &out) {
	int temp_out(0);
	if (validator_parts(out)) 
		temp_out = return_by_string(out).convert_into_int();
	else if (validator_reg(out))   
		temp_out = return_reg_by_string(out).convert_into_int();
	else if (validator_title(out)) 
		temp_out = data.return_by_string(out).convert_into_int();
	else
		temp_out = std::atoi(out.c_str());

	if (validator_parts(out)) 
		return_by_string(in) -= temp_out;
	else if (validator_reg(in))	
		return_reg_by_string(in) -= temp_out;
	else if (validator_title(in))
		data.return_by_string(in) -= temp_out;
	else {}
}
void ROM::XOR (const std::string &in, const std::string &out) {
	int temp_out;
	if (validator_parts(out))
		temp_out = return_by_string(out).convert_into_int();
	else if (validator_reg(out))
		temp_out = return_reg_by_string(out).convert_into_int();
	else if (validator_title(out))
		temp_out = data.return_by_string(out).convert_into_int();
	else
		temp_out = std::atoi(out.c_str());

	if (validator_parts(in))
		return_by_string(in) ^= temp_out;
	else if (validator_reg(in))
		return_reg_by_string(in) ^= temp_out;
	else if (validator_title(in))
		data.return_by_string(in) ^= temp_out;
	else {}
}
void ROM::AND (const std::string &in, const std::string &out) {
	int temp_out;
	if (validator_parts(out))
		temp_out = return_by_string(out).convert_into_int();
	else if (validator_reg(out))
		temp_out = return_reg_by_string(out).convert_into_int();
	else if (validator_title(out))
		temp_out = data.return_by_string(out).convert_into_int();
	else
		temp_out = std::atoi(out.c_str());

	if
		(validator_parts(in)) return_by_string(in) &= temp_out;
	else if
		(validator_reg(in))	  return_reg_by_string(in) &= temp_out;
	else if
		(validator_title(in)) data.return_by_string(in) &= temp_out;
	else {}
}
bool ROM:: CMP(const std::string &in, const std::string &out) {
	int temp_in, temp_out;
	if (validator_parts(in))
		temp_in = return_by_string(in).convert_into_int();
	else if (validator_reg(in))
		temp_in = return_reg_by_string(in).convert_into_int();
	else if (validator_title(in))
		temp_in = data.return_by_string(in).convert_into_int();
	else
		temp_in = std::atoi(out.c_str());

	if (validator_parts(out)) 
		temp_out = return_by_string(out).convert_into_int();
	else if (validator_reg(out))
		temp_out = return_reg_by_string(out).convert_into_int();
	else if (validator_title(out))
		temp_out = data.return_by_string(out).convert_into_int();
	else
		temp_out = std::atoi(out.c_str());

	if (temp_in == temp_out)
		return true;
	else
		return false;
}
void ROM::add_integer(int out, const std::string &in) 
{
	Double_Word temp(out);
	data.push(temp, in);
}
/**********************************command********************************************/
void ROM::PUSH (const std::string &in) 
{
	if (validator_title(in))
		Stack.push(data.return_by_string(in));
	else if (validator_parts(in))
		Stack.push(return_by_string(in));
	else if (validator_reg(in))	
		Stack.push(return_reg_by_string(in));
	else
		Double_Word i = std::atoi(in.c_str());
}
void ROM::POP (const std::string &in) 
{
	if (validator_parts(in)) 
		return_by_string(in) = Stack.pop();
	else if (validator_reg(in))
		return_reg_by_string(in) = Stack.pop();
	else if (validator_title(in))
		data.return_by_string(in) = Stack.pop();
}
/*************************************************************************************/
int ROM::comp(const std::string &input) 
{
	std::ifstream file(input);
	int count = 0;
	std::string in;
	for (file >> in; !file.eof(); file >> in) 
	{
		++count;
		if (in == "Double_Word") {
			file >> in;
			Double_Word temp(0);
			data.push(temp, in);
		}
		else if (validator_command_double(in)) {
			file >> in;
			if (!validator_title(in) && !validator_parts(in) && !validator_reg(in) && !isint(in)) {
				std::cout << "Unknown in: <" << in << "> in string " << count << std::endl;
				return false;
			}
			file >> in;
			if (!validator_title(in) && !validator_parts(in) && !validator_reg(in) && !isint(in)) {
				std::cout << "Unknown out: <" << in << "> in string " << count << std::endl;
				return false;
			}
		}
		else if (validator_command(in)) {
			file >> in; 
			if (!validator_title(in) && !validator_parts(in) && !validator_reg(in) && !isint(in)) {
				std::cout << "Unknown in: <" << in << "> in string " << count << std::endl;
				return false;
			}
		}
		else if (in == "out" || in == "jmp" || in == "jne" || in == "label") {}
		else {
			std::cout << "Unknown command: <" << in << "> in string " << count << std::endl;
			return false;
		}
	}
	for (; data.return_size() != 0; )
		data.pop();
	std::cout << "comp. completed. Strings in file: " << count << std::endl;
	return count;
}

bool ROM::parser(const std::string &input) 
{
	std::string in, out;
	if (validator_command_double(input)) 
	{
		std::cin >> in >> out;
		if (input == "mov") MOV(in, out);
		else if (input == "add") ADD(in, out);
		else if (input == "sub") SUB(in, out);
		else if (input == "cmp") CMP(in, out);
		else if (input == "xor") XOR(in, out);
		else if (input == "dec") ADD(in, "1");
		else if (input == "inc") SUB(in, "1");
		else if (input == "and") AND(in, out);
		return true;
	}
	else if (validator_command(input)) {
		std::cin >> in;
		if (input == "push") PUSH(in);
		else if (input == "pop") POP(in);
		else if (input == "dword") add_integer(0, in);
		return true;
	}
	else if (input == "out") 
	{
		std::cout <<
			"EAX: " << EAX << std::endl <<
			"EBX: " << EBX << std::endl <<
			"ECX: " << ECX << std::endl <<
			"EDX: " << EDX << std::endl << std::endl;
		return true;
	}
	else if (input == "open") file_parser();
	else if (input == "exit") return false;
	else std::cout << "Try again" << std::endl;
}

bool ROM::file_parser() 
{
	std::string in, out, label, input;
	int lbl = 0;
	std::cin >> in;
	std::ifstream file(in);
	if (!file.is_open()) 
	{
		std::cout << "CAN'T OPEN\n";
		return false;
	}
	file.seekg(0, std::ios_base::end);
	std::cout << "Opened file. File size: " << file.tellg() << std::endl;
	file.seekg(0, std::ios_base::beg);
	if (comp(in)) {
		std::cout << "\nRunning...\n";
		for (file >> input; !file.eof(); file >> input) {
			if (validator_command_double(input)) {
				file >> in >> out;
				if (input == "MOV") MOV(in, out);
				else if (input == "ADD")
					ADD(in, out);
				else if (input == "SUB")
					SUB(in, out);
				else if (input == "XOR") 
					XOR (in, out);
				else if (input == "AND") 
					AND (in, out);
				else if (input == "DEC") 
					ADD (in, "1");
				else if (input == "INC") 
					SUB (in, "1");
				else if (input == "CMP") {
					file >> label;
					int temp = file.tellg();
					if (label == "JNE") {
						if (CMP(in, out)) {
							file.seekg(-((int)file.tellg() - lbl), std::ios_base::cur);
						}
					}
					else {
						file.seekg(-((int)file.tellg() - temp), std::ios_base::cur);
					}
				}
			}
			else if (validator_command(input)) {
				file >> in;
				if (input == "PUSH") 
					PUSH(in);
				else if (input == "POP") 
					POP(in);
				else if (input == "Double_Word") 
					add_integer(0, in);
			}
			else if (input == "label") 
				lbl = file.tellg();
			else if (input == "JMP") 
				file.seekg(-((int)file.tellg() - lbl), std::ios_base::cur);
			else if (input == "out") {
				std::cout << "EAX: " << EAX << std::endl <<
					"EBX: " << EBX << std::endl <<
					"ECX: " << ECX << std::endl <<
					"EDX: " << EDX << std::endl << std::endl;
			}
			else if (input == "open") {
				file_parser();
			}
		}
		std::cout << "Finished.\n";
		return true;
	}
	return false;
}
/*************************************************************************************/
bool ROM::validator_parts(const std::string &in) 
{
	if (in == "AH" || in == "BH" || in == "AL" || in == "BL" || in == "CL" || in == "DL" || in == "CH" || in == "DH")
		return true;
	else return false;
}
bool ROM::validator_reg(const std::string &in) 
{
	if (in == "EAX" || in == "EBX" || in == "ECX" || in == "EDX")
		return true;
	else return false;
}
bool ROM::validator_command_double(const std::string &in) 
{
	if (in == "MOV" || in == "ADD" || in == "SUB" || in == "CMP" || in == "XOR" ||
		in == "AND")
		return true;
	else return false;
}
bool ROM::validator_command(const std::string &in) 
{
	if (in == "PUSH" || in == "POP" || in == "DEC" || in == "INC" || in == "Double_Word")
		return true;
	else return false;
}
bool ROM::validator_title(const std::string &in) 
{
	return data.validator(in);
}
bool ROM::isint(const std::string &in) 
{
	int i= 0;
	if (in[0] == '-') 
	{
		++i;
	}
	for (i; i < in.size(); ++i) 
	{
		if (!isdigit(in[i]))
			return false;
	}
	return true;
}
