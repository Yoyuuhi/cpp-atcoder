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

ll n, m;
mint calcA(mint a0, mint cx, mint cy) {
  mint a1, a2;
  a1 = (a0 + a0 + (cy - 1) * 2) * cy / 2;
  a2 = (a1 + a1 + (cx - 1) * 2 * m * cy) * cx / 2;
  return a2;
}

void calc() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll h = b - a + 1;
  ll w = d - c + 1;

  mint cy, cx;
  mint ans = 0;
  if (!((a + c) % 2)) {
    cy = (w + 1) / 2;
    cx = (h + 1) / 2;
    mint a0 = (a - 1) * m + c;
    ans += calcA(a0, cx, cy);
  } else if (h) {
    cy = (w + 1) / 2;
    cx = h / 2;
    mint a0 = (a - 1) * m + c + m;
    ans += calcA(a0, cx, cy);
  }
  if ((a + c) % 2) {
    cy = w / 2;
    cx = (h + 1) / 2;
    mint a0 = (a - 1) * m + c + 1;
    ans += calcA(a0, cx, cy);
  } else if (h) {
    cy = w / 2;
    cx = h / 2;
    mint a0 = (a - 1) * m + c + 1 + m;
    ans += calcA(a0, cx, cy);
  }

  out(ans.val());
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> m;
  int q;
  cin >> q;
  rep(i, q) calc();
}
