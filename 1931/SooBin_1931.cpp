#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(vector<int> a, vector<int> b) {
    if (a[1] == b[1]) {
        return a[0] < b[0];
    }
    else return a[1] < b[1];
}

int main() {
    int num = 0;
    cin >> num;
    vector<vector<int>> S;
    int maxTime = 0;

    for (int i = 0; i < num; i++) {
        vector<int> cur(3, 0);
        cin >> cur[0] >> cur[1];
        if (maxTime < cur[1]) maxTime = cur[1];
        S.push_back(cur);

    }
    sort(S.begin(), S.end(), compare);

    int answer = 1;
    int endTime = S[0][1];
    
    for (int i = 1; i < num; i++) {
        if (S[i][0] >= endTime) {
            endTime = S[i][1];
            answer++;
        }
    }
    cout << answer;
}