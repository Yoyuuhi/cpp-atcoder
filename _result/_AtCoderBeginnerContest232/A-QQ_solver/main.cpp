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

int main() {
#ifdef __LOCAL
    freopen("input", "r", stdin);
#endif

    int a, b;
    string s;

    cin >> s;
    a = s[0]-'0';
    b = s[2]-'0';
    out(a*b);
}
