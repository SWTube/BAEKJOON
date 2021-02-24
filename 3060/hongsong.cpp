#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		int n, arr[6], day = 1;
		cin >> n;
		for(int j=0; j<6; j++){
			cin >> arr[j];
		}
		for(int k=0; ; k++){
			long long int sum = 0;
			day = k+1;
			for(int j=0; j<6; j++){
				sum += arr[j];
			}
			if(sum > n)
				break;
			int temp[6];
			temp[0] = arr[0] + arr[5] + arr[1] + arr[3];
			temp[5] = arr[5] + arr[0] + arr[4] + arr[2];
			for(int j=1; j<3; j++)
				temp[j] = arr[j-1] + arr[j] + arr[j+1] + arr[j+3];
			for(int j=3; j<5; j++)
				temp[j] = arr[j-1] + arr[j] + arr[j+1] + arr[j-3];
			for(int j=0; j<6; j++){
				arr[j] = temp[j];
			}
		}
		cout << day << "\n";
	}
	return 0;
}