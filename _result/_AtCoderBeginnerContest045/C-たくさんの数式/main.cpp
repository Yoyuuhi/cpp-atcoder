#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS)                      \
  for (auto X : XS) cout << X << " "; \
  cout << endl;
#define outl cout << endl;
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
using mint = atcoder::modint1000000007;
const int INF = numeric_limits<int>::max() / 2;
const ll INFLL = numeric_limits<ll>::max() / 2;
ll ni() {
  ll ret;
  cin >> ret;
  return ret;
}
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}

ll calc(string s, int bit) {
  int n = s.size();
  ll num = 0;
  ll ret = 0;
  rep(i, n) {
    num *= 10;
    num += s[i] - '0';
    if ((bit >> i) & 1 == 1 || i == n - 1) {
      ret += num;
      num = 0;
    }
  }
  return ret;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  string s;
  cin >> s;
  ll ans = 0;
  rep(bit, 1 << (s.size() - 1)) { ans += calc(s, bit); }
  out(ans);
}
