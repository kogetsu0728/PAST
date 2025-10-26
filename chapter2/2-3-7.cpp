// https://atcoder.jp/contests/dp/tasks/dp_o

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    vector A(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    vector<ll> dp(1 << N);
    dp[0] = 1;

    for (int i = 1; i < (1 << N); ++i) {
        int c = __builtin_popcount(i);

        for (int j = 0; j < N; ++j) {
            if (((i >> j) & 1) == 0) {
                continue;
            }

            if (A[c - 1][j] == 0) {
                continue;
            }

            dp[i] = (dp[i] + dp[i & ~(1 << j)]) % MOD;
        }
    }

    cout << dp[(1 << N) - 1] << endl;

    return 0;
}
