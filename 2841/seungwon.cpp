#include<iostream>
#include<stack>
using namespace std;
stack<int> s[7];
int main() {
  int n, p;
  cin >> n >> p;
  int x = 0;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (!s[a].empty()) {
      while (!s[a].empty() && s[a].top() > b) {
        s[a].pop();
        x++;
      }
      if (!s[a].empty()) {
        if (s[a].top() != b) {
          s[a].push(b);
          x++;
        }
      }
      else {
        s[a].push(b);
        x++;
      }

    }
    else {
      s[a].push(b);
      x++;
    }
  }
  cout << x;
}
