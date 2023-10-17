#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
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
using mint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;

ll xa, ya, xb, yb, xc, yc;
ll calc0(ll xt, ll yt) {
  ll ans = abs(xa - xt) + abs(ya - yt);
  if (ya == yt && (xa < xb && xb < xt || xa > xb && xb > xt)) ans += 2;
  if (xa == xt && (ya < yb && yb < yt || ya > yb && yb > yt)) ans += 2;
  return ans;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> xa >> ya >> xb >> yb >> xc >> yc;

  ll x0 = xb > xc ? xb + 1 : xb - 1;
  ll y0 = yb;
  ll x1 = xb;
  ll y1 = yb > yc ? yb + 1 : yb - 1;

  ll a0 = 0, a1 = 0;
  a0 += calc0(x0, y0);
  a0 += abs(xb - xc);
  if (yb != yc) a0 += 2 + abs(yb - yc);
  a1 += calc0(x1, y1);
  a1 += abs(yb - yc);
  if (xb != xc) a1 += 2 + abs(xb - xc);
  out(min(a0, a1));
}
