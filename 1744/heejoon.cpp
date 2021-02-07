#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N+1);
	vector<int> pos; // ���
	vector<int> neg; // ����
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (v[i] > 0) { pos.push_back(v[i]); }
		else if(v[i]==0){ pos.push_back(v[i]); neg.push_back(v[i]);}
		else { neg.push_back(v[i]); }
	}

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	int sum = 0;

	// pos�� ���ϱ�
	if (pos.size() % 2 == 0) { // pos size�� ¦��
		for (int i = pos.size()-1 ; i > 0; i -= 2) {
			if (pos[i] * pos[i - 1] > pos[i] + pos[i-1]) {
				sum += pos[i] * pos[i - 1];
			}
			else {
				sum += (pos[i] + pos[i - 1]);
			}
		}
	}
	else { // pos size�� Ȧ��
		for (int i = pos.size() - 1; i > 0; i -= 2) {
			if (pos[i] * pos[i - 1] > pos[i] + pos[i - 1]) {
				sum += pos[i] * pos[i - 1];
			}
			else {
				sum += (pos[i] + pos[i - 1]);
			}
		}
		sum += pos[0];
	}

	// neg�� ���ϱ�
	if (neg.size() % 2 == 0) { // neg size�� ¦��
		for (int i = 0; i < neg.size(); i += 2) {
			sum += neg[i] * neg[i + 1];
		}
	}
	else { // pos size�� Ȧ��
		for (int i = 0; i < neg.size()-1; i += 2) {
			sum += neg[i] * neg[i + 1];
		}
		sum += neg[neg.size() - 1];
	}


	cout << sum;
}

/*
* 5
* -2 0 2 4 5
* 
* 
*/