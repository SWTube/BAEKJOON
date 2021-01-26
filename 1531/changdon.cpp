#include <iostream>

int main(void)
{
	int arr[101][101] = { 0, };
	int x1, y1, x2, y2;
	int sum = 0;
	
	int N, M;
	std::cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		std::cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x <= x2; x++)
		{
			for (int y = y1; y <= y2; y++)
			{
				arr[x][y]++;
			}
		}
	}

	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (arr[i][j] > M) sum++;
		}
	}

	std::cout << sum;

	return 0;
}