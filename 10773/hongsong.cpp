#include <iostream>
#include <stack>
using namespace std;

int main() {
	int k, sum = 0;
	stack<int> s;
	cin >> k;
	for(int i=0, integer; i<k; i++){
		cin >> integer;
		if(!integer){
			s.pop();
		}
		else
			s.push(integer);
	}
	
	while(!s.empty()){
		sum+= s.top();
		s.pop();
	}
	cout << sum;
	return 0;
}