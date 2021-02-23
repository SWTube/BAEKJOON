#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, arr[6], maximum[1001];
	cin >> n;
	for(int i=0; i<n; i++){
		int sum = 0;
		for(int j=0; j<5; j++){
			cin >> arr[j];
			sum += arr[j];
		}
		int max = 0;
		for(int j=0; j<4; j++){
			for(int k=j+1; k<5; k++){
				int temp;
				temp = sum - arr[j] - arr[k];
				temp %= 10;
				max = temp > max ? temp : max;
			}
		}
		maximum[i] = max;
	}
	int temp = maximum[0], idx = 1;
	for(int i=1; i<n; i++){
		if(maximum[i] >= temp){
			temp = maximum[i];
			idx = i+1;
		}
	}
	cout << idx;
	return 0;
}