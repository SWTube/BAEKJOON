#include<iostream>
using namespace std;
int arr[31];
int main() {
  int n;
  cin >> n;
  arr[2] = 3;
  for (int i = 4; i <= n; i += 2) {
    arr[i] = arr[i - 2] * 3;
    for (int j = i - 4; j >= 2; j -= 2) {
      arr[i] += arr[j] * 2;
    }
    arr[i] += 2;
  }
  cout << arr[n];
}
