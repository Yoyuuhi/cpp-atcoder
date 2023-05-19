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
using ll = long long;
using mint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  string s, t;
  cin >> s >> t;
  if (s == t) {
    out("Yes");
    return 0;
  }

  int n = s.size();
  rep(i, n - 1) {
    int l = i;
    int r = i + 1;
    if (s.substr(0, l) == t.substr(0, l) &&
        s.substr(r + 1) == t.substr(r + 1) && s[l] == t[r] && s[r] == t[l]) {
      out("Yes");
      return 0;
    }
  }
  out("No");
}
