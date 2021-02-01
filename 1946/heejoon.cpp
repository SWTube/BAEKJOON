#include <iostream>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	pair<int, int> candidate[100001];
	int T;
	int N;
	int cnt = 0;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		
		for (int i = 0; i < N; i++) {
			cin >> candidate[i].first >> candidate[i].second;
		}

		sort(candidate,candidate+N);

		int passcut = candidate[0].second;
		for (int i = 1; i < N; i++) {
			
			if (candidate[i].second < passcut) {
				passcut = candidate[i].second;
				cnt++;
			}
		}

		cout << cnt+1 << endl;
		cnt = 0;
	}
}
/*
* 시간 초과 코드
* for(int i=0;i<N-1;i++){
*	for(int j= i+1; j<N; j++){
*		if(candidate[i].first < candidate[j].first && candidate[i].second < candidate[j].second)
*				flase;
*				break;
*		else
*			cnt++;
*/
