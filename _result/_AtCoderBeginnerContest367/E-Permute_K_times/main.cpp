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

vector<ll> xs;

vector<ll> proc(vector<ll> v1, vector<ll> v2) {
  vector<ll> v(v1.size());
  rep(i, v1.size()) v[i] = v1[v2[i]];
  return v;
}

vector<ll> calc(ll num) {
  if (num == 1) {
    return xs;
  }

  auto txs = calc(num / 2);
  txs = proc(txs, txs);
  if (num % 2) txs = proc(txs, xs);
  return txs;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, k;
  cin >> n >> k;
  rep(i, n) {
    ll x;
    cin >> x;
    x--;
    xs.push_back(x);
  }
  auto as = nis(n);
  if (k == 0) {
    outs(as);
    return 0;
  }

  auto ans = proc(as, calc(k));
  outs(ans);
}
