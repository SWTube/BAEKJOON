#include <iostream>
#include <vector>

using namespace std;

bool* PrimeArray;

void Eratos(int n)
{
	if (n <= 1) return;
	for (int i = 2; i <= n; i++)
		PrimeArray[i] = true;
	for (int i = 2; i * i <= n; i++)
	{
		if (PrimeArray[i])
			for (int j = i * i; j <= n; j += i)
				PrimeArray[j] = false;
	}
}

void printCase(int num) {
	int a, b = 1;
	for (int i = 3; i < num; i += 2) {
		if (PrimeArray[i]) {
			a = i;
			b = num - a;
			if (PrimeArray[b]) {
				cout << num << " = " << a << " + " << b << "\n";
				return;
			}
		}
	}
	cout << "Goldbach's conjecture is wrong." << "\n";
}

int main() {
	int num = -1;
	int numbers[100001];
	int i = 0;
	int maxNum = 0;

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		cin >> num;
		if (num == 0) break;
		numbers[i] = num;
		if (maxNum < num) maxNum = num;
		i++;
	}
	PrimeArray = new bool[maxNum + 1];
	Eratos(maxNum);

	for (int j = 0; j < i; j++) {
		printCase(numbers[j]);
	}
	delete[] PrimeArray;
}