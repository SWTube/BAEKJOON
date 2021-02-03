#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int cash, stock[14], bnp_cash,timing_cash,bnp_stock = 0 ,timing_stock = 0;
	cin >> cash;
	for(int i=0; i<14; i++)
		cin >> stock[i];
	bnp_cash = cash, timing_cash = cash;
	int upCount = 0, downCount = 0;
	for(int i=0; i<14; i++){
		if(stock[i] <= bnp_cash){
			bnp_stock += bnp_cash / stock[i];
			bnp_cash %= stock[i];
		}
		if(i>=1){
			if(stock[i-1] < stock[i])
				downCount = 0, upCount++;
			else if(stock[i-1] > stock[i])
				upCount = 0, downCount++;
			else
				downCount=0, upCount=0;
		}
		if(upCount == 3){
			timing_cash += timing_stock*stock[i];
			timing_stock = 0;
			upCount--;
		}
		else if(downCount == 3){
			if(timing_cash >= stock[i]){
				timing_stock += timing_cash / stock[i];
				timing_cash %= stock[i];
			}
			downCount--;
		}
	}
	int bnp_sum = stock[13]*bnp_stock + bnp_cash, timing_sum = stock[13]*timing_stock + timing_cash;
	if(bnp_sum > timing_sum)
		cout << "BNP";
	else if (bnp_sum < timing_sum)
		cout << "TIMING";
	else
		cout << "SAMESAME";
	return 0;
}