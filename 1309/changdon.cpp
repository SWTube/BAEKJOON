#include <iostream>
#include <algorithm>

int dp[100000];

int main()
{
	int N;
	std::cin >> N;

	dp[0] = 1;
	dp[1] = 3;

	for (int i = 2; i <= N; i++)
		dp[i] = (2 * dp[i - 1] + dp[i - 2]) % 9901;

	std::cout << dp[N];

	return 0;
}