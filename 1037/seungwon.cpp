#include<iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int min = 9999999, max = 0;
  while (n--) {
    int a;
    cin >> a;
    min = (min > a) ? a : min;
    max = (max < a) ? a : max;
  }
  cout << min * max;
}
