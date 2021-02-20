#include<iostream>
#include<vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  while (n--) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  int x;
  cin >> x;
  int min = 99999, max = 0;
  for (const auto& index : v) {
    if (index == x) {
      cout << 0;
      return 0;
    }
    else if (index < x) {
      max = (index > max) ? index : max;
    }
    else if(index > x){
      min = (index < min) ? index : min;
    }
  }
  int cnt = 0;
  for (int i = max + 1; i < min; i++) {
    for (int j = i + 1; j < min; j++) {
      if (i <= x && x <= j) {
        cnt += 1;
      }
    }
  }
  cout << cnt;
}
