// https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_d

#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 10007;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<int> dp(1 << 3), ep(1 << 3);
    dp[1] = 1;

    for (int i = 0; i < N; ++i) {
        ep = vector<int>(1 << 3);

        for (int j = 0; j < (1 << 3); ++j) {
            if (S[i] == 'J' && ((j >> 0) & 1) == 0) {
                continue;
            }

            if (S[i] == 'O' && ((j >> 1) & 1) == 0) {
                continue;
            }

            if (S[i] == 'I' && ((j >> 2) & 1) == 0) {
                continue;
            }

            for (int k = 0; k < (1 << 3); ++k) {
                if ((j & k) == 0) {
                    continue;
                }

                ep[j] = (ep[j] + dp[k]) % MOD;
            }
        }

        swap(dp, ep);
    }

    int ans = 0;
    for (int i = 0; i < (1 << 3); ++i) {
        ans = (ans + dp[i]) % MOD;
    }

    cout << ans << "\n";

    return 0;
}
