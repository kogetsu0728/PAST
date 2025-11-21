// https://atcoder.jp/contests/past202104-open/tasks/past202104_n

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, H;
    cin >> N >> H;

    vector<pair<ll, ll>> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin(), A.end(), [](auto a, auto b) -> bool {
        return a.first * b.second > b.first * a.second;
    });

    vector dp(N + 1, vector<ll>(H + 1, -1));
    dp[0][H] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= H; ++j) {
            if (dp[i][j] == -1) {
                continue;
            }

            int nj = max(0LL, j - A[i].second);

            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + j * A[i].first);
        }
    }

    ll ans = 0;
    for (int j = 0; j <= H; ++j) {
        ans = max(ans, dp[N][j]);
    }

    cout << ans << endl;

    return 0;
}
