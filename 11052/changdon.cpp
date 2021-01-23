#include <iostream>
#include <algorithm>

int dp[1000];
int p[10000];

int main()
{
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; i++)
		std::cin >> p[i];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			dp[i] = std::max(dp[i], dp[i - j] + p[j]);

	std::cout << dp[N];

	return 0;
}