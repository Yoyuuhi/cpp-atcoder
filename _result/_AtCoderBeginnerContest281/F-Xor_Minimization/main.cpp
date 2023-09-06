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

int n;
vector<ll> as;
ll calc(int l, int r) {
  for (int i = 29; i >= 0; i--) {
    if ((as[l] & (1 << i)) == (as[r] & (1 << i))) continue;
    ll border = ((as[l] >> i) << i) + (1 << i);
    int bi = lower_bound(all(as), border) - as.begin();
    return min(calc(l, bi - 1), calc(bi, r)) + (1 << i);
  }
  return 0;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n;
  as.resize(n);
  rep(i, n) cin >> as[i];
  sort(all(as));
  out(calc(0, n - 1));
}
