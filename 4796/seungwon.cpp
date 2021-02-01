#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  int l = 1, p = 1, v = 1;
  int i = 1;
  while (true) {
    cin >> l >> p >> v;
    if (l == 0 && p == 0 && v == 0) {
      break;
    }
    int ans = v / p * l + min(l, (v - v / p * p));
    cout << "Case " << i++ << ": " << ans << endl;

  }
}
