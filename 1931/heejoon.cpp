#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct timeinfo {
	int startime;
	int endtime;
};

// 종료시간 비교
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
	
	// 회의 사용 정보가 들어있는 벡터 생성
	for(unsigned i = 0; i< N;i++){
		cin >> starttime >> endtime;
		reserve[i].startime = starttime;
		reserve[i].endtime = endtime;
	}

	/*
	********회의 종료 시간이 빠른 것부터! 해야 선택할 수 있는 경우의 수가 많아져서 최대 회의 가능!!*********
	*/
	sort(reserve.begin(), reserve.end(), endtimecompare);

	// Check 작은 것부터
	int end = 0; // 초기 회의 종료 시간
	int cnt = 0; // 회의 수
	for (unsigned i = 0; i < N; i++) {

		if (end <= reserve[i].startime) {
			end = reserve[i].endtime; // 회의 종료 시간 입력
			cnt++;
		}
	}
	cout << cnt;
}
/* solved!
* O(N2)이 되므로 swap을 이용한 정렬보다는 sort함수를 이용해서 하는 것이 현명할듯
* 회의 종료시간이 이른 것부터 경우의 수가 많이 생긴다는 점이 point!
*/