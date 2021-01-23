/*
���ڿ� S�� �־����� ��, �� ���ڿ����� �ܾ ���������� �Ѵ�.

����, ���ڿ� S�� �Ʒ��Ͱ� ���� ��Ģ�� ��Ų��.

���ĺ� �ҹ���('a'-'z'), ����('0'-'9'), ����(' '), Ư�� ����('<', '>')�θ� �̷���� �ִ�.
���ڿ��� ���۰� ���� ������ �ƴϴ�.
'<'�� '>'�� ���ڿ��� �ִ� ��� �����ư��鼭 �����ϸ�, '<'�� ���� �����Ѵ�. 
��, �� ������ ������ ����.
�±״� '<'�� �����ؼ� '>'�� ������ ���̰� 3 �̻��� �κ� ���ڿ��̰�, '<'�� '>' ���̿���
���ĺ� �ҹ��ڿ� ���鸸 �ִ�. �ܾ�� ���ĺ� �ҹ��ڿ� ���ڷ� �̷���� �κ� ���ڿ��̰�,
�����ϴ� �� �ܾ�� ���� �ϳ��� �����Ѵ�. �±״� �ܾ �ƴϸ�, �±׿� �ܾ� ���̿��� 
������ ����.

*/

#include <iostream>
#include <string>

using namespace std;

void swap(char& a, char& b);

int main() {
	
	string S;
	getline(cin, S);

	int index = S.size() - 1;
	int start_index;
	int last_index;
	int stride;

	for (int i = 0; i <= index; ++i) {

		if (S[i] == '<') { //��ȣ
			while (S[i] != 62) {
				++i;
			}
		}

		else if (S[i] == ' ') { // ����
			continue;
		}

		else {
			
			int start_index = i;
			bool last = false;
			while (S[i] != ' ' && S[i] != '<') {
				if (i == index) {
					last = true;
					break;
				}
				else {
					++i;
				}
			}

			if ((S[i] == ' ') && last == false) {
				--i;
			}

			if ((S[i] == '<') && last == false) {
				--i;
			}
			
			int last_index = i;
			int stride = last_index - start_index;

			for (int j = 0; j < (stride + 1) / 2; ++j) {
				swap(S[start_index + j], S[last_index - j]);
			}
			
		}

	}

	cout << S;

	return 0;
}

void swap(char& a, char& b) {
	char temp = a;
	a = b;
	b = temp;
}