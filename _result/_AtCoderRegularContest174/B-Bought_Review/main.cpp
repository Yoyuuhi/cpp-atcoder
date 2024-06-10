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
template <typename T>
T tpow(T x, int n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

void calc() {
  ll n = 5;
  auto as = nis(n);
  auto ps = nis(n);

  ll num = 0, score = 0;
  rep(i, n) {
    num += as[i];
    score += as[i] * (i + 1);
  }

  if (score >= num * 3) {
    out(0);
    return;
  }
  ll diff = 3 * num - score;

  ll p4 = ps[3], p5 = ps[4];
  ll ans = diff * p4;
  ans = min(ans, p5 * (diff / 2 + diff % 2));
  ans = min(ans, p4 * (diff - diff / 2 * 2) + p5 * (diff / 2));

  out(ans);
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int t;
  cin >> t;

  rep(i, t) calc();
}
