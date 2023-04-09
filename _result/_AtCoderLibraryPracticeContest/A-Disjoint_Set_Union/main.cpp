#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#ifdef __LOCAL
#define DBG(X) cout << #X << " = " << (X) << endl;
#else
#define DBG(X)
#endif
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
template <typename T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
#ifdef __LOCAL
    freopen("input", "r", stdin);
#endif

    int n, q;
    cin >> n >> q;
    dsu d(n);

    rep(i, q) {
        int t, u, v;
        cin >> t >> u >> v;
        if (!t) {
            d.merge(u, v);
            continue;
        }
        if (d.same(u, v)) {
            out(1);
        } else {
            out(0);
        }
    }
}
