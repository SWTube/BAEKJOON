#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int j = 0; j < n; j++) {
      int a, b;
      cin >> a >> b;
      v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    int minNum;
    int ans = 0;
    for (int j = 0; j < n; j++) {
      if (j == 0) {
        minNum = v[j].second;
        ++ans;
        continue;
      }
      if (minNum > v[j].second) {
        ++ans;
      }
      minNum = min(minNum, v[j].second);
    }
    cout << ans << endl;
  }
}
