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
vector<ll> ls;
bool f(ll w) {
  int count = 1;
  ll sum = ls[0];
  rep2(i, 1, ls.size()) {
    ll l = ls[i];
    if (l + 1 + sum > w) {
      sum = l;
      count++;
    } else {
      sum += l + 1;
    }
  }
  return count <= m;
}

ll bs(ll ok, ll ng, bool f(ll)) {
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
  ls.resize(n);
  rep(i, n) cin >> ls[i];
  ll ml = 0;
  for (auto l : ls) ml = max(ml, l);

  out(bs(300000000000000, ml, f));
}
