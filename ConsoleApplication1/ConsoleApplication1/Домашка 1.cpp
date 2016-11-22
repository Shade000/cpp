#include <iostream>

#define TO_UPPER_REGISTER -32
#define TO_LOWER_REGISTER 32

class String
{
private:
	char* str_;
	int size = 0;

public:
	String(const char*);
	void change(const char*);
	inline char* getString();
	int lenghtOfString();
	void add(const char*);
	void pasteSymbol(char, int);
	void printAnsiiCods();
	void toUpperRegister();
	void toLowerRegister();
	~String();
};

String::String(const char* text)
{
	size = strlen(text) + 1;
	str_ = new char[size];
	strcpy_s(str_, size, text);
}

void String::change(const char* text)
{
	delete[] str_;
	size = strlen(text) + 1;
	str_ = new char[size];
	strcpy_s(str_, size, text);
}

inline char* String::getString()
{
	return str_;
}

int String::lenghtOfString()
{
	return strlen(str_);
}

void String::add(const char* text)
{
	size = strlen(text) + size;
	char* textBuffer = str_;
	str_ = new char[size];
	strcpy_s(str_, size, textBuffer);
	delete[] textBuffer;
	strcat_s(str_, size, text);
}

void String::pasteSymbol(char symbol, int index)
{
	if (index < 0 || index >= size)
	{
		std::cout << "Invalid index " << index << std::endl;
		return;
	}
	++size;
	char* textBuffer = str_;
	str_ = new char[size];
	strncpy_s(str_, index + 1, textBuffer, _TRUNCATE);	 
	str_[index] = symbol;
	for (int i = index + 1; i < size; ++i)
	{
		str_[i] = textBuffer[i - 1];
	}
}

void String::printAnsiiCods()
{
	int i = 0;
	while (str_[i] != '\0')
		std::cout << (int)str_[i++] << " ";
	std::cout << std::endl;
}

void String::toUpperRegister()
{
	int i = 0;
	while (str_[i] != '\0')
	{
		if ((int)str_[i] >= 'a' && (int)str_[i] <= 'z')
		{
			str_[i] += TO_UPPER_REGISTER;
		}
		++i;
	}
}

void String::toLowerRegister()
{
	int i = 0;
	while (str_[i] != '\0')
	{
		if ((int)str_[i] >= 'A' && (int)str_[i] <= 'Z')
		{
			str_[i] += TO_LOWER_REGISTER;
		}
		++i;
	}
}

String::~String()
{
	delete[] str_;
}

int main()
{
	String string("Hello!");
	std::cout << "1) ";
	std::cout << string.getString() << std::endl;
	string.change("Hello people!");
	std::cout << "2) ";
	std::cout << string.getString() << std::endl;
	std::cout << "4) Length of string = " << string.lenghtOfString() << std::endl;
	string.add(" What's up?");
	std::cout << "5) ";
	std::cout << string.getString() << std::endl;
	string.pasteSymbol('9', 12);
	std::cout << "6) ";
	std::cout << string.getString() << std::endl;
	std::cout << "7) ";
	string.printAnsiiCods();
	string.toUpperRegister();
	std::cout << "8) ";
	std::cout << string.getString() << std::endl;
	string.toLowerRegister();
	std::cout << "9) ";
	std::cout << string.getString() << std::endl;
	return 0;
}