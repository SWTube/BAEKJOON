#include <iostream>
#include <string>
#include <stack>
using namespace std;

string words;
stack<char> reverse_stack; // ������ �ٲ� ���ڵ��� ����

void print_stack() {
	while (!reverse_stack.empty()) {
		cout << reverse_stack.top();
		reverse_stack.pop();
	}
}

int main() {
	getline(cin, words); // ���鵵 �Է¹���

	bool flag = false; // �±� ���� �Ǻ�
	for (char ch : words) {

		// < > �±� ó��
		if (ch == '<') {
			print_stack();
			cout << ch;
			flag = true;
		}
		else if (ch == '>') {
			cout << ch;
			flag = false;
		}

		// < > ������ ������ �״�� ���
		else if (flag) {
			cout << ch;
		}

		// < > �ٱ���
		else {
			if (ch == ' ') { // ���� ������ ���� ���
				print_stack();
				cout << ch;
			}
			else { // ������ �ƴ� ��� stack�� ����
				reverse_stack.push(ch);
			}
		}
	}

	// stack�� �����ִ� ���� ��� ���
	print_stack();
	return 0;
}