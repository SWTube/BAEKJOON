#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, sum, end;
	vector<pair<int,int>> v; 
	cin >> n;
	sum=1;
	for(int i=0; i<n; i++){
		int a,b;
		cin >> a >> b;
		v.push_back({b,a});
	}
	sort(v.begin() ,v.end());
	end = v[0].first;
	for(int i=1; i<n; i++){
		if(v[i].second >= end){
			sum++;
			end = v[i].first;
		}
	}
	cout << sum;
	return 0;
}