#include<iostream>
#include<string>
void reverse(std::string& s, int start, int end) {
	for (int i = start; i <= end; ++i) {
		if ((end - start) / 2 + start < i) {
			break;
		}
		char c = s[i];
		s[i] = s[end - i + start];
		s[end - i + start] = c;
	}
}
int main() {
	int start = 0, end = 0;
	bool isTag = false;
	std::string s;
	getline(std::cin, s);
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '<') {
			end = i - 1;
			if (start < end) {
				reverse(s, start, end);
			}
			isTag = true;
		}
		else if (s[i] == '>') {
			isTag = false;
			start = i + 1;
		}
		else if (s[i] == ' ') {
			if (!isTag) {
				end = i - 1;
				reverse(s, start, end);
				start = i + 1;
			}
		}
		if (i == s.size() - 1) {
			if (s[i] != '<' && s[i] != '>' && s[i] != ' ') {
				end = i;
				reverse(s, start, end);
			}
		}
	}
	std::cout << s;
    return 0;
}
