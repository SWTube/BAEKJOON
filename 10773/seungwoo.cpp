#include <iostream>
#include <stack>

int main() {
	int K; std::cin >> K;

	int sum = 0;
	std::stack<int> st;

	for (int i = 0; i < K; i++) {
		int num; std::cin >> num;

		if (num != 0) {
			st.push(num);
			sum += num;
		}
		else {
			sum -= st.top();
			st.pop();
		}
	}

	std::cout << sum << "\n";

	return 0;
}