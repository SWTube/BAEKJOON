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

		if (!over) { // 상한가 이하의 값들만 price 대입
			Input.push_back(make_pair(name, price));
		}
		over = false;
	}
	
	int size = Input.size();
	vector<int> pricelist(100001,0); // 가격의 중복 횟수가 적혀있는 list
	for (int i = 0; i < size; i++) {
		pricelist[Input[i].second]++;
	}

	
	// 최소 중복 횟수 찾기
	int minnum = 1000000;
	for (int i = 1; i < 100001; i++) {
		if ( minnum > 0 && pricelist[i]>0) {
			minnum = min(minnum, pricelist[i]);
		}
	}

	// 최소 중복 횟수만큼만 가지고 있는 price들을 list삽입
	vector<int> result;
	for (int i = 1; i < 100001; i++) {
		if (pricelist[i] == minnum)
			result.push_back(i);
	}

	sort(result.begin(), result.end());

	// 최소 중복 횟수 중 최솟값을 갖는 price를 이용하여 이름 찾기!
	for (int i = 0; i < Input.size(); i++) {
		if (Input[i].second == result[0]) {
			cout << Input[i].first << ' ' << Input[i].second;
			break;
		}
	}

	return 0;
}
