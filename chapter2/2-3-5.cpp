// https://atcoder.jp/contests/tdpc/tasks/tdpc_iwi

#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    int N = S.length();

    vector dp(N + 1, vector<int>(N + 1));

    for (int i = 2; i < N + 1; ++i) {
        for (int j = 0; j < N; ++j) {
            int k = j + i;

            if (k > N) {
                break;
            }

            if (S[j] == 'i' && S[k - 1] == 'i') {
                for (int l = j + 1; l < k - 1; ++l) {
                    if (S[l] != 'w') {
                        continue;
                    }

                    if (dp[j + 1][l] * 3 != l - (j + 1)) {
                        continue;
                    }

                    if (dp[l + 1][k - 1] * 3 != (k - 1) - (l + 1)) {
                        continue;
                    }

                    dp[j][k] = (k - j) / 3;

                    break;
                }
            }

            for (int l = j + 1; l < k - 1; ++l) {
                dp[j][k] = max(dp[j][k], dp[j][l] + dp[l][k]);
            }
        }
    }

    cout << dp[0][N] << endl;

    return 0;
}
