#include<iostream>
using namespace std;
long long int arr[101][101];
int main() {
  int n;
  cin >> n;
  long long int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 9; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      else if (i == 0) {
        arr[i][j] = 1;
      }
      else if (j == 0) {
        arr[i][j] = (arr[i - 1][j + 1] % 1000000000);
      }
      else if (j == 9) {
        arr[i][j] = (arr[i - 1][j - 1] % 1000000000);
      }
      else {
        arr[i][j] = (arr[i - 1][j - 1] % 1000000000 + arr[i - 1][j + 1] % 1000000000) % 1000000000;
      }
      if (i == n - 1) {
        ans += arr[i][j] % 1000000000;
      }
    }
  }
  cout << ans % 1000000000;
}
