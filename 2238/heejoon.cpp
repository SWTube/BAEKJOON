#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int U, N;
	cin >> U >> N;
	bool over = false;
	vector<pair<string, int>> Input;
	
	for (int i = 0; i < N; i++) {
		string name; int price;
		cin >> name >> price;
		if (price > U) over = true;

		if (!over) { // ���Ѱ� ������ ���鸸 price ����
			Input.push_back(make_pair(name, price));
		}
		over = false;
	}
	
	int size = Input.size();
	vector<int> pricelist(100001,0); // ������ �ߺ� Ƚ���� �����ִ� list
	for (int i = 0; i < size; i++) {
		pricelist[Input[i].second]++;
	}

	
	// �ּ� �ߺ� Ƚ�� ã��
	int minnum = 1000000;
	for (int i = 1; i < 100001; i++) {
		if ( minnum > 0 && pricelist[i]>0) {
			minnum = min(minnum, pricelist[i]);
		}
	}

	// �ּ� �ߺ� Ƚ����ŭ�� ������ �ִ� price���� list����
	vector<int> result;
	for (int i = 1; i < 100001; i++) {
		if (pricelist[i] == minnum)
			result.push_back(i);
	}

	sort(result.begin(), result.end());

	// �ּ� �ߺ� Ƚ�� �� �ּڰ��� ���� price�� �̿��Ͽ� �̸� ã��!
	for (int i = 0; i < Input.size(); i++) {
		if (Input[i].second == result[0]) {
			cout << Input[i].first << ' ' << Input[i].second;
			break;
		}
	}

	return 0;
}
