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

vector<ll> as, bs;
ll n, m;
bool judge(ll x) {
  ll i1 = upper_bound(all(as), x) - begin(as);
  ll i2 = lower_bound(all(bs), x) - begin(bs);

  return i1 >= m - i2;
}

ll bsearch(ll ok, ll ng, bool f(ll)) {
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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> m;
  as.assign(n, 0);
  rep(i, n) cin >> as[i];
  bs.assign(m, 0);
  rep(i, m) cin >> bs[i];
  sort(all(as));
  sort(all(bs));
  out(bsearch(1000000001, 0, judge));
}
