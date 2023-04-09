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
    fenwick_tree<long long> f(n);
    rep(i, n) {
        int a;
        cin >> a;
        f.add(i, a);
    }

    rep(i, q) {
        int qu;
        cin >> qu;
        if (!qu) {
            int p, x;
            cin >> p >> x;
            f.add(p, x);
            continue;
        }
        int l, r;
        cin >> l >> r;
        out(f.sum(l, r));
    }
}
