// https://atcoder.jp/contests/past202004-open/tasks/past202004_k

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 1LL << 60;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<ll> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }

    vector<ll> D(N);
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }

    vector dp(N + 1, vector<ll>(N, INF));
    dp[0][0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + D[i]);

            if (S[i] == '(') {
                if (j + 1 < N) {
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
                }

                if (j - 1 >= 0) {
                    dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + C[i]);
                }
            } else {
                if (j + 1 < N) {
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + C[i]);
                }

                if (j - 1 >= 0) {
                    dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j]);
                }
            }
        }
    }

    cout << dp[N][0] << "\n";

    return 0;
}
