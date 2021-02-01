#include <iostream>

using namespace std;

int main() {
	int cnt = 0;
	while (true) {
		cnt++;
		int L, P, V;
		cin >> L >> P >> V;

		if ((L==0)&(P==0)&(V==0))
			break;
		int camping = 0;
		int div;
		div = V / P;
		
		// 2 Cases!!
		if (V % P <= L) {
			camping = (L * div) + (V - P * div);
		}
		else {
			camping = L * (div + 1);
		}


		cout << "Case " << cnt << ": " << camping << endl;
	}
}