#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T, num;
	cin >> T;
	
	for (int j = 0; j < T; j++) {
		cin >> num;
		vector<pair<int, int>> fibo(num+1);
		for (int i = 0; i <= num; i++) {
			if (i == 0) { fibo[0].first = 1, fibo[0].second = 0; }
			else if (i == 1) { fibo[1].first = 0, fibo[1].second = 1; }
			else {
				fibo[i].first = fibo[i - 1].first + fibo[i - 2].first;
				fibo[i].second = fibo[i - 1].second + fibo[i - 2].second;
			}
		}

		cout << fibo[num].first << ' ' << fibo[num].second << "\n";
	}
}