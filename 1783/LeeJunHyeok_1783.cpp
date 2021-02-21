#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M; // N : 세로길이, M : 가로길이
	cin >> N >> M;
	
	if (N == 1) {
		cout << 1 << '\n';;
	}
	else if (N == 2) {
		cout << min(4, (M +1) / 2) << '\n';;
	}
	else if (M < 7) {
		cout << min(4, M) << '\n';
	}
	else {
		cout << M - 2 << '\n';
	}

	return 0;
}