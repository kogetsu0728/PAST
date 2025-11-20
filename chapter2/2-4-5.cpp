// https://atcoder.jp/contests/tdpc/tasks/tdpc_house

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;

int main() {
    ll H;
    cin >> H;

    int R;
    cin >> R;

    vector G(R, vector<int>(R));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < R; ++j) {
            cin >> G[i][j];
        }
    }

    vector m(R, vector<ll>(R));
    for (int s = 0; s < R; ++s) {
        vector dp(1 << R, vector<ll>(R));
        dp[1 << s][s] = 1;

        for (int i = 0; i < (1 << R); ++i) {
            for (int j = 0; j < R; ++j) {
                if (((i >> j) & 1) == 0) {
                    continue;
                }

                for (int k = 0; k < R; ++k) {
                    if (((i >> k) == 0) || j == k) {
                        continue;
                    }

                    if (G[k][j] == 0) {
                        continue;
                    }

                    dp[i][j] += dp[i & ~(1 << j)][k];

                    if (dp[i][j] >= MOD) {
                        dp[i][j] -= MOD;
                    }
                }
            }
        }

        for (int i = 0; i < (1 << R); ++i) {
            for (int j = 0; j < R; ++j) {
                m[s][j] += dp[i][j];

                if (m[s][j] >= MOD) {
                    m[s][j] -= MOD;
                }
            }
        }
    }

    auto mul = [&](vector<vector<ll>>& a, vector<vector<ll>>& b) -> vector<vector<ll>> {
        vector res(R, vector<ll>(R));

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < R; ++j) {
                for (int k = 0; k < R; ++k) {
                    res[i][j] += a[i][k] * b[k][j];
                    res[i][j] %= MOD;
                }
            }
        }

        return res;
    };

    auto pow = [&](vector<vector<ll>> a, ll p) -> vector<vector<ll>> {
        vector res(R, vector<ll>(R));

        for (int i = 0; i < R; ++i) {
            res[i][i] = 1;
        }

        while (p > 0) {
            if ((p & 1) == 1) {
                res = mul(res, a);
            }

            a = mul(a, a);
            p >>= 1;
        }

        return res;
    };

    m = pow(m, H);

    cout << m[0][0] << endl;

    return 0;
}
