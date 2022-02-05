#pragma once
#include "AllLibraries.h"
class String
{
private:
char* text = nullptr;
unsigned int length = 0;
unsigned int capacity = 80;
void CheckIndexLength(unsigned int index);
void SetString(const char* text, unsigned int capacity);

public:
	String();
	String(const char* text);
	explicit String(unsigned int capacity);
	String(const String& original);
	String(const char* text, unsigned int capacity);
	~String();
	const char* const GetString() const;
	int GetLength() const;
	int GetCapacity() const;
	void Clear();
	void ShrinkToFit();
	void ShowInfo() const;
	void Print() const;
	void PrintLn() const;
	char GetCharAt(unsigned int index);
	void GetLine();
	int CompareTo(char* text);
	int CompareTo(String& original);
	void Concat(const char* text);
	void Concat(int num);
	//void Concat(double num);
	//void Concat(String& original);
};

