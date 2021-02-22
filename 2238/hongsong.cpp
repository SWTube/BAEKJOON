#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
	int u,n;
	vector<pair<int,string>> arr;
	int count[100001];
	cin >> u >> n;
	for(int i=0; i<n; i++){
		int price;
		string name;
		cin >> name >> price;
		arr.push_back({price,name});
		count[price]++;
	}
	int min = 100001, idx = 0;
	for(int i=1; i<=u; i++){
		if(count[i] != 0 && count[i] < min){
			min = count[i];
			idx = i;
		}
	}
	for(int i=0; i<n; i++){
		if(arr[i].first == idx){
			cout << arr[i].second << " " << idx;
			break;
		}
			
	}
	return 0;
}