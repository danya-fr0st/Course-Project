#pragma once

#include "Byte.h"
class registers 
{
	protected:
		byte upper_first; 
		byte upper_second;
		byte lower_first;
		byte lower_second;
	public:
		byte &return_byte(size_t option); //возвращение байта
};

