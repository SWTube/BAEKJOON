#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans = -99999;
  int pre = -99999;
  while (n > 0) {
    int a;
    cin >> a;
    pre = max(a, pre + a);
    ans = max(ans, pre);
    --n;
  }
  cout << ans;

}
