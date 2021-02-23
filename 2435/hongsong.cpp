#include <iostream>
using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	int arr[101];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int max = -9999999;
	for(int i=0; i<n-k+1; i++){
		int sum = arr[i];
		for(int j=i+1; j<i+k; j++){
			sum += arr[j];
		}
		max = max > sum ? max : sum;
	}
	cout << max;
	return 0;
}