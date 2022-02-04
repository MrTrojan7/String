#include "String.h"
char* text = nullptr;
unsigned int length = 0;
unsigned int capacity = 80;

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
	for (unsigned int i = 0; i < GetLength(); i++)
		cout << text[i];
}

void String::PrintLn() const
{
	for (unsigned int i = 0; i < GetLength(); i++)
		cout << text[i];
	cout << "\n";
}

char String::GetCharAt(unsigned int index)
{
	CheckIndexLength(index);
	return text[index];
}

void String::GetLine() // do a function for reallocation *text
{
	int size = 4096;
	char* temp = new char[size];
	cout << "Enter string:\n";
	cin.getline(temp, size);
	
	if(temp != nullptr)
		delete[] temp;
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

void String::Concat(const char* text) //do a function for reallocation* text
{
	cout << "concat\n";
	length = strlen(this->text) + strlen(text);
	if (capacity <= length)
		SetString(this->text, length);
	strcat_s(this->text, length + 1, text);
}
