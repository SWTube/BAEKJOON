#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;
int main() {
  int n;
  while (true) {
    cin >> n;
    if (n == 0) break;
    vector<pair<string, string>> v;
    while (n--) {
      string a;
      cin >> a;
      string b = a;
      for (int i = 0; i < a.size(); i++) {
        if ('a' <= a[i] && a[i] <= 'z') a[i] = a[i] - 'a' + 'A';
      }
      v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    cout << v[0].second << endl;
  }
}
