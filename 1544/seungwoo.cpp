#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

std::string makeString(std::queue<char>& q) {
	std::string str = "";
	for (int i = 0; i < q.size(); i++) {
		str += q.front();
		q.push(q.front());
		q.pop();
	}

	return str;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	std::vector<std::string> v;

	for (int i = 0; i < N; i++) {
		std::string s; std::cin >> s;
		
		if (v.size() == 0) {
			v.push_back(s);
		}
		else {
			std::queue<char> q;

			for (int k = 0; k < s.size(); k++) {
				q.push(s[k]);
			}

			bool issame = false;

			for (int j = 0; j < v.size(); j++) {
				for (int k = 0; k < s.size(); k++) {
					std::string compstr = makeString(q);

					if (compstr == v[j]) {
						issame = true;
						break;
					}
					
					q.push(q.front());
					q.pop();
				}

				if (issame) {
					break;
				}
			}

			if (!issame) {
				v.push_back(s);
			}
		}
	}

	std::cout << v.size() << "\n";

	return 0;
}