#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> arr;
vector<vector<int>> arr_case;

bool Descending(int a, int b) {
	return a > b;
}

int main() {
	int N;
	cin >> N;

	int num;

	for (int i = 0; i < N; ++i) {
		vector<int> a;
		for (int j = 0; j < 5; ++j) {
			cin >> num;
			a.push_back(num);
		}
		arr.push_back(a);
	}

	for (int l = 0; l < N; ++l) {
		int index = 0;
		vector<int> a;
		for (int i = 0; i < 2; ++i) {
			for (int j = i + 1; j < 4; ++j) {
				for (int k = j + 1; k < 5; ++k) {
					a.push_back((arr[l][i] + arr[l][j] + arr[l][k]) % 10);
					++index;
				}
			}
		}
		arr_case.push_back(a);
	}

	for (int i = 0; i < N; ++i) {;
		sort(arr_case[i].begin(), arr_case[i].end(), Descending);
	}

	int answer_index = 0;
	int answer_num = 0;

	for (int i = 0; i < N; ++i) {
		if (max(arr_case[i][0], answer_num) == arr_case[i][0]) {
			answer_index = i;
			answer_num = arr_case[i][0];
		}
	}

	cout << answer_index + 1;

	return 0;
}