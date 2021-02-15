#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
int input[100001];
pair<int, int> tree[400004];
pair<int, int> ans;
pair<int, int> find(int node, int start, int end, int left, int right) {
  if (start <= left && right <= end) {
    return tree[node];
  }
  else if (end < left || start > right) {
    return ans;
  }
  pair<int, int> a = find(node * 2, start, end, left, (left + right) / 2);
  pair<int, int> b = find(node * 2 + 1, start, end, (left + right) / 2 + 1, right);
  return make_pair(min(a.first, b.first), max(a.second, b.second));
}
pair<int, int> makeTree(int node, int start, int end) {
  if (start == end) {
    tree[node].first = input[start];
    tree[node].second = input[start];
    return tree[node];
  }
  pair<int, int> a = makeTree(node * 2, start, (start + end) / 2);
  pair<int, int> b = makeTree(node * 2 + 1, (start + end) / 2 + 1 , end);
  tree[node].first = min(a.first, b.first);
  tree[node].second = max(a.second, b.second);
  return tree[node];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> input[i];
  }

  pair<int, int> make = makeTree(1, 1, n);

  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    ans = make_pair(min(input[a], input[b]), max(input[a], input[b]));
    ans = find(1, a, b, 1, n);
    cout << ans.first << " " << ans.second << "\n";
  }
}
