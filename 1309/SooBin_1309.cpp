#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    int devide = 9901;
    
    int *S = new int[num+1];
    S[0] = 1;
    S[1] = 3;
    for(int i =2; i< num+1;i++){
        S[i] = (S[i-1]*2 + S[i-2])%devide;

    }
    cout << S[num];

}
