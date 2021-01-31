#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> word;
int result = 0;
int alphaCheck[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	string alphaNum;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> alphaNum;
		word.push_back(alphaNum);
	}

	for (int i = 0; i < word.size(); i++)
	{
		int pow = 1;
		for (int j = word[i].size() - 1; j >= 0; j--)
		{
			int val = word[i][j] - 'A';
			alphaCheck[val] += pow;
			pow *= 10;
		}
	}

	sort(alphaCheck, alphaCheck + 26);

	int num = 9;
	for (int i = 25; i >= 0; i--) {
		if (alphaCheck[i] == 0) break;
		result += (alphaCheck[i] * num);
		num--;
	}

	cout << result;

	return 0;
}