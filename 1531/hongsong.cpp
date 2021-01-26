#include <iostream>
using namespace std;

int main() {
	int n,m,arr[100][100], x1, y1, x2, y2, sum;
	cin >> n >> m;
	sum = 0;
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			arr[i][j] = -m;
		}
	}
	for(int k=0; k<n; k++){
		cin >> x1 >> y1 >> x2 >> y2;
		for(int i=x1-1; i<x2; i++){
			for(int j=y1-1; j<y2; j++){
				arr[i][j]++;
			}
		}
	}
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			if(arr[i][j] > 0)
				sum++;
		}
	}
	cout << sum;
	return 0;
}