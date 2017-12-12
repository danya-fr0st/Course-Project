#include "Double_Word.h"

Double_Word::Double_Word() 
{
	bytes_arrangement[0] = 0;
	bytes_arrangement[1] = 0;
}
int Double_Word::convert_into_int() const 
{
	int result = 0;
	Double_Word temp = *this;
	if (getbit(31)) {
		if (getbit(0))
			for (int i = 31; !getbit(31 - i); --i)
			{
				temp.flip(32 - i);
			}
		temp.flip(0);
		temp.flip();
		for (int i = 0; i <= 31; ++i) {
			if (temp.getbit(i))
				result += (int)pow(2, i);
		}
		return -result;
	}

	else {
		for (int i = 0; i <= 31; ++i) {
			if (getbit(i))
				result += (int)pow(2, i);
		}
	}
	return result;
}

Double_Word::Double_Word(int value)
{
	int tmp = value;

	for (int i = 0; i < 32; ++i)
	{
		if (value % 2)
		{
			setbit(i, 1);
		}
		else
		{
			setbit(i, 0);
		}
		value = value / 2;
	}
	if (tmp < 0) 
	{
		flip();
		flip(0);
		if (!getbit(0))
		{
			for (int i = 31; !getbit(31 - i); --i)
			{
				flip(32 - i);
			}
		}
	}
}

void Double_Word::reset()
{
	for (size_t i = 0; i < 32; ++i)
	{
		setbit(i, 0);
	}
}

void Double_Word::flip()
{
	for (size_t i = 0; i < 32; i++)
	{
		setbit(i, !getbit(i));
	}
}
bool Double_Word::operator== (const Double_Word& rhs) const 
{
	for (int i = 0; i < 32; ++i)
	{
		if (getbit(i) != rhs.getbit(i))
		{
			return false;
		}
	}
	return true;
}

Double_Word& Double_Word::operator += (int rhs) 
{
	int value = convert_into_int() + rhs;
	int tmp = value;
	for (int i = 0; i < 32; ++i)
	{
		if (value % 2)
		{
			setbit(i, 1);
		}
		else
		{
			setbit(i, 0);
		}
		value = value / 2;
	}
	if (tmp < 0) 
	{
		flip();
		flip(0);
		if (!getbit(0))
		{
			for (int i = 31; !getbit(31 - i); --i) 
			{
				flip(32 - i);
			}
		}
	}
	return *this;
}

Double_Word& Double_Word::operator -= (const Double_Word& rhs) 
{
	for (int i = 31; i >= 0; --i)
	{
		setbit(i, (rhs.getbit(i) != getbit(i)));
	}
	return *this;
}

Double_Word& Double_Word::operator -= (int rhs) 
{
	int value = convert_into_int() - rhs;
	int tmp = value;
	for (int i = 0; i < 32; ++i)
	{
		if (value % 2)
		{
			setbit(i, 1);
		}
		else
		{
			setbit(i, 0);
		}
		value = value / 2;
	}
	if (tmp < 0) 
	{
		flip();
		flip(0);
		if (!getbit(0))
		{
			for (int i = 31; !getbit(31 - i); --i) 
			{
				flip(32 - i);
			}
		}
	}
	return *this;
}

Double_Word& Double_Word::operator =(int value) 
{
	reset();
	int tmp = value;
	for (int i = 0; i < 32; ++i)
	{
		if (value % 2)
		{
			setbit(i, 1);
		}
		else
		{
			setbit(i, 0);
		}
		value = value / 2;
	}
	if (tmp < 0) 
	{
		flip();
		flip(0);
		if (!getbit(0))
		{
			for (int i = 31; !getbit(31 - i); --i)
			{
				flip(32 - i);
			}
		}
	}
	return *this;
}

Double_Word& Double_Word::operator += (const Double_Word& rhs) 
{
	for (int i = 31; i >= 0; --i)
	{
		setbit(i, (rhs.getbit(i) != getbit(i)));
	}
	return *this;
}

Double_Word& Double_Word::operator =(const Double_Word& rhs) 
{
	for (size_t i = 0; i <= 31; ++i)
	{
		setbit(i, rhs.getbit(i));
	}
	return *this;
}

Double_Word::~Double_Word() {}

void Double_Word::flip(size_t index)
{
	setbit(index, !getbit(index));
}

bool Double_Word::getbit(int index) const
{
	if (index < 8)
		return bytes_arrangement[0].return_array() >> index & 1;
	else if (index > 7 && index < 16)
		return bytes_arrangement[1].return_array() >> (index - 8) & 1;
	else if (index > 15 && index < 24)
		return bytes_arrangement[2].return_array() >> (index - 16) & 1;
	else
		return bytes_arrangement[3].return_array() >> (index - 24) & 1;
}

void Double_Word::setbit(int index, bool newval)
{
	if (newval) {
		if (index < 8)
			bytes_arrangement[0].return_array() |= 1 << index;
		else if (index > 7 && index < 16)
			bytes_arrangement[1].return_array() |= 1 << (index - 8);
		else if (index > 15 && index < 24)
			bytes_arrangement[2].return_array() |= 1 << (index - 16);
		else
			bytes_arrangement[3].return_array() |= 1 << (index - 24);
	}
	else {
		if (index < 8)
			bytes_arrangement[0].return_array() &= ~(1 << index);
		else if (index > 7 && index < 16)
			bytes_arrangement[1].return_array() &= ~(1 << (index - 8));
		else if (index > 15 && index < 24)
			bytes_arrangement[2].return_array() &= ~(1 << (index - 16));
		else
			bytes_arrangement[3].return_array() &= ~(1 << (index - 24));
	}
}

Assembly_Byte Double_Word::return_byte(size_t number) const
{
	return bytes_arrangement[number];
}

Assembly_Byte & Double_Word::return_byte(size_t number) 
{
	return bytes_arrangement[number];
}

Double_Word::Double_Word(const Assembly_Byte& first, const Assembly_Byte& second, const Assembly_Byte& third, const Assembly_Byte& fourth) 
{
	bytes_arrangement[0] = first;
	bytes_arrangement[1] = second;
	bytes_arrangement[2] = third;
	bytes_arrangement[3] = fourth;
}

Double_Word& Double_Word::operator^=(const Double_Word& in) 
{
	for (int i = 31; i >= 0; --i) 
	{
		if (in.getbit(i) == getbit(i)) 
		{
			setbit(i, 0);
		}
		else
		{
			setbit(i, 1);
		}
	}
	return *this;
}
Double_Word& Double_Word::operator&=(const Double_Word& in) 
{
	for (int i = 31; i >= 0; --i) 
	{
		if (in.getbit(i) == 1 && getbit(i) == 1) 
		{
			setbit(i, 1);
		}
		else
		{
			setbit(i, 0);
		}
	}
	return *this;
}
std::ostream & operator<<(std::ostream &out, Double_Word &rhs)
{
	for (int i = 3; i >= 0; --i)
	{
		out << rhs.return_byte(i) << " : ";
	}
	return out;
}