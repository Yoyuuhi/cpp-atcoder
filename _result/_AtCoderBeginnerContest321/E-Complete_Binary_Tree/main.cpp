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

void solve() {
  ll n, x, k;
  cin >> n >> x >> k;
  vector<ll> layNum;
  ll two = 1;
  ll tn = n;
  while (tn) {
    layNum.push_back(min(two, tn));
    tn -= min(two, tn);
    two *= 2;
  }
  ll xLay = 0;
  ll tx = x;
  for (auto num : layNum) {
    if (!tx) break;
    xLay++;
    tx -= min(num, tx);
  }

  ll ans = 0;
  ll from = 0;
  while (k > 0 && x) {
    if (xLay + k > ll(layNum.size())) {
      xLay--;
      k--;
      if (x % 2) {
        from = 1;
      } else {
        from = -1;
      }
      x /= 2;
      continue;
    }
    ll lel = x * 2;
    ll ril = x * 2 + 1;
    ll rir = x * 2 + 1;
    rep(i, k - 1) {
      lel *= 2;
      ril *= 2;
      rir = rir * 2 + 1;
    }
    ll ler = ril - 1;
    ll total = max(ll(0), min(rir, n) - lel + 1);
    if (from == 1) {
      total -= max(ll(0), min(rir - ril + 1, n - ril + 1));
    }
    if (from == -1) {
      total -= max(ll(0), min(ler - lel + 1, n - lel + 1));
    }
    ans += total;

    xLay--;
    k--;
    if (x % 2) {
      from = 1;
    } else {
      from = -1;
    }
    x /= 2;
  }
  if (k == 0 && x) ans++;
  out(ans);
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int t;
  cin >> t;
  rep(i, t) { solve(); }
}
