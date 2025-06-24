// https://atcoder.jp/contests/typical90/tasks/typical90_h

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;
const string ATC = "atcoder";

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<ll> dp(ATC.length() + 1), ep(ATC.length() + 1);
    dp[0] = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= ATC.length(); ++j) {
            ep[j] = dp[j];
        }

        for (int j = 0; j < ATC.length(); ++j) {
            if (S[i] == ATC[j]) {
                ep[j + 1] = (ep[j + 1] + dp[j]) % MOD;
            }
        }

        swap(dp, ep);
    }

    cout << dp[ATC.length()] << "\n";

    return 0;
}
