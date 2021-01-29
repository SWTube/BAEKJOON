/*
알파벳 소문자로만 이루어진 단어 S가 주어진다.
각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int alphabet[] = { -1,-1,-1,-1,-1,
                    -1,-1,-1,-1,-1,
                    -1,-1,-1,-1,-1,
                    -1,-1,-1,-1,-1,
                    -1,-1,-1,-1,-1,
                    -1 };
    string input;
    cin >> input;
    int aNum = (int)'a';
    for (int i = 0; i < input.length(); i++) {
        int seat = (int)input[i] -aNum;
        if(alphabet[seat] == -1) alphabet[seat] = i;

    }
    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << " ";
    }
}