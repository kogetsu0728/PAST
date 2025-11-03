// https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_d

#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1 << 30;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        --A[i];
    }

    vector csum(M, vector<int>(N + 1));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            csum[i][j + 1] = csum[i][j] + (A[j] == i);
        }
    }

    vector<int> dp(1 << M, INF);
    dp[0] = 0;

    for (int i = 1; i < (1 << M); ++i) {
        int r = 0;
        for (int j = 0; j < M; ++j) {
            if ((i >> j) & 1) {
                r += csum[j][N];
            }
        }

        for (int j = 0; j < M; ++j) {
            if (((i >> j) & 1) == 0) {
                continue;
            }

            int l = r - csum[j][N];

            dp[i] = min(dp[i], dp[i & ~(1 << j)] + ((r - l) - (csum[j][r] - csum[j][l])));
        }
    }

    cout << dp[(1 << M) - 1] << endl;

    return 0;
}
