#include "String.h"

void String::CheckIndexLength(unsigned int index)
{
	if (index < 0 || index >= length)
		throw "Invalid index!";
}

String::String() : String("", 80) {}

String::String(const char* text) : String(text, 80) {}

String::String(unsigned int capacity) : String("", capacity) {}

String::String(const String& original) : String(original.text, original.capacity) {}

String::String(const char* text, unsigned int capacity)
{
	SetString(text, capacity);
}

String::~String()
{
	if (text != nullptr)
	{
		delete[] text;
		text = nullptr;
	}
}

const char* const String::GetString() const
{
	return text;
}

void String::SetString(const char* text, unsigned int capacity)
{
	length = strlen(text);
	if (capacity <= length)
		capacity = length + 1;
	this->capacity = capacity;
	if (this->text != nullptr)
	{
		delete[] this->text;
		this->text = nullptr;
	}
	this->text = new char[capacity];
	strcpy_s(this->text, length + 1, text);
}

int String::GetLength() const
{
	return length;
}

int String::GetCapacity() const
{
	return capacity;
}

void String::Clear()
{
	text[0] = 0;
	length = 0;
}

void String::ShrinkToFit()
{
	if (length + 1 <= capacity)
		return;
	capacity = length + 1;
	char* temp = new char[capacity];
	strcpy_s(temp, capacity, text);
	delete[] text;
	text = temp;
}

void String::ShowInfo() const
{
	cout << "Text: " << GetString() << endl;
	cout << "Length: " << GetLength() << endl;
	cout << "Capacity: " << GetCapacity() << endl;
}

void String::Print() const
{
	for (unsigned int i = 0; text[i] != '\0'; i++)
		cout << text[i];
}

void String::PrintLn() const
{
	Print();
	cout << "\n";
}

char String::GetCharAt(unsigned int index)
{
	CheckIndexLength(index);
	return text[index];
}

void String::GetLine()
{
	int size = 4096;
	char* temp = new char[size];
	cout << "Enter string:\n";
	cin.getline(temp, size);
	Concat(temp);
	if (temp != nullptr)
	{
		delete[] temp;
		temp = nullptr;
	}
}

int String::CompareTo(char* text)
{
	unsigned int count = 0;
	unsigned int min_length;
	strlen(this->text) > strlen(text) ? min_length = strlen(text) : min_length = strlen(this->text);
	for (unsigned int i = 0; i < min_length; i++)
	{
		if (this->text[i] == text[i])
			++count;
	}
	return count;
}

int String::CompareTo(String& original)
{
	return CompareTo(original.text);
}

void String::Concat(const char* text)
{
	length = strlen(this->text) + strlen(text);
	this->capacity = length + 1;
	char* temp = new char[strlen(this->text) + 1];
	strcpy_s(temp, strlen(this->text) + 1, this->text);
	if (this->text != nullptr)
	{
		delete[] this->text;
		this->text = nullptr;
	}
	this->text = new char[capacity];
	strcpy_s(this->text, length + 1, temp);
	strcat_s(this->text, length + 1, text);
	if (temp != nullptr)
	{
		delete[] temp;
		temp = nullptr;
	}
}

void String::Concat(int num) // remake
{
	int result = (log(num) / 2);
	cout << "num-> " << num << " log-> " << result << "\n";
	char* buff = new char[result]; // problem
	for (int i = result - 1; i >= 0 ; i--)
	{
		buff[i] = ((num % 10) + 48);
		num /= 10;
	}
	Concat(buff);
	delete[] buff;
}
