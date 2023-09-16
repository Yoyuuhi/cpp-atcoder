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

  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;
  rep(i, n) {
    rep2(j, i, n) {
      string ss = s.substr(i, j - i + 1);
      string ssr = ss;
      reverse(all(ssr));
      if (ss == ssr) ans = max(ans, j - i + 1);
    }
  }
  out(ans);
}
