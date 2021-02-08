#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, sum = 0;
	vector <int> pos,nag;
	cin >> n;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		if (a>0)
			pos.push_back(a);
		else
			nag.push_back(a);
	}
	sort(pos.begin(),pos.end(),greater<int>());
	sort(nag.begin(),nag.end());
	for(int i=0; i<pos.size();){
		if(i == pos.size()-1)
			sum += pos[i], i++;
		else if(pos[i]+pos[i+1] >= pos[i]*pos[i+1])
			sum += pos[i]+pos[i+1], i+=2;
		else
			sum += pos[i]*pos[i+1], i+=2;
	}
	for(int i=0; i<nag.size();){
		if(i!=nag.size()-1)
			sum += nag[i]*nag[i+1], i+=2;
		else
			sum += nag[i], i++;
	}
	cout << sum;
	return 0;
}