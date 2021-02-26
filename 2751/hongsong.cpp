#include <iostream>
using namespace std;

void merge(int* data, int p, int q, int r, int len, int* tmp){
    int i = p, j = q+1, k = p;
    while(i<=q && j <= r){
        if(data[i] <= data[j])
            tmp[k++] = data[i++];
        else
            tmp[k++] = data[j++];
    }
    while(i<=q){tmp[k++] = data[i++];}
    while(j<=r){tmp[k++] = data[j++];}
    for(int a=p; a<=r; a++){ data[a] = tmp[a];}
}

void mergeSort(int* data, int p, int r, int len, int* tmp){
    int q;
    if(p<r){
        q = (p+r)/2;
        mergeSort(data,p,q,len,tmp);
        mergeSort(data,q+1,r,len,tmp);
        merge(data,p,q,r,len,tmp);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	cin >> n;
	int arr[1000001],tmp[1000001];
	for(int i=0; i<n; i++)
		cin >> arr[i];
    mergeSort(arr,0,n-1,n,tmp);
    for(int i=0; i<n; i++){
        cout << arr[i] << "\n";
    }
    return 0;
}