// https://atcoder.jp/contests/joisc2010/tasks/joisc2010_stairs

#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1234567;

int main() {
    int N, P;
    cin >> N >> P;

    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    vector<int> dp(N + 1);
    dp[0] = 1;

    int l = 0, h_s = 0, dp_s = 1;
    for (int r = 1; r <= N; ++r) {
        h_s += H[r - 1];

        while (h_s > P) {
            h_s -= H[l];

            dp_s -= dp[l];
            if (dp_s < 0) {
                dp_s += MOD;
            }

            ++l;
        }

        dp[r] = dp_s;

        dp_s += dp[r];
        if (dp_s >= MOD) {
            dp_s -= MOD;
        }
    }

    cout << dp[N] << endl;

    return 0;
}
