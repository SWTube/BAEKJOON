#include <iostream>

using namespace std;

int main() {

	int L = 1, P = 1, V = 1;

	for (int num = 1; L != 0; ++num){
		int result = 0;
		
		cin >> L >> P >> V;

		if (L == 0 && P == 0 && V == 0) {
			break;
		}

		for (; V > 0;) {
			if (V >= P) {
				V -= P;
				result += L;
			}
			else {
				if (V > L) {
					result += L;
					V = 0;
				}
				else {
					result += V;
					V = 0;
				}
			}
		}
		cout << "Case " << num << ": " << result << endl;
	}
	
	return 0;
}