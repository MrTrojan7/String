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
	String str2("string 2, test 2");
	//cout << str.CompareTo(str2);
	str.Concat(" concat!cbweuib uheufhuwefewfhweifjugwf23yfhehfkjhafgeqgfehewfhkjhaehhhhhhhhhhhhhhhuwegfuwiu");
	str.PrintLn();
	str.Concat(123456789);
	str.PrintLn();


	return 0;
}