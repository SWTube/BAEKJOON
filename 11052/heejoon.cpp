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
	for (int i = 1; i <= N; i++) // P1���� �Է�!!
		cin >> P[i];

	//( P[N] vs P[N-i] + P[i] )
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++)
			P[i] = max(P[i], P[i-j] + P[j]); // P[N]�� �ᱹ N���� ī�带 ���� ���� �ݾ��� �ִ��� ����
	}
	cout << P[N];
}
 /* solved!
 * P[N] �̳� P[N-i] + P[i] �߿��� ū ���� 
 */