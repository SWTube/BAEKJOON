#include <iostream>

using namespace std;

int main() {
    unsigned long long T, N, M;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        unsigned long long bridge = 1;
        unsigned long long small, large;

        cin >> N >> M;

        if (M - N > N) {
            large = M - N;
            small = N;
        }
        else {
            large = N;
            small = M - N;
        }

        if (M != N) {
            for (unsigned long long j = M; j > large; --j) {
                bridge *= j;
            }
            for (unsigned long long k = 2; k <= small; ++k) {
                bridge /= k;
            }
        }
        cout << bridge << endl;
    }
    return 0;
}