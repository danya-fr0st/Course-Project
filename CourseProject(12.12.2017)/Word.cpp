#include "Word.h"

Word::Word() 
{
	bytes_arrangement[0] = 0;
	bytes_arrangement[1] = 0;
}

int Word::convert_into_int() const 
{
	int result = 0;
	Word temp = *this;
	if (getbit(15)) 
	{
		if (getbit(0))
			for (int i = 15; !getbit(15 - i); --i)
			{
				temp.flip(16 - i);
			}
		temp.flip(0);
		temp.flip();
		for (int i = 0; i <= 15; ++i) 
		{
			if (temp.getbit(i))
			{
				result += (int)pow(2, i);
			}
		}
		return -result;
	}

	else {
		for (int i = 0; i <= 15; ++i) 
		{
			if (getbit(i))
			{
				result += (int)pow(2, i);
			}
		}
	}
	return result;
}

Word::Word(int value)
{
	int tmp = value;

	for (int i = 0; i < 16; ++i)
	{
		if (value % 2)
			setbit(i, 1);
		else
			setbit(i, 0);
		value = value / 2;
	}

	if (tmp < 0) 
	{
		flip();
		flip(0);
		if (!getbit(0))
		{
			for (int i = 15; !getbit(15 - i); --i)
			{
				flip(16 - i);
			}
		}
	}
}

void Word::reset()
{
	for (size_t i = 0; i < 16; ++i)
	{
		setbit(i, 0);
	}
}

void Word::flip()
{
	for (size_t i = 0; i < 16; i++)
	{
		setbit(i, !getbit(i));
	}
}

bool Word::operator== (const Word& rhs) const
{
	for (int i = 0; i < 16; ++i)
	{
		if (getbit(i) != rhs.getbit(i))
		{
			return false;
		}
	}
	return true;
}

bool Word::operator!= (const Word& rhs) const
{
	for (int i = 0; i < 16; ++i)
	{
		if (getbit(i) != rhs.getbit(i))
		{
			return true;
		}
	}
	return false;
}

Word& Word::operator += (int rhs) 
{
	int val = convert_into_int() + rhs;
	int tmp = val;
	for (int i = 0; i < 16; ++i)
	{
		if (val % 2)
		{
			setbit(i, 1);
		}
		else
		{
			setbit(i, 0);
		}
		val = val / 2;
	}

	if (tmp < 0) 
	{
		flip();
		flip(0);
		if (!getbit(0))
		{
			for (int i = 15; !getbit(15 - i); --i)
			{
				flip(16 - i);
			}
		}
	}
	return *this;
}

Word& Word::operator -= (const Word& rhs) 
{
	for (int i = 15; i >= 0; --i)
	{
		setbit(i, (rhs.getbit(i) != getbit(i)));
	}
	return *this;
}

Word& Word::operator -= (int rhs) 
{
	int value = convert_into_int() - rhs;
	int tmp = value;
	for (int i = 0; i < 16; ++i)
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
			for (int i = 15; !getbit(15 - i); --i)
			{
				flip(16 - i);
			}
		}
	}
	return *this;
}

Word& Word::operator =(int value) 
{
	reset();
	int tmp = value;
	for (int i = 0; i < 16; ++i)
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
			for (int i = 15; !getbit(15 - i); --i)
			{
				flip(16 - i);
			}
	}
	return *this;
}

Word& Word::operator += (const Word& rhs) 
{
	for (int i = 15; i >= 0; --i)
	{
		setbit(i, (rhs.getbit(i) != getbit(i)));
	}
	return *this;
}

Word& Word::operator =(const Word& rhs) 
{
	for (size_t i = 0; i <= 15; ++i)
	{
		setbit(i, rhs.getbit(i));
	}
	return *this;
}

Word::~Word() {}

void Word::flip(size_t index)
{
	setbit(index, !getbit(index));
}

bool Word::getbit(int index) const
{
	if(index < 8)
	{
		return bytes_arrangement[0].return_array() >> index & 1;
	}
	else
	{
		return bytes_arrangement[1].return_array() >> (index - 8) & 1;
	}
}

void Word::setbit(int index, bool newval)
{
	if (newval && index < 8) 
	{
		bytes_arrangement[0].return_array() |= 1 << index;
	}
	else if (newval && index > 7) 
	{
		bytes_arrangement[1].return_array() |= 1 << index - 8;
	}
	else if (!newval && index < 8) 
	{
		bytes_arrangement[0].return_array() &= ~(1 << index);
	}
	else 
	{
		bytes_arrangement[1].return_array() &= ~(1 << (index - 8));
	}
}

Assembly_Byte Word::return_byte(size_t number) const 
{
	return bytes_arrangement[number];
}

Assembly_Byte & Word::return_byte(size_t number) 
{
	return bytes_arrangement[number];
}

Word::Word(const Assembly_Byte& first, const Assembly_Byte& second) 
{
	bytes_arrangement[0] = first;
	bytes_arrangement[1] = second;
}

Word& Word::operator^=(const Word& in) 
{
	for (int i = 15; i >= 0; --i) 
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

Word& Word::operator&=(const Word& in) 
{
	for (int i = 15; i >= 0; --i) 
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