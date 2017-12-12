#include "Assembly_Byte.h"

Assembly_Byte::Assembly_Byte() 
{
	for (int i = 0; i < 8; ++i) 
	{
		setbit(i, 0);
	}
}

Assembly_Byte::Assembly_Byte(int val)
{
	int tmp = val;
	for (int i = 0; i < 8; ++i)
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
			for (int i = 7; !getbit(7 - i); --i)
			{
					flip(8 - i);
			}
		}
	}
}

Assembly_Byte::~Assembly_Byte() {}

Assembly_Byte& Assembly_Byte::operator += (const Assembly_Byte& in) 
{
	for (int i = 7; i >= 0; --i)
	{
		setbit(i, (in.getbit(i) != getbit(i)));
	}
	return *this;
}

Assembly_Byte& Assembly_Byte::operator -= (const Assembly_Byte& in) 
{
	for (int i = 7; i >= 0; --i)
	{
		setbit(i, (in.getbit(i) != getbit(i)));
	}
	return *this;
}

Assembly_Byte& Assembly_Byte::operator -= (int in) 
{
	int value = convert_into_int() - in;
	int tmp = value;
	for (int i = 0; i < 8; ++i)
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
			for (int i = 7; !getbit(7 - i); --i)
			{
				flip(8 - i);
			}
		}
	}
	return *this;
}

Assembly_Byte& Assembly_Byte::operator += (int in) 
{
	int value = convert_into_int() + in;
	int tmp = value;
	for (int i = 0; i < 8; ++i)
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
			for (int i = 7; !getbit(7 - i); --i)
			{
				flip(8 - i);
			}
		}
	}
	return *this;
}

Assembly_Byte& Assembly_Byte::operator =(const Assembly_Byte& in) 
{
	for (size_t i = 0; i <= 7; ++i)
	{
		setbit(i, in.getbit(i));
	}
	return *this;
}

Assembly_Byte& Assembly_Byte::operator =(int in) 
{
	reset();
	int tmp =in;
	for (int i = 0; i < 8; ++i)
	{
		if (in % 2)
		{
			setbit(i, 1);
		}
		else
		{
			setbit(i, 0);
		}
		in = in / 2;
	}
	if (tmp < 0) 
	{
		flip();
		flip(0);
		if (!getbit(0))
		{
			for (int i = 7; !getbit(7 - i); --i)
			{
				flip(8 - i);
			}
		}
	}
	return *this;
}

Assembly_Byte& Assembly_Byte::operator^=(const Assembly_Byte& in) 
{
	for (int i = 7; i >= 0; --i) 
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

Assembly_Byte& Assembly_Byte::operator&=(const Assembly_Byte& in) 
{
	for (int i = 7; i >= 0; --i) 
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

void Assembly_Byte::setbit(int index, bool newvalue)
{
	if (newvalue)
	{
		bytes_arrangement |= 1 << index;
	}
	else
	{
		bytes_arrangement &= ~(1 << index);
	}
}

bool Assembly_Byte::getbit(int index) const
{
	return bytes_arrangement >> index & 1;
}

int Assembly_Byte::convert_into_int() const 
{
	int result = 0;
	Assembly_Byte temp = *this;
	if (getbit(7)) 
	{
		if (getbit(0))
		{
			for (int i = 7; !getbit(7 - i); --i)
			{
				temp.flip(8 - i);
			}
		}
		temp.flip(0);
		temp.flip();
		for (int i = 0; i <= 7; ++i) 
		{
			if (temp.getbit(i))
			{
				result += (int)pow(2, i);
			}
		}
		return -result;
	}
	else 
	{
		for (int i = 0; i <= 7 ; ++i) 
		{
			if (getbit(i))
			{
				result += (int)pow(2, i);
			}
		}
	}
	return result;
}

void Assembly_Byte::reset()
{
	for (size_t i = 0; i < 8; ++i)
	{
		setbit(i, 0);
	}
}
void Assembly_Byte::flip(size_t index)
{
	setbit(index, !getbit(index));
}

void Assembly_Byte::flip()
{
	for (size_t i = 0; i < 8; i++)
	{
		setbit(i, !getbit(i));
	}
}

bool Assembly_Byte::operator== (const Assembly_Byte& in) const
{
	for (int i = 0; i < 8; ++i)
	{
		if (getbit(i) != in.getbit(i))
		{
			return false;
		}
	}
	return true;
}

unsigned char Assembly_Byte::return_array() const
{
	return bytes_arrangement;
}

unsigned char & Assembly_Byte::return_array() 
{
	return bytes_arrangement;
}

std::ostream & operator<<(std::ostream &out, Assembly_Byte &in)
{
	for (int i = 7; i >= 0; --i)
		out << in.getbit(i);
	return out;
}