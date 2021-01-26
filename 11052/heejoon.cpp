#include <iostream>
#include <algorithm>
using namespace std;

int P[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	int max_amount = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) // P1부터 입력!!
		cin >> P[i];

	//( P[N] vs P[N-i] + P[i] )
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++)
			P[i] = max(P[i], P[i-j] + P[j]); // P[N]은 결국 N개의 카드를 갖기 위한 금액의 최댓값이 저장
	}
	cout << P[N];
}
 /* solved!
 * P[N] 이냐 P[N-i] + P[i] 중에서 큰 값을 
 */