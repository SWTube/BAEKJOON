#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  m = min(m, n - m);
  long long int t = 5;
  long long int ans1 = 0;
  while (n >= t) {
    ans1 += n / t;
    t *= 5;
  }
  t = 5;
  while (n - m >= t) {
    ans1 -= (n - m) / t;
    t *= 5;
  }
  t = 5;
  while (m >= t) {
    ans1 -= m / t;
    t *= 5;
  }

  t = 2;
  long long int ans2 = 0;
  while (n >= t) {
    ans2 += n / t;
    t *= 2;
  }
  t = 2;
  while (n - m >= t) {
    ans2 -= (n - m) / t;
    t *= 2;
  }
  t = 2;
  while (m >= t) {
    ans2 -= m / t;
    t *= 2;
  }

  cout << min(ans2, ans1);
}
