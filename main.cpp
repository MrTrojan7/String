#include "AllLibraries.h"
#include "Vector.h"
#include "Sorter.h"
#include "String.h"

int main()
{
	String str("string 1, test 1");
	str.ShowInfo();
	str.PrintLn();
	cout << str.GetCharAt(8) << "\n";
	//str.GetLine();
	//str.ShowInfo();
	str.PrintLn();
	String str2("string 1 test 2");
	//cout << str.CompareTo(str2);
	str.ConcatChar(" concat!");
	str.PrintLn();
	//str.ConcatNum(-123);
	str.ConcatDouble(-1.121);
	//str.GetLine();
	//str.ConcatNum(12345678);
	//str.ConcatChar(" ConcatAfterDouble!!!");
	str.PrintLn();
	str.Clear();
	str.ConcatChar("22string 2, test 2hh");
	str.PrintLn();
	str2.PrintLn();
	str.Contains(str2);
	//str.StartWith(str2);


	return 0;
}