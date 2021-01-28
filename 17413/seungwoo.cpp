#include <iostream>
#include <stack>
#include <queue>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	std::string str;
	std::stack<char> st;
	std::queue<char> q;

	getline(std::cin, str);
	str += '\n';

	for (int i = 0; i < str.length(); i++) {

		if (str[i] == '<') {
			while (str[i] != '>') {
				if (str[i] == '\n')
					break;
				q.push(str[i]);
				i++;
			}

			while (!q.empty()) {
				std::cout << q.front();
				q.pop();
			}

			std::cout << '>';
		}
		
		else if (str[i] == ' ') {
			std::cout << ' ';
		}

		else {
			while (str[i] != '<' && str[i] != ' ') {
				if (str[i] == '\n')
					break;
				st.push(str[i]);
				i++;
			}

			while (!st.empty()) {
				std::cout << st.top();
				st.pop();
			}

			if (str[i] == '\n')
				break;

			i--;
		}
	}

	return 0;
}
