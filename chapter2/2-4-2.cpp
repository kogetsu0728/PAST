// https://atcoder.jp/contests/dp/tasks/dp_m

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector dp(N + 1, vector<ll>(K + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            dp[i][j] += dp[i - 1][j];

            if (j > 0) {
                dp[i][j] += dp[i][j - 1];
            }

            if (j - A[i - 1] > 0) {
                dp[i][j] += MOD - dp[i - 1][j - A[i - 1] - 1];
            }

            dp[i][j] %= MOD;
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}
