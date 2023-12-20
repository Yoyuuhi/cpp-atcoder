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
T pow(T x, int n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

ll n, k;
vector<ll> xs;
vector<ll> ys;
ll sumx1 = 0, sumy1 = 0;
ll sumx2 = 0, sumy2 = 0;

template <typename T>
T bs(T ok, T ng, bool f(ll)) {
  if (!f(ok)) return -1;
  if (f(ng)) return ng;
  while (abs(ok - ng) > 1) {
    auto mid = (ok + ng) / 2;
    if (f(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

ll calc1(ll l, vector<ll> as, ll suma) {
  ll ret = suma;
  int ir = 0;
  while (ir < n && as[ir] <= as[0] + l) {
    ret -= as[ir] - as[0];
    ir++;
  }
  ret -= (n - ir) * l;
  ll val = ret;

  rep2(i, 1, n) {
    val += i * (as[i] - as[i - 1]);
    while (ir < n && as[ir] <= as[i] + l) {
      val -= as[ir] - (as[i - 1] + l);
      ir++;
    }
    val -= (n - ir) * (as[i] - as[i - 1]);
    ret = min(ret, val);
  }
  return ret;
}

ll calc2(ll l, vector<ll> as, ll suma) {
  ll ret = suma;
  int il = n - 1;
  while (il >= 0 && as[il] >= as[n - 1] - l) {
    ret -= as[n - 1] - as[il];
    il--;
  }
  ret -= (il + 1) * l;
  ll val = ret;

  for (int i = n - 2; i >= 0; i--) {
    val += (n - 1 - i) * (as[i + 1] - as[i]);
    while (il >= 0 && as[il] >= as[i] - l) {
      val -= as[i + 1] - l - as[il];
      il--;
    }
    val -= (il + 1) * (as[i + 1] - as[i]);
    ret = min(ret, val);
  }
  return ret;
}

bool f(ll l) {
  ll cx = min(calc1(l, xs, sumx1), calc2(l, xs, sumx2));
  ll cy = min(calc1(l, ys, sumy1), calc2(l, ys, sumy2));
  return cx + cy <= k;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> k;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    xs.push_back(x);
    ys.push_back(y);
  }

  sort(all(xs));
  sort(all(ys));
  for (auto x : xs) sumx1 += x - xs[0];
  for (auto y : ys) sumy1 += y - ys[0];
  for (auto x : xs) sumx2 += xs[n - 1] - x;
  for (auto y : ys) sumy2 += ys[n - 1] - y;
  out(bs(1000000000, 0, f));
}
