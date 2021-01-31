#include<iostream>
#include<algorithm>
using namespace std;
int arr[10001][3];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    if (i == 1) {
      arr[i][0] = a;
      arr[i][1] = a;
      arr[i][2] = 0;
    }
    else {
      arr[i][0] = arr[i - 1][1] + a;
      arr[i][1] = max(arr[i - 2][0], arr[i - 1][2]) + a;
      arr[i][2] = max(max(arr[i - 1][0], arr[i - 1][1]), arr[i - 1][2]);
    }
  }
  cout << max(max(arr[n][0], arr[n][1]), arr[n][2]);
}
