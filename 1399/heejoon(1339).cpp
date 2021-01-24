#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/* �⺻ IDEA
* EX) ABC + BCA = (100A+10B+C) + (100B+10C+A) = 110B + 101A + 11C
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	string str;
	int sum = 0;
	vector<int> alphabet(26, 0); // 0���� �ʱ�ȭ �� ����

	for (int j = 0; j < N; j++) {
		cin >> str;
		int Size = str.size();
		for (int i = 0; i < Size; i++) {
			alphabet[str[i] - 'A'] += pow(10, (str.size()-1-i));
		}
	}

	// ���ĺ� sort�ϱ�!
	sort(alphabet.begin(), alphabet.end());

	int value = 9;
	for (int i = 25; i >= 17; i--) {
		
	
		sum += alphabet[i] * value;
		value--;
	
	}

	cout << sum;
}

// O(N)