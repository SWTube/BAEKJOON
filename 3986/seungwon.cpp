#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans = 0;
  while (n--) {
    string str;
    cin >> str;
    stack<char> s;

    for (int i = 0; i < str.size(); i++) {
      if (!s.empty()) {
        if (s.top() == str[i]) {
          s.pop();
        }
        else {
          s.push(str[i]);
        }
      }
      else {
        s.push(str[i]);
      }
    }
    if (s.empty()) {
      ans += 1;
    }
  }
  cout << ans;
}
