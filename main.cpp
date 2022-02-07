#include "AllLibraries.h"
#include "Vector.h"
#include "Sorter.h"
#include "String.h"

int main()
{
	String str("string 2, test 2");
	str.ShowInfo();
	//str.GetLine();
	//str.ShowInfo();
	//str.PrintLn();
	String str2("string 2, test 2");
	str2.ShowInfo();
	//cout << str.CompareTo(str2);
	//str.ConcatChar(" concat!");
	//str.PrintLn();
	//str.ConcatNum(-123);
	//str.ConcatDouble(-1.121);
	//str.GetLine();
	//str.ConcatNum(12345678);
	//str.ConcatChar(" ConcatAfterDouble!!!");
	//str.PrintLn();
	//str.Clear();
	//str.ConcatChar("v1string 2, test 2xfd00000");
	//str.PrintLn();
	//str2.PrintLn();
	str.Contains(str2);
	//str.StartWith(str2);


	return 0;
}