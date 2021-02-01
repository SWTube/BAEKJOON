#include<iostream>
using namespace std;
int main() {
  int input;
  cin >> input;

  int money1 = input, money2 = input;
  int stock1 = 0, stock2 = 0;

  int arr[14];
  int up = 0, down = 0;

  for (int i = 0; i < 14; i++) {
    cin >> arr[i];
    if (money1 >= arr[i]) {
      stock1 += money1 / arr[i];
      money1 -= money1 / arr[i] * arr[i];
    }
    if (i != 0) {
      if (arr[i - 1] < arr[i]) {
        up += 1;
        down = 0;
      }else if(arr[i - 1] > arr[i]) {
        down += 1;
        up = 0;
      }
      else {
        down = 0;
        up = 0;
      }
    }
    if (down >= 3) {
      if (money2 >= arr[i]) {
        stock2 +=  money2 / arr[i];
        money2 -= money2 / arr[i] * arr[i];
      }
    }
    if (up >= 3) {
      if (stock2 > 0) {
        money2 += stock2 * arr[i];
        stock2 = 0;
      }
    }
  }
  if (money1 + stock1 * arr[13] > money2 + stock2 * arr[13]) {
    cout << "BNP";
  }
  else if (money1 + stock1 * arr[13] < money2 + stock2 * arr[13]) {
    cout << "TIMING";
  }
  else {
    cout << "SAMESAME";
  }
}
