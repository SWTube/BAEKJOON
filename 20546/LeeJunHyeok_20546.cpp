#include <iostream>

using namespace std;

int main() {
	int money = 0;
	int arr[15];
	cin >> money;
	int s_money = money, j_money = money, s_stock = 0, j_stock = 0;
	
	for (int i = 1; i < 15; ++i) {
		cin >> arr[i];
	}

	for (int i = 1; i < 15; ++i) {
		if (arr[i] <= j_money && j_money != 0) {
			j_stock += j_money / arr[i];
			j_money = j_money % arr[i];
		}
	}

	for (int j = 4; j < 15; ++j) {
		if ((arr[j - 3] < arr[j - 2]) && (arr[j-2] < arr[j-1]) && (arr[j - 1] < arr[j]) && s_stock > 0) { // 풀 매도
			s_money += arr[j] * s_stock;
			s_stock = 0;
		}
		if ((arr[j - 3] > arr[j - 2]) && (arr[j - 2] > arr[j - 1]) && (arr[j - 1] > arr[j]) && arr[j] < s_money) { //풀 매수
			s_stock += s_money / arr[j];
			s_money = s_money % arr[j];
		}
	}
	
	if (arr[14] * j_stock + j_money > arr[14] * s_stock + s_money) {
		cout << "BNP";
	}
	else if (arr[14] * j_stock + j_money < arr[14] * s_stock + s_money) {
		cout << "TIMING";
	}
	else {
		cout << "SAMESAME";
	}

	return 0;
}