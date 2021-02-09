#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	int result = 0;
	int i = 0;

	cin >> N;

	int j = N - 1;

	vector<int> vec(N);

	for (int k = 0; k < N; ++k) {
		cin >> vec[k];
	}

	sort(vec.begin(), vec.end());
	
	for (; i < j; i += 2) {
		if (vec[i] < 1 && vec[i + 1] < 1) {
			result += vec[i] * vec[i + 1];
		}
		else {
			break;
		}
	}
	for (; j > 0; j -= 2) {
		if (vec[j] > 1 && vec[j - 1] > 1){
			result += vec[j] * vec[j - 1];
		}
		else {
			break;
		}
	}
	for (; j >= i; --j) {
		result += vec[j];
	}

	cout << result;

	return 0;
}