#include<iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr1[6] = { 500, 300, 200, 50, 30, 10 };
  int arr2[6] = { 1, 2, 3, 4, 5, 6 };
  int brr1[5] = { 512, 256, 128, 64, 32 };
  int brr2[5] = {1, 2, 4, 8, 16 };
  while (n--) {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    int i = 0;
    while (a > 0) {
      if (i >= 6) break;
      a -= arr2[i++];
    }
    if (i > 0 && a <= 0) ans += arr1[i - 1];
    i = 0;
    while (b > 0) {
      if (i >= 5) break;
      b -= brr2[i++];
    }
    if (i > 0 && b <= 0) ans += brr1[i - 1];
    cout << ans * 10000 << endl;
  }
}
