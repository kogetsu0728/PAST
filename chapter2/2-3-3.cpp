// https://atcoder.jp/contests/pastbook2022/tasks/pastbook2022_b

#include <bits/stdc++.h>
using namespace std;

constexpr int INF = INT_MAX / 2;

int main() {
    int M, N;
    cin >> M >> N;

    string S, T;
    cin >> S >> T;

    vector dp(M + 1, vector<int>(N + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i <= M; ++i) {
        for (int j = 0; j <= N; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }

            int a = INF, b = INF, c = INF;

            if (i - 1 >= 0 && j - 1 >= 0) {
                a = dp[i - 1][j - 1] + (S[i - 1] != T[j - 1]);
            }

            if (i - 1 >= 0) {
                b = dp[i - 1][j] + 1;
            }

            if (j - 1 >= 0) {
                c = dp[i][j - 1] + 1;
            }

            dp[i][j] = min({a, b, c});
        }
    }

    cout << dp[M][N] << "\n";

    return 0;
}
