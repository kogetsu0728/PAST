// https://atcoder.jp/contests/abc236/tasks/abc236_e

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    auto check1 = [&](ld m) -> bool {
        vector dp(N + 1, vector<ld>(2));

        for (int i = 0; i < N; ++i) {
            auto d = A[i] - m;

            dp[i + 1][0] = dp[i][1];
            dp[i + 1][1] = max(dp[i][0], dp[i][1]) + d;
        }

        return max(dp[N][0], dp[N][1]) >= 0;
    };

    auto check2 = [&](ll m) -> bool {
        vector dp(N + 1, vector<ll>(2));

        for (int i = 0; i < N; ++i) {
            auto d = (A[i] >= m) ? 1 : -1;

            dp[i + 1][0] = dp[i][1];
            dp[i + 1][1] = max(dp[i][0], dp[i][1]) + d;
        }

        return max(dp[N][0], dp[N][1]) > 0;
    };

    {
        ld ok = 0, ng = 1e12;

        for (int i = 0; i < 100; ++i) {
            auto mid = (ok + ng) / 2;

            if (check1(mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        cout << fixed << setprecision(16) << ok << "\n";
    }

    {
        ll ok = 0, ng = 1LL << 32;

        while (abs(ok - ng) > 1) {
            auto mid = (ok + ng) / 2;

            if (check2(mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        cout << ok << "\n";
    }

    return 0;
}
