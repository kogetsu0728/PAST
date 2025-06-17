// https://atcoder.jp/contests/past202012-open/tasks/past202012_m

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    ll L;
    cin >> L;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> csum(N + 1);
    for (int i = 0; i < N; ++i) {
        csum[i + 1] = csum[i] + A[i];
    }

    auto check = [&](ll m) -> bool {
        vector<ll> imos(N + 1);
        imos[0] = 1;
        imos[1] = -1;

        ll l = 0, r = 0;
        for (int i = 0; i < N + 1; ++i) {
            if (i - 1 >= 0) {
                imos[i] += imos[i - 1];
            }

            if (imos[i] == 0) {
                continue;
            }

            while (l < N + 1 && csum[l] - csum[i] < m) {
                ++l;
            }

            while (r + 1 < N + 1 && csum[r + 1] - csum[i] <= L) {
                ++r;
            }

            if (l < N + 1) {
                ++imos[l];
            }

            if (r + 1 < N + 1) {
                --imos[r + 1];
            }
        }

        return imos[N] > 0;
    };

    ll ok = 1, ng = L + 1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ok << "\n";

    return 0;
}
