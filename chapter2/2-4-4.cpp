// https://atcoder.jp/contests/dp/tasks/dp_r

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    ll K;
    cin >> K;

    vector A(N, vector<ll>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    auto mul = [&](vector<vector<ll>>& a, vector<vector<ll>>& b) -> vector<vector<ll>> {
        vector res(N, vector<ll>(N));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    res[i][j] += a[i][k] * b[k][j];
                    res[i][j] %= MOD;
                }
            }
        }

        return res;
    };

    vector m(N, vector<ll>(N));
    for (int i = 0; i < N; ++i) {
        m[i][i] = 1;
    }

    while (K > 0) {
        if (K & 1) {
            m = mul(A, m);
        }

        A = mul(A, A);
        K >>= 1;
    }

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            ans += m[i][j];
            ans %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
