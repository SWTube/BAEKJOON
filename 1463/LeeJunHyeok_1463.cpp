/*
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.

정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다.
연산을 사용하는 횟수의 최솟값을 출력하시오.


첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 정수 N이 주어진다.

첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.
*/

// i == 1~1,000,000 까지의 숫자.
// arr[i] ==> i라는 숫자는 몇 번 연산해야 하는가?

// 전역변수 선언시 배열은 0으로 초기화, 지역변수 선언시 배열은 쓰레기값으로 초기화

#include <iostream>

using namespace std;

int arr[1000001];

int main() {

	int x;

	cin >> x;
	
	arr[1] = 0;

	for (int i = 2; i < 1000001; ++i) 
	{
		if (i % 3 == 0 && i % 2 == 0) {
			if (arr[i / 3] < arr[i / 2] || arr[i / 3] < arr[i - 1]) {
				arr[i] = arr[i / 3] + 1;
			}

			else if (arr[i / 2] < arr[i / 3] || arr[i / 2] < arr[i - 1]) {
				arr[i] = arr[i / 2] + 1;
			}

			else if (arr[i / 3] > arr[i / 2]) {
				arr[i] = arr[i / 2] + 1;

			}
			else if (arr[i / 3] > arr[i - 1]) {
				arr[i] = arr[i - 1] + 1;
			}
		}

		else if (i % 3 == 0) {
			if (arr[i - 1] < arr[i / 3]) {
				arr[i] = arr[i - 1] + 1;
			}
			else {
				arr[i] = arr[i / 3] + 1;
			}
		}
		
		else if (i % 2 == 0) {
			if (arr[i - 1] < arr[i / 2]) {
				arr[i] = arr[i - 1] + 1;
			}
			else {
				arr[i] = arr[i / 2] + 1;
			}
		}

		else {
			arr[i] = arr[i - 1] + 1;
		}
	}

	cout << arr[x];

	return 0;
}