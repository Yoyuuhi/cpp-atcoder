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
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  string s;
  cin >> s;

  ll num = 0;
  ll ans = 0;
  rep(i, n - 1) {
    char c = s[i];
    if (c == '<') {
      ans += num * (num + 1) / 2;
      num = 0;
    } else {
      num++;
    }
  }
  ans += num * (num + 1) / 2;
  out(ans);
}
