// https://atcoder.jp/contests/typical-algorithm/tasks/typical_algorithm_c

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1LL << 60;

int main() {
    int N;
    cin >> N;

    vector A(N, vector<ll>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    vector dp(1 << N, vector<ll>(N, INF));

    dp[1 << 0][0] = 0;

    for (int i = 0; i < (1 << N); ++i) {
        for (int j = 0; j < N; ++j) {
            if ((i & (1 << j)) == 0) {
                continue;
            }

            for (int k = 0; k < N; ++k) {
                if (k == j) {
                    continue;
                }

                if ((i & (1 << k)) == 0) {
                    continue;
                }

                dp[i][j] = min(dp[i][j], dp[i & ~(1 << j)][k] + A[k][j]);
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i < N; ++i) {
        ans = min(ans, dp[(1 << N) - 1][i] + A[i][0]);
    }

    cout << ans << endl;

    return 0;
}
