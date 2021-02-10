#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000
int minTree[MAX * 4], maxTree[MAX * 4];
int arr[100001];

int segmentTree(int start, int end, int node, int set){
	if(start == end){
		if(set){
			return maxTree[node] = arr[start];
		}
		else{
			return minTree[node] = arr[start];
		}
	}
	int mid = (start+end)/2;
	if(set)
		return maxTree[node] = max(segmentTree(start,mid,node*2,1),segmentTree(mid+1,end,node*2 +1,1));
	else
		return minTree[node] = min(segmentTree(start,mid,node*2,0),segmentTree(mid+1,end,node*2 +1,0));
}

int getNum(int start, int end, int node, int left, int right, int set){
	if(left > end || right < start){
	   if(set)
	        return 0;
	   else
	        return 1000000001;
	}
	
	if(left <= start && right >= end){
		if(set){
			return maxTree[node];
		}
		else
			return minTree[node];
	}
	int mid = (start+end)/2;
	if(set)
		return max(getNum(start,mid,node*2,left,right,1),getNum(mid+1,end,node*2 + 1,left,right,1));
	else
		return min(getNum(start,mid,node*2,left,right,0),getNum(mid+1,end,node*2 + 1,left,right,0));
}
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	segmentTree(0,n-1,1,0);
	segmentTree(0,n-1,1,1);
	for(int i=0; i<m; i++){
		int a,b;
		cin >> a >> b;
		cout << getNum(0,n-1,1,a-1,b-1,0) << " " << getNum(0,n-1,1,a-1,b-1,1) << "\n";
	}
	return 0;
}