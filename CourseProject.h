#include <iostream>
#include <string>
#include <vector>

template < size_t N >
class byte
{
private:
	unsigned char *array_of_bytes;
	size_t count_of_bit_in_register;

public:
	byte() 
	{}

	int to_int() const 
	{}

	const bool operator[](int index) const
	{}

	bool getbit(int index) const
	{}

	void setbit(int index, size_t newval)
	{}

	byte(unsigned long val)
	{}

	byte(const std::string& str, size_t pos, size_t n)
	{}

	byte& set()
	{};

	byte& set(size_t index, bool value = true)
	{}

	byte& reset()
	{}

	byte& reset(size_t index)
	{}

	byte& flip()
	{}

	byte& flip(size_t index)
	{}

	size_t count() const
	{}

	size_t size() const
	{}

	bool test(size_t index) const
	{}

	bool any()
	{}

	bool none()
	{}

	bool all() const
	{}

	byte& operator&= (const byte& rhs)
	{}

	byte& operator|= (const byte& rhs)
	{}

	byte& operator^= (const byte& rhs)
	{}

	byte& operator<<= (size_t pos)
	{}

	byte& operator>>= (size_t pos)
	{}

	byte operator~()
	{}

	byte operator<<(size_t pos)
	{}

	byte operator >> (size_t pos)
	{}

	bool operator== (const byte& rhs) const
	{}

	bool operator!= (const byte& rhs) const
	{}

	byte &operator += (const byte& rhs) 
	{}

	byte &operator += (const int& rhs) 
	{}

	byte &operator -= (const byte& rhs) 
	{}

	byte &operator -= (const int& rhs) 
	{}

	byte &operator =(const byte& rhs) 
	{}

	byte &operator =(int val) 
	{}

	std::string to_string()
	{}

	unsigned long to_ulong()
	{}

};

template<size_t N>
std::ostream & operator<<(std::ostream &out, byte<N> &rhs)
{}

template<size_t N>
byte<N> operator& (const byte<N>& lhs, const byte<N>& rhs)
{}

template<size_t N>
byte<N> operator| (const byte<N>& lhs, const byte<N>& rhs)
{}

template<size_t N>
byte<N> operator^ (const byte<N>& lhs, const byte<N>& rhs)
{}

class registers {
protected:
	byte<1> upper_first;
	byte<1> upper_second;
	byte<1> lower_first;
	byte<1> lower_second;
public:
	byte<1> &return_byte(size_t option) {}
};

std::ostream & operator<<(std::ostream &out, registers &rhs) {}

class saver_registers
{
	registers EAX;
	registers EBX;
public:
	byte<1> &return_by_string(const std::string &title) {}

	registers &return_reg_by_string(const std::string &title) {}

	registers mov_reg(const std::string &in, const std::string &out) {}

	registers mov_reg(const std::string &in, const unsigned long &out) {}

	byte<1> mov(const std::string &in, const std::string &out) {}

	byte<1> mov(const std::string &in, const unsigned long& out) {}

	byte<1> add(const std::string &in, const std::string &out) {}

	byte<1> add(const std::string &in, const unsigned long& out) {}

	byte<1> sub(const std::string &in, const std::string &out) {}

	byte<1> sub(const std::string &in, const unsigned long& out) {}

	bool cmp(const std::string &in, const std::string &out) {}

	bool parser(const std::string &input) {}
};
