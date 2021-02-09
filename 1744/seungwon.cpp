#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.first > b.first;
}
int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  int s = 0, e = v.size() - 1;
  int ans = 0;
  while (s  + 1 < e) {
    vector<pair<int, int>> imsi;
    imsi.push_back(make_pair(v[s], 1));
    imsi.push_back(make_pair(v[e], 2));
    imsi.push_back(make_pair(v[s] * v[s + 1], 3));
    imsi.push_back(make_pair(v[e] * v[e - 1], 4));

    sort(imsi.begin(), imsi.end(), cmp);
    switch (imsi[0].second) {
    case 1:
      ans += v[s++];
      break;
    case 2:
      ans += v[e--];
      break;
    case 3:
      ans += v[s] * v[s + 1];
      s += 2;
      break;
    case 4:
      ans += v[e] * v[e - 1];
      e -= 2;
      break;
    }
  }
  if (v.size() == 1) {
    ans = v[0];
  }
  else if (v.size() == 2) {
    ans += max(v[0] + v[1], v[0] * v[1]);
  }
  else {
    if (s != e) {
      ans += max(v[s] + v[e], v[s] * v[e]);
    }
    else {
      ans += v[s];
    }
  }
  cout << ans;
}
