#include "AllLibraries.h"
#include "Vector.h"
#include "Sorter.h"
#include "String.h"

int main()
{
	String str("55555550string 1, test 207777770string 2, test 2");
	str.ShowInfo();
	String str2("string 2, test 2");
	String str3("ABCDEF");
	str2.ShowInfo();
	str3.ShowInfo();

	//str.Contains(str2);
	//str.StartWith(str2);
	//str.EndsWith(str2);
	str.LastIndexOf(str2);
	str.IndexOf(str2);
	//str.Remove(40, 5);
	str.Replace(2, '4');
	str.Replace(str2, str3); // it's confusing, but it works
	str.ShowInfo();
	int pieces = 4;
	str.Split(4, pieces);
	cout << pieces << "\n";


	return 0;
}