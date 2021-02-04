#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		pair<char, int> pos, des;
		vector<pair<char, int>> posArray, desArray;
		cin >> pos.first >> pos.second >> des.first >> des.second;
		if (abs(pos.first + pos.second - des.first - des.second) % 2 == 1)
			cout << "Impossible" << "\n";
		else if (pos.first == des.first && pos.second == des.second)
			cout << "0 " << pos.first << " " << pos.second << "\n";
		else if (abs(pos.first - des.first) == abs(pos.second - des.second))
			cout << "1 " << pos.first << " " << pos.second << " " << des.first << " " << des.second << "\n";
		else {
			for (int j = 0; j < 8; j++) {
				for (int k = 0; k < 8; k++) {
					if (abs(pos.first - ('A' + k)) == abs(pos.second - (1 + j)))
						posArray.push_back({ char('A' + k), 1 + j });
					if (abs(des.first - ('A' + k)) == abs(des.second - (1 + j)))
						desArray.push_back({ char('A' + k), 1 + j });
				}
			}
			bool check = false;
			pair<char, int> tempPos;
			for (int j = 0; j < posArray.size() && !check; j++) {
				for (int k = 0; k < desArray.size(); k++) {
					if (desArray[k].first == posArray[j].first && desArray[k].second == posArray[j].second)
						tempPos = posArray[j];
				}
			}
			cout << "2 " << pos.first << " " << pos.second << " " << tempPos.first << " " << tempPos.second << " " << des.first << " " << des.second << "\n";
		}
	}
	return 0;
}