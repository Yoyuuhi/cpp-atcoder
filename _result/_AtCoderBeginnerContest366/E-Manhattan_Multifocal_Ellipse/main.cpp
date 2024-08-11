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

ll n, d;
vector<ll> xs, ys;
vector<ll> sxs, sys;

vector<ll> calcD(vector<ll> as, vector<ll> sas) {
  vector<ll> das;
  int idx = 0;
  for (ll num = as[0]; num <= as[n - 1]; num++) {
    while (idx + 1 < n && as[idx + 1] <= num) idx++;
    ll dd = 0;
    dd += (idx + 1) * num - sas[idx];
    dd += sas[n - 1] - sas[idx] - (n - (idx + 1)) * num;
    if (dd <= d) das.push_back(dd);
  }

  for (ll num = as[n - 1] + 1; num <= 3000000; num++) {
    ll dd = n * num - sas[n - 1];
    if (dd <= d) {
      das.push_back(dd);
    } else {
      break;
    }
  }
  for (ll num = as[0] - 1; num >= -3000000; num--) {
    ll dd = sas[n - 1] - n * num;
    if (dd <= d) {
      das.push_back(dd);
    } else {
      break;
    }
  }

  sort(all(das));
  return das;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif
  cin >> n >> d;

  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    xs.push_back(x);
    ys.push_back(y);
  }
  sort(all(xs));
  sort(all(ys));

  sxs.resize(n);
  sys.resize(n);
  rep(i, n) {
    sxs[i] = xs[i];
    if (i > 0) sxs[i] += sxs[i - 1];
    sys[i] = ys[i];
    if (i > 0) sys[i] += sys[i - 1];
  }

  vector<ll> dxs = calcD(xs, sxs);
  vector<ll> dys = calcD(ys, sys);

  ll ans = 0;
  for (auto dx : dxs) ans += lower_bound(all(dys), d - dx + 1) - dys.begin();
  out(ans);
}
