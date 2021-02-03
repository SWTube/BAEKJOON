#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main() {
  string input;
  cin >> input;
  stack<string> s;
  string num = "";
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == '-') {
      if (num != "") {
        s.push(num);
        num = "";
      }
      s.push("-");
    }
    else if (input[i] == '+') {
      if (num != "") {
        s.push(num);
        num = "";
      }
      s.push("+");
    }
    else {
      num += input[i];
    }
  }
  if (num != "") {
    s.push(num);
  }

  int ans = 0;
  int imsi = 0;
  while(!s.empty()) {
    if (s.top() == "-") {
      ans -= imsi;
      imsi = 0;
      s.pop();
    }
    else if (s.top() == "+") {
      s.pop();
      continue;
    }
    else {
      imsi += stoi(s.top());
      s.pop();
    }
  }
  ans += imsi;
  cout << ans;
}
