#include <iostream>

int dp[31];

int main()
{
    int N;
    std::cin >> N;

    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= N; i++)
    {
        dp[i] = dp[i - 2] * 3;
        for (int j = 4; j <= i; j += 2)
        {
            dp[i] += dp[i - j] * 2;
        }
    }

    std::cout << dp[N];
    return 0;
}