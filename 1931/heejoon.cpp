#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct timeinfo {
	int startime;
	int endtime;
};

// ����ð� ��
bool endtimecompare(timeinfo t1, timeinfo t2) {
	if (t1.endtime == t2.endtime)
		return t1.startime < t2.startime;
	else
		return t1.endtime < t2.endtime;
}


int main() {
	unsigned int N;
	cin >> N;
	int starttime, endtime;
	vector<timeinfo> reserve(N);
	
	// ȸ�� ��� ������ ����ִ� ���� ����
	for(unsigned i = 0; i< N;i++){
		cin >> starttime >> endtime;
		reserve[i].startime = starttime;
		reserve[i].endtime = endtime;
	}

	/*
	********ȸ�� ���� �ð��� ���� �ͺ���! �ؾ� ������ �� �ִ� ����� ���� �������� �ִ� ȸ�� ����!!*********
	*/
	sort(reserve.begin(), reserve.end(), endtimecompare);

	// Check ���� �ͺ���
	int end = 0; // �ʱ� ȸ�� ���� �ð�
	int cnt = 0; // ȸ�� ��
	for (unsigned i = 0; i < N; i++) {

		if (end <= reserve[i].startime) {
			end = reserve[i].endtime; // ȸ�� ���� �ð� �Է�
			cnt++;
		}
	}
	cout << cnt;
}
/* solved!
* O(N2)�� �ǹǷ� swap�� �̿��� ���ĺ��ٴ� sort�Լ��� �̿��ؼ� �ϴ� ���� �����ҵ�
* ȸ�� ����ð��� �̸� �ͺ��� ����� ���� ���� ����ٴ� ���� point!
*/