// https://atcoder.jp/contests/abc183/tasks/abc183_e

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }

    vector dp(H, vector<ll>(W));
    vector csum(H, vector(W, vector<ll>(3)));

    dp[0][0] = 1;
    for (int i = 0; i < 3; ++i) {
        csum[0][0][i] = 1;
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }

            if (S[i][j] == '#') {
                continue;
            }

            if (i > 0) {
                ll c = csum[i - 1][j][0];

                dp[i][j] += c;
                csum[i][j][0] += c;
            }

            if (j > 0) {
                ll c = csum[i][j - 1][1];

                dp[i][j] += c;
                csum[i][j][1] += c;
            }

            if (i > 0 && j > 0) {
                ll c = csum[i - 1][j - 1][2];

                dp[i][j] += c;
                csum[i][j][2] += c;
            }

            dp[i][j] %= MOD;

            for (int k = 0; k < 3; ++k) {
                csum[i][j][k] = (dp[i][j] + csum[i][j][k]) % MOD;
            }
        }
    }

    cout << dp[H - 1][W - 1] << endl;

    return 0;
}
