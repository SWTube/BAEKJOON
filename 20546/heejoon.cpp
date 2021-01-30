#include <iostream>
using namespace std;

// 0 is same, 1 is rise, 2 is fall
int PriceStatus(int a, int b, int c, int d) {
	int result = 0;
	
	if (a < b && b < c && c < d)
		result = 1;
	else if (a > b && b > c && c > d)
		result = 2;

	return result;
}

int main() {
	int StockPrice[14] = { 0, };
	int money;
	int Jun;
	int Sung;
	cin >> money;
	int totalstock = 0;

	for (int i = 0; i < 14; i++) {
		cin >> StockPrice[i];
	}

	// Junhyeon
	Jun = money;
	for (int i = 0; i < 14; i++) {
		int purchase = 0;
		if (Jun <= 0)
			break;
		purchase = Jun / StockPrice[i];
		totalstock += purchase;
		Jun -= purchase * StockPrice[i];
		
	}
	Jun += StockPrice[13] * totalstock;

	// Sungmin
	totalstock = 0;
	Sung = money;
	for (int i = 0; i < 11; i++) {
		switch (PriceStatus(StockPrice[i],StockPrice[i+1],StockPrice[i+2],StockPrice[i+3]))
		{
		case 0:
			break;
		case 1: // rise
			Sung += totalstock * StockPrice[i + 3];
			totalstock = 0;
			break;
		case 2: // fall
			int purchase = 0;
			purchase = (Sung / StockPrice[i + 3]);
			totalstock += purchase;
			Sung -= purchase * StockPrice[i + 3];
			if (Sung <= 0)
				break;
			break;
		
		}
	}
	Sung += totalstock * StockPrice[13];


	if (Jun > Sung)
		cout << "BNP";
	else if (Jun < Sung)
		cout << "TIMING";
	else
		cout << "SAMESAME";
}