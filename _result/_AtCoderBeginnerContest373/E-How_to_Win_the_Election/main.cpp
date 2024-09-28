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

ll op(ll a, ll b) { return a + b; }
ll e() { return 0; }
segtree<ll, op, e> st;

ll bs(ll ok, ll ng, bool f(ll)) {
  if (!f(ok)) return -1;
  if (f(ng)) return ng;
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (f(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

ll n, m, k, res;
ll ia;
vector<ll> sas;
bool f(ll border) {
  ll ir = lower_bound(all(sas), border + 1) - sas.begin();
  ll il = n - m;
  if (ia >= il) il--;
  if (ir <= il) return false;

  ll sum = 0;
  sum += (border + 1) * (ir - il) - st.prod(il, ir);
  if (ia >= il) sum -= border + 1 - sas[ia];

  auto ires = res - (border - sas[ia]);
  return sum > ires;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> m >> k;
  auto as = nis(n);
  res = k;

  for (auto a : as) {
    sas.push_back(a);
    res -= a;
  }
  sort(all(sas));

  if (n == m) {
    vector<ll> ans(n, 0);
    outs(ans);
    return 0;
  }

  st = segtree<ll, op, e>(sas);
  map<ll, ll> memans;
  for (int i = 0; i < n; i++) {
    while (i + 1 < n && sas[i + 1] == sas[i]) i++;
    ia = i;

    auto border = bs(sas[i] + res, sas[i], f);
    if (border == -1) {
      memans[sas[i]] = -1;
    } else {
      memans[sas[i]] = border - sas[i];
    }
  }
  for (auto a : as) cout << memans[a] << ' ';
  outl;
}
