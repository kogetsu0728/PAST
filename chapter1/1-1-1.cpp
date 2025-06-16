// https://atcoder.jp/contests/past201912-open/tasks/past201912_m

#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main() {
    int N, M;
    cin >> N >> M;

    vector<ld> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }

    vector<ld> C(M), D(M);
    for (int i = 0; i < M; ++i) {
        cin >> C[i] >> D[i];
    }

    auto check = [&](ld m) -> ld {
        vector<ld> p(N);
        for (int i = 0; i < N; ++i) {
            p[i] = ld(B[i]) - m * A[i];
        }

        ld ma = -1e12;
        for (int i = 0; i < M; ++i) {
            ma = max(ma, ld(D[i]) - m * C[i]);
        }
        p.emplace_back(ma);

        sort(p.rbegin(), p.rend());

        ld sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum += p[i];
        }

        return sum >= 0;
    };

    ld ok = 0, ng = 1e12;
    for (int i = 0; i < 1000; ++i) {
        ld mid = (ok + ng) / 2;

        if (check(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << fixed << setprecision(16) << ok << "\n";

    return 0;
}
