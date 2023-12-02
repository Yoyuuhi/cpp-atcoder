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

ll n, q, tb;
vector<vector<ll>> mem;
void calc() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  c -= a / n * n;
  a %= n;
  d -= b / n * n;
  b %= n;
  a++;
  b++;
  c++;
  d++;

  ll ans = 0;
  ll cn = (c - a + 1) / n * ((d - b + 1) / n);
  ans += tb * cn;
  ll e = a + (c - a + 1) % n - 1;
  ll f = b + (d - b + 1) % n - 1;
  if (e >= a) {
    ll l = mem[e][n] - mem[e][0] - mem[a - 1][n] + mem[a - 1][0];
    ll cl = (d - b + 1) / n;
    ans += cl * l;
  }
  if (f >= b) {
    ll l = mem[n][f] - mem[0][f] - mem[n][b - 1] + mem[0][b - 1];
    ll cl = (c - a + 1) / n;
    ans += cl * l;
  }
  if (e >= a && f >= b) {
    ans += mem[e][f] - mem[e][b - 1] - mem[a - 1][f] + mem[a - 1][b - 1];
  }
  out(ans);
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> q;
  tb = 0;
  vector<string> ps(n);
  rep(i, n) cin >> ps[i];

  mem.assign(2 * n + 1, vector<ll>(2 * n + 1, 0));
  rep(i, n) {
    rep(j, n) {
      char c = ps[i][j];
      if (c == 'B') {
        mem[i + 1][j + 1]++;
        mem[i + 1 + n][j + 1]++;
        mem[i + 1][j + 1 + n]++;
        mem[i + 1 + n][j + 1 + n]++;
        tb++;
      }
    }
  }
  rep(i, 2 * n + 1) {
    rep2(j, 1, 2 * n + 1) { mem[i][j] += mem[i][j - 1]; }
  }
  rep(j, 2 * n + 1) {
    rep2(i, 1, 2 * n + 1) { mem[i][j] += mem[i - 1][j]; }
  }

  rep(i, q) { calc(); }
}
