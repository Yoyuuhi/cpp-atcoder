#include <bits/stdc++.h>
#define out(X) cout << (X) << endl;
#ifdef __LOCAL
#define DBG(X) cout << #X << " = " << (X) << endl;
#else
#define DBG(X)
#endif
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
int l, r;
string s;

int main() {
#ifdef __LOCAL
    freopen("input", "r", stdin);
#endif

    cin >> l >> r >> s;
    l--;
    r--;
    rep(i, s.size()) {
        if (i >= l && i <= r) {
            int idx = r - (i-l);
            cout << s[idx];
        } else {
            cout << s[i];
        }
    }
    out("");
}
