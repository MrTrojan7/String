#pragma once
#include "AllLibraries.h"
class String
{
private:
char* text = nullptr;
unsigned int length = 0;
unsigned int capacity = 80;

public:
	String();
	String(const char* text);
	String(unsigned int capacity);
	String(const String& original);
	String(const char* text, unsigned int capacity);
	~String();
	const char* const GetString() const;
	void SetString(const char* text, unsigned int capacity = 80);
	int GetLength() const;
	int GetCapacity() const;
	void Clear();
	void ShrinkToFit();
	void ShowInfo() const;
};

