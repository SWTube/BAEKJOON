#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int,int>> arr;
	for(int i=0; i<n; i++){
		int d,c;
		cin >> d >> c;
		arr.push_back({d,c});
	}
	bool check[10001] = {true,};
	int count = n;
	for(int i=0; i<n; i++){
		int dis = arr[i].first, cost = arr[i].second;
		for(int j=0; j<n; j++){
			if(dis >= arr[j].first && cost > arr[j].second){
				count--;
				break;
			}
			else if(cost >= arr[j].second && dis > arr[j].first){
				count--;
				break;
			}
		}
	}
	cout << count;
	return 0;
}