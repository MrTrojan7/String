#include "String.h"

void String::CheckIndexLength(int index)
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
		capacity = (length + 1) * 1.5;
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
	ConcatChar(temp);
	if (temp != nullptr)
	{
		delete[] temp;
		temp = nullptr;
	}
}

int String::CompareTo(char* text)
{
	if (strlen(this->text) != strlen(text))
		return -1;
	unsigned int count = 0;
	for (unsigned int i = 0; text[i] != '\0'; i++)
	{
		if (this->text[i] == text[i])
			++count;
	}
	return count;
}

int String::CompareTo(String const& original)
{
	return CompareTo(original.text);
}

void String::ConcatChar(const char* text)
{
	unsigned len = strlen(text) + strlen(this->text);
	if (capacity <= len)
		ReallocNCopy(len + 10);
	strcat_s(this->text, capacity - 1, text);
}

void String::ConcatNum(int num)
{
	char str[100];
	_itoa_s(num, str, 10);
	int sz = strlen(str) + strlen(text);
	if (sz >= capacity - 1)
		ReallocNCopy(sz + 10);
	ConcatChar(str);
}

void String::ConcatString(String const& s)
{
	ConcatChar(s.text);
}

void String::ConcatDouble(double d)
{
	String d_str = ToString(d);
	ConcatString(d_str);
}

int String::IndexOf(char ch)
{
	for (unsigned int i = 0; i < length; i++)
	{
		if (text[i] == ch)
			return i;
	}
	return -1;
}

int String::LastIndexOf(char ch)
{
	for (int i = length - 1; i >= 0; i--)
	{
		if (text[i] == ch)
			return i;
	}
	return -1;
}

bool String::Equals(String const& right)
{
	return CompareTo(right.text) == strlen(text);
}

bool String::Contains(String const& right)
{
	if (Equals(right))
	{
		cout << "Contains is ==\n";
		return true;
	}
		
	if (strlen(text) < strlen(right.text))
	{
		cout << "strlen this* < strlen right!\n";
		return false;
	}
	else
	{
		if (SearchFirstElement(right.text) == strlen(right.text))
		{
			cout << "Contains true!!\n";
			return true;
		}
		cout << "this* contains is not have right text!\n";
		return false;
	}
	cout << "Default false!\n";
	return false;
}

bool String::StartWith(String const& right)
{
	unsigned int min_length;
	strlen(text) > strlen(right.text) ? min_length = strlen(right.text) : min_length = strlen(text);
	if (CompareTo(right) == min_length)
	{
		for (unsigned int i = 0; i < min_length; i++)
		{
			if (text[i] != right.text[i])
			{
				cout << "FALSE!\n";
				return false;
			}
		}
		cout << "TRUE!\n";
		return true;
	}
	return false;
}

bool String::EndsWith(String const& right)
{
	return false;
}




void String::ReallocNCopy()
{
	capacity = capacity * 1.5;
	char* tmp = new char[capacity];
	strcpy_s(tmp, capacity - 1, text);
	delete[] text;
	text = tmp;
}

void String::ReallocNCopy(int sz)
{
	capacity = sz;
	char* tmp = new char[capacity];
	strcpy_s(tmp, capacity - 1, text);
	delete[] text;
	text = tmp;
}

String String::ToString(double d)
{
	String s_num;
	if (d < 0)
		s_num.ConcatChar("-");
	int left = (int)d;
	int tmp = left;
	if (tmp < 0)
		tmp = -tmp;
	unsigned int sz = GetSizeOfNum(tmp);

	int pw = pow(10, sz - 1);
	if (sz == 0)
		s_num.ConcatNum(0);
	for (size_t i = 0; i < sz; i++)
	{
		s_num.ConcatNum(tmp / pw);
		tmp %= pw;
		pw /= 10;
	}
	s_num.ConcatChar(".");
	double right = abs(d - left);
	sz = GetSizeOfDouble(right);
	pw = pow(10, sz);
	right *= pw;
	right = TruncRightNulls(right);
	s_num.ConcatNum(right);
	return s_num;
}

bool String::ContainsTo(String const& right)
{

	return false;
}

int String::SearchFirstElement(const char* text, int index)
{
	int result = 0;
	if (index == strlen(this->text))
		return result;
	for (unsigned int i = 0; i < strlen(text); i++)
	{
		if(this->text[i + index] != text[i])
			return SearchFirstElement(text, ++index);
		if (this->text[i + index] == text[i])
			++result;
		if (result == strlen(text))
			return result;
	}
	return result;
}

unsigned int String::GetSizeOfNum(unsigned int num)
{
	unsigned int sz = 0;
	while (num)
	{
		num /= 10;
		++sz;
	}
	return sz;
}

unsigned int String::GetSizeOfDouble(double d)
{
	unsigned int size = 0;
	double mirror = 1.0 - d;
	int const precision = 2;
	int concurency = 0;
	while (true)
	{
		++size;
		d *= 10;
		mirror *= 10;
		int int_d = (int)d;
		int int_m = (int)mirror;
		if (int_d == 0 && int_m == 9)
			concurency++;
		if (int_d - int_m == 0 || concurency == precision) 
			break;
		d -= int_d;
		mirror -= int_m;
	}
	return size;
}

unsigned int String::TruncRightNulls(unsigned num)
{
	if (num == 0)
		return num;
	while (true)
	{
		if (num % 10 == 0)
			num /= 10;
		else
			break;
	}
	return num;
}
