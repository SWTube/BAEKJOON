#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int l, arr[51], n, count = 0;
	cin >> l;
	for(int i=0; i<l; i++){
		cin >> arr[i];
	}
	cin >> n;
	sort(arr,arr+l);
	int A,B;
	for(int i=0; i<l; i++){
		if(arr[i] < n)
			continue;
		if(arr[i] == n)
			break;
		B = arr[i];
		if(i == 0)
			A = 1;
		else
			A = arr[i-1];
		
		if(n==1)
			count = B - n - 1;
		else if(i==0)
			count = (n - A)*(B-n) + B-n-1;
		else
			count = (n - A)*(B-n)-1;
		break;
	}
	cout << count;
	return 0;
}