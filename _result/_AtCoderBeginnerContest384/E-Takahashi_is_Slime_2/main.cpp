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

  ll h, w, x;
  cin >> h >> w >> x;
  ll p, q;
  cin >> p >> q;
  p--;
  q--;
  vector<vector<ll>> sx(h);
  rep(i, h) sx[i] = nis(w);

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  vector<bool> seen(h * w, false);
  seen[p * w + q] = true;
  vector<vector<ll>> vs = {
      {0, 1},
      {0, -1},
      {1, 0},
      {-1, 0},
  };
  for (auto v : vs) {
    auto pp = p + v[0], qq = q + v[1];
    if (!(pp >= 0 && pp < h && qq >= 0 && qq < w)) continue;
    if (!seen[pp * w + qq]) {
      pq.emplace(sx[pp][qq], pp * w + qq);
      seen[pp * w + qq] = true;
    }
  }

  ll ans = sx[p][q];
  while (!pq.empty()) {
    auto mem = pq.top();
    pq.pop();
    auto s = mem.first, xx = mem.second / w, yy = mem.second % w;

    auto l = ans / x;
    if (ans % x) l++;
    if (s >= l) continue;
    ans += s;

    for (auto v : vs) {
      auto pp = xx + v[0], qq = yy + v[1];
      if (!(pp >= 0 && pp < h && qq >= 0 && qq < w)) continue;
      if (!seen[pp * w + qq]) {
        pq.emplace(sx[pp][qq], pp * w + qq);
        seen[pp * w + qq] = true;
      }
    }
  }
  out(ans);
}
