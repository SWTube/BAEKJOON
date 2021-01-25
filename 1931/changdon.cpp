#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	vector<pair<int, int>> comfTime(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> comfTime[i].second >> comfTime[i].first;
	}
	
	sort(comfTime.begin(), comfTime.end());
	
	int saveTime = 0, count = 0;
	
	for (int i = 0; i < N; i++)
	{
		if (saveTime <= comfTime[i].second)
		{
			saveTime = comfTime[i].first;
			count++;
		}
	}
	cout << count << "\n";

	return 0;
}