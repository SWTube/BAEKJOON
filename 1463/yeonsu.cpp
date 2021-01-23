#include <iostream>
#include <algorithm>
using namespace std;
int DP[1000000] = { 0, }; // 연산횟수를 저장하는 DP 배열
int main() {
	int x; cin >> x; // 정수 입력
	for (int i = 2; i <= x; i++) { // 1은 연산횟수가 0이므로 2부터 시작
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0) DP[i] = min(DP[i], DP[i / 2] + 1);
		if (i % 3 == 0) DP[i] = min(DP[i], DP[i / 3] + 1);
	}
	cout << DP[x]; // 결과 출력
	return 0;
}