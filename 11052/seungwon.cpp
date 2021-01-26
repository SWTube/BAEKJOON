#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[1001];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    arr[i] = a;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      arr[i] = max(arr[i], arr[i - j] + arr[j]);
    }
  }
  cout << arr[n];
}
