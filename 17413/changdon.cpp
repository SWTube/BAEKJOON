#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S = "";

    getline(cin, S);
    S += '\n';

    stack<char> st;
    bool check = false;

    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '<')
        {
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }
            cout << "<";
            check = true;
        }
        else if (S[i] == '>')
        {
            cout << ">";
            check = false;
        }
        else if (check)
        {
            cout << S[i];
        }

        else if (S[i] == ' ' || S[i] == '\n')
        {
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }
            cout << " ";
        }
        else st.push(S[i]);
    }

    return 0;
}