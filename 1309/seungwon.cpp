#include<iostream>
using namespace std;
int arr[100001], n;
int main() {
  cin >> n;
  arr[1] = 3, arr[2] = 7;
  for (int i = 3; i <= n; i++)
    arr[i] = (arr[i - 1] * 2 + arr[i - 2]) % 9901;
  cout << arr[n];
}
