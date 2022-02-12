#include "AllLibraries.h"
#include "Vector.h"
#include "Sorter.h"
#include "String.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	/*String str("    55554550string 1, test 20477747770string 4, test 2    ");
	str.ShowInfo();
	String str2("string 2, test 2");
	String str3("ABCDEF");
	str2.ShowInfo();
	str3.ShowInfo();*/

	//str.Contains(str2);
	//str.StartWith(str2);
	//str.EndsWith(str2);
	//str.LastIndexOf(str2);
	//str.IndexOf(str2);
	//str.Remove(40, 5);
	
	//str.Replace(str2, str3); // it's confusing, but it works
	
	//str.ShowInfo();
	//str.Reverse();
	

	String a("string5 test5");
	cout << a << "\n";
	String b("string6test66");
	cout << b << "\n";
	//a = b;
	//cout << a << "\n";
	if (a == b)
		cout << "Equal\n";
	b("string22test67687687676", 42);
	cout << b << "\n";
	b + a;
	cout << b << "\n";
	cout << *b << "\n";

	return 0;
}