#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, t, p,endTime[101] = {0,}, availableTime = 0;
	vector<pair<int, int>> time;
	cin >> n >> t >> p;
	for (int i = 0; i < t; i++) {
		int ent, exi;
		cin >> ent >> exi;
		time.push_back({(ent / 100) * 60 + ent % 100,(exi / 100) * 60 + exi % 100});
	}
	sort(time.begin(), time.end());
	int idx = 0;
	vector<int> checkSeat;
	for (int i = 540; i < 1260; i++) {
		auto iter = checkSeat.begin();
		while(iter != checkSeat.end()){
			if(endTime[*iter]==i){
				checkSeat.erase(iter);
			}
			else iter++;
		}
		for(; idx < t && time[idx].first == i;){
			if(time[idx].first == time[idx].second){
				idx++;
				continue;
			}
			if(checkSeat.empty()){
				checkSeat.push_back(1);
				endTime[1] = time[idx].second;
			}
			else{
                sort(checkSeat.begin(), checkSeat.end());
				int curIdx = -1, tempDis = checkSeat[0]-1;
				for(int i=0; i<checkSeat.size()-1; i++){
					if((checkSeat[i+1]-checkSeat[i])/2 > tempDis){
						curIdx = i;
						tempDis = (checkSeat[i+1] - checkSeat[i]) / 2;
					}
				}
				if(n - checkSeat.back() > tempDis){
					checkSeat.push_back(n);
					endTime[n] = time[idx].second;
				}
				else if(curIdx == -1){
					checkSeat.push_back(1);
					endTime[1] = time[idx].second;
				}
				else{
					int temp = checkSeat[curIdx] + tempDis; 
					checkSeat.push_back(temp);
					endTime[temp] = time[idx].second;
				}
			}
			idx++;
		}
		if(endTime[p] <= i)	 availableTime++;
	}
	cout << availableTime;	
}