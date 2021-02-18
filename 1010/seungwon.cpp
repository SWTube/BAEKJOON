#include<iostream>
using namespace std;
int arr[31][31];
int main() {
  for (int i = 1; i <= 30; i++) {
    arr[i][i] = 1;
    for (int j = i + 1; j <= 30; j++) {
      if (i == 1) {
        arr[i][j] = arr[i][j - 1] + 1;
        continue;
      }
      arr[i][j] = arr[i][j - 1] + arr[i - 1][j - 1];
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    cout << arr[n][m] << endl;
  }
}
