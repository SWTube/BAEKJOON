#include<iostream>
#include<string>
using namespace std;

int main() {
  string str1;
  string str2;

  cin >> str1;
  cin >> str2;

  string s;

  for (int i = 0; i < str1.size(); i++) {
    s.push_back(str1[i]);
    if (s.size() >= str2.size()) {
      if (s.substr(s.size() - str2.size(), str2.size()) == str2) {
        s.replace(s.size() - str2.size(), str2.size(), "");
      }
    }
  }
  if (s.size() == 0) {
    cout << "FRULA";
  }
  else {
    cout << s;
  }
}
