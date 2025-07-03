// https://atcoder.jp/contests/dp/tasks/dp_n

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1LL << 60;

int main() {
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> csum(N + 1);
    for (int i = 0; i < N; ++i) {
        csum[i + 1] = csum[i] + A[i];
    }

    vector dp(N, vector<ll>(N + 1, INF));
    for (int i = 0; i < N; ++i) {
        dp[i][i + 1] = 0;
    }

    for (int len = 2; len <= N; ++len) {
        for (int i = 0; i < N; ++i) {
            int j = i + len;

            if (j > N) {
                break;
            }

            for (int k = i + 1; k < j; ++k) {
                dp[i][j] =
                    min(dp[i][j], dp[i][k] + dp[k][j] + csum[j] - csum[i]);
            }
        }
    }

    cout << dp[0][N] << "\n";

    return 0;
}
