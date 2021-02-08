#include<iostream>
#include<algorithm>
using namespace std;
int arr[100001];
int main() {
  int n;
  cin >> n;
  arr[1] = 1;
  for (int i = 2; i <= n; i++) {
    arr[i] = 999999999;
    for (int j = 1; j * j <= i; j++) {
      arr[i] = min(arr[i - j * j] + 1, arr[i]);
    }
  }
  cout << arr[n];
}
