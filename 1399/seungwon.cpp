#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.first > b.first;
}
int main() {
  int n;
  cin >> n;
  vector<string> input;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    input.push_back(s);
  }
  vector<pair<int, int>> numValue(26, make_pair(0, 0));
  for (const auto& x : input) {
    for (int i = 0; i < x.size(); i++) {
      numValue[x[i] - 65].first += int(pow(10, x.size() - i - 1));
      numValue[x[i] - 65].second = x[i] - 65 + 1;
    }
  }
  sort(numValue.begin(), numValue.end(), cmp);
  int ans = 0;
  vector<int> numChar(26, 0);
  int numTop = 9;
  for (int i = 0; i < 26; i++) {
    if (numValue[i].second != 0) {
      numChar[numValue[i].second - 1] = numTop--;
    }
  }
  for (const auto& x : input) {
    for (int i = 0; i < x.size(); i++) {
      ans += numChar[x[i] - 65] * int(pow(10, x.size() - i - 1));
    }
  }
  cout << ans;
}
