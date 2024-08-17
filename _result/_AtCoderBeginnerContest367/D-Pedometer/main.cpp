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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, m;
  cin >> n >> m;
  auto as = nis(n);

  vector<ll> sa;
  sa.push_back(0);
  for (auto a : as) {
    sa.push_back(a);
    sa[sa.size() - 1] += sa[sa.size() - 2];
  }
  ll sum = sa[n];

  // outs(sa);

  map<ll, ll> mem;
  rep2(i, 1, n) mem[sa[i] % m]++;
  ll res = 0, ans = 0;
  rep(i, n) {
    ans += mem[res];

    res = (res + as[i]) % m;
    mem[sa[i + 1] % m]--;
    mem[(sum + sa[i]) % m]++;
  }
  out(ans);
}
