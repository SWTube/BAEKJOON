#include <iostream>
#include <string>
#include <stack>
using namespace std;

string words;
stack<char> reverse_stack; // 순서를 바꿀 문자들을 저장

void print_stack() {
	while (!reverse_stack.empty()) {
		cout << reverse_stack.top();
		reverse_stack.pop();
	}
}

int main() {
	getline(cin, words); // 공백도 입력받음

	bool flag = false; // 태그 여부 판별
	for (char ch : words) {

		// < > 태그 처리
		if (ch == '<') {
			print_stack();
			cout << ch;
			flag = true;
		}
		else if (ch == '>') {
			cout << ch;
			flag = false;
		}

		// < > 안쪽은 무조건 그대로 출력
		else if (flag) {
			cout << ch;
		}

		// < > 바깥쪽
		else {
			if (ch == ' ') { // 공백 나오면 역순 출력
				print_stack();
				cout << ch;
			}
			else { // 공백이 아닌 경우 stack에 저장
				reverse_stack.push(ch);
			}
		}
	}

	// stack에 남아있는 문자 모두 출력
	print_stack();
	return 0;
}