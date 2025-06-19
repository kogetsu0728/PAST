// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, W;
    cin >> N >> W;

    vector<pair<int, ll>> I(N);
    for (int i = 0; i < N; ++i) {
        int w;
        cin >> w;

        ll v;
        cin >> v;

        I[i] = make_pair(w, v);
    }

    vector dp(N + 1, vector<ll>(W + 1, -1));
    dp[0][0] = 0;

    for (int i = 0; i < N; ++i) {
        auto [w, v] = I[i];

        for (int j = 0; j <= W; ++j) {
            if (dp[i][j] == -1) {
                continue;
            }

            if (j + w <= W) {
                dp[i + 1][j + w] = max(dp[i + 1][j + w], dp[i][j] + v);
            }

            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }

    ll ans = 0;
    for (int i = 0; i <= W; ++i) {
        ans = max(ans, dp[N][i]);
    }

    cout << ans << "\n";

    return 0;
}
