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

vector<ll> hs;
ll n, a, b;
bool judge(ll target) {
  ll t = 0;
  for (auto h : hs) {
    if (b * target >= h) continue;
    ll hh = h - b * target;
    ll tt = hh / (a - b) + (hh % (a - b) ? 1 : 0);
    t += tt;
  }
  return t <= target;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> a >> b;
  hs = nis(n);
  ll ok = 0;
  for (auto h : hs) ok = max(ok, h / b + (h % b ? 1 : 0));

  out(bs(ok, ll(0), judge));
}
