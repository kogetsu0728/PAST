// https://atcoder.jp/contests/joi2016ho/tasks/joi2016ho_a

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1LL << 60;

int main() {
    int N, M;
    cin >> N >> M;

    ll K;
    cin >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector c(N, vector<ll>(M));
    for (int i = 0; i < N; ++i) {
        ll mi = INF, ma = -INF;

        for (int j = 0; j < M; ++j) {
            if (i - j < 0) {
                break;
            }

            mi = min(mi, A[i - j]);
            ma = max(ma, A[i - j]);

            c[i][j] = K + (j + 1) * (ma - mi);
        }
    }

    vector<ll> dp(N + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i - j < 0) {
                break;
            }

            dp[i + 1] = min(dp[i + 1], dp[i - j] + c[i][j]);
        }
    }

    cout << dp[N] << "\n";

    return 0;
}
