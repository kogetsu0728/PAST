// https://atcoder.jp/contests/pastbook2022/tasks/pastbook2022_a

#include <bits/stdc++.h>
using namespace std;

constexpr int INF = INT_MAX / 2;

int main() {
    int N;
    cin >> N;

    vector C(N + 1, vector<int>(N + 1));
    for (int i = 0; i < N + 1; ++i) {
        for (int j = 0; j < N + 1; ++j) {
            cin >> C[i][j];
        }
    }

    vector<int> dp(N + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i + 1] = min(dp[i + 1], dp[j] + C[j][i + 1]);
        }
    }

    cout << dp[N] << "\n";

    return 0;
}
