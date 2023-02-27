#pragma once
#include <cstddef>
#include <ostream>

namespace my
{
	namespace
	{
		constexpr size_t n_initial_capacity = 2;
	}
	class str
	{
	public:
		str();
		str(const char);
		str(const char*);
		
		// copy constructor
		str(const str&);
		
		// move constructor
		// && rvalue reference
		str(str&&);
		~str();

		void append(char);
		void append(const char*);
		size_t len() const;
		const char* cstr() const;

		str& operator+=(char);
		//: str& operator+=(const char*);
		str& operator+=(const str&);
		str& operator*=(size_t);
		

		// after copy constructor
		//: str operator+(char) const;
		//: str operator+(const char*) const;
		str operator+(const str&) const;

		str operator*(size_t) const;

		// copy assignment operator
		str& operator=(const str&);

		// move assignment operator
		str& operator=(str&&);

		char operator[](size_t) const;

	private:
		size_t m_length;
		size_t m_capacity;
		char* m_chars;
	};

	str operator+(const char[], const str&);
	str operator*(size_t times, const str&);

	std::ostream& operator<<(std::ostream&, const str&);
}