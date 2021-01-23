#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string str;
	int alphabet[27];
	for (int i = 0; i < 26; i++)
		alphabet[i] = -1;
	cin >> str;
	
	for (int i = 0; i < str.length(); i++)
	{
		if (alphabet[str[i] - 97] == -1)
			alphabet[str[i] - 97] = i;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << alphabet[i] << " ";
	}
	return 0;
}