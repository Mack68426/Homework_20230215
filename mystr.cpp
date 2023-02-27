#include <cstdlib>
#include <utility>
#include "mystr.h"

namespace my
{
	str::str()
		: m_length(0)
		, m_capacity(n_initial_capacity)
		, m_chars(static_cast<char*>(malloc(sizeof(char) * m_capacity)))
	{
		m_chars[0] = '\0';
	}

	str::str(const char* chars)
		: str()
	{
		append(chars);
	}

	str::str(const char ch)
		: str()
	{
		append(ch);
	}

	str::str(const str& other)
		: str(other.cstr())
	{
	}
	
	str::str(str&& other)
		: m_length(other.m_length)
		, m_capacity(other.m_capacity)
		, m_chars(other.m_chars)
	{
		other.m_chars = nullptr;
	}
	
	str::~str()
	{
		free(m_chars);
	}

	void str::append(char ch)
	{
		if (m_length + 1 >= m_capacity)
		{
			m_capacity *= 2;
			m_chars = static_cast<char*>(realloc(m_chars, m_capacity * sizeof(char)));
		}
		
		m_chars[m_length++] = ch;
		m_chars[m_length] = '\0';
	}

	void str::append(const char* chars)
	{
		while (*chars != '\0')
		{
		    append(*chars);
		    ++chars;
		}
	}
	
	size_t str::len() const
	{
		return m_length;
	}

	const char* str::cstr() const
	{
		return m_chars;
	}

	str& str::operator+=(char ch)
	{
		append(ch);

		return *this;
	}
	/* :
	str& str::operator+=(const char* chars)
	{
		append(chars);

		return *this;
	}
	*/

	str& str::operator+=(const str& other)
	{
		append(other.m_chars);
		
		return *this;
	}

	str& str::operator*=(size_t times)
	{
		if (times < 1)
		{
			m_chars[0] = '\0';
			m_length = 0;
		}
		else
		{
			const size_t original_length = m_length;

			
			for (size_t t = 1; t < times; ++t)
			{
				for (size_t i = 0; i < original_length; ++i)
				{
					// ¤]¥i¥H: *this += m_chars[i];
					append(m_chars[i]);
				}
			}
		}
		

		return *this;
	}
	/*:
	str str::operator+(char ch) const
	{
		str new_str = m_chars;
		new_str.append(ch);

		return new_str;
	}
	*/

	/*
	str str::operator+(const char* string) const
	{
		str new_str = m_chars;
		new_str.append(string);

		return new_str;
	}
	*/

	str str::operator+(const str& other) const
	{
		str new_str = m_chars;

		new_str.append(other.cstr());

		return new_str;
	}

	str str::operator*(size_t times) const
	{
		// my answer:
		// str new_str;
		// 
		// if (times >= 1)
		// {	
		// 	for (size_t t = 0; t < times; ++t)
		// 		new_str.append(m_chars);
		// }
		// 
		// return new_str;

		// better answer:
		str result(m_chars);
		result *= times;
		return result;

	}

	str& str::operator=(const str& other)
	{
		// m_chars[0] = '\0';
		*m_chars = '\0';
		m_length = 0;
		append(other.m_chars);

		return *this;
	}

	str& str::operator=(str&& other)
	{
		m_length = other.m_length;
		m_capacity = other.m_capacity;

		// swap (include <utility>)
		// std::swap(m_chars, other.m_chars);
		char* temp = m_chars;
		m_chars = other.m_chars;
		other.m_chars = temp;

		return *this;
	}
	

	str operator+(const char str1[], const str& str2)
	{
		str result = str1;
		
		return result + str2;
	}

	str operator*(size_t times, const str& string)
	{
		str result(string);
		// return result *= times; // return str&
		
		result *= times;

		
		// optimization (copy elision)
		return result;
	}

	std::ostream& operator<<(std::ostream& os, const str& mystr)
	{
		return os << mystr.cstr();
	}
	

	char str::operator[](size_t index) const
	{
		return m_chars[index];
	}
}



