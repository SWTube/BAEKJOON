#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, m; cin >> n >> m; // n : 세로, m : 가로

	if (n == 1) { // 세로가 1일 때 방문할 수 있는 최대 칸수는 1이다.
		cout << 1;
	}
	else if (n == 2) { // 세로가 2일 때 방문할 수 있는 최대 칸수는 4와 (m+1)/2 중 작은 값이다.
		cout << min(4, (m + 1) / 2);
	}
	else {
		if (m < 7) { // 가로가 7미만일 때 방문할 수 있는 최대 칸수는 4와 m 중 작은 값이다.
			cout << min(4, m);
		}
		else { // 그 외의 경우 방문할 수 있는 최대 칸수는 m - 7 + 5이다.
			cout << m - 7 + 5;
		}
	}

	return 0;
}