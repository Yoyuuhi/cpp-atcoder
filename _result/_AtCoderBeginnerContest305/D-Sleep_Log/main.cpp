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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;
  vector<ll> as(n);
  rep(i, n) cin >> as[i];
  ll q;
  cin >> q;

  vector<ll> mem(n + 1, 0);
  rep2(i, 1, n + 1) {
    mem[i] += mem[i - 1];
    if (!(i % 2)) mem[i + 1] += as[i] - as[i - 1];
  }
  rep(i, q) {
    ll l, r;
    ll ta = 0;
    cin >> l >> r;
    auto il = lower_bound(all(as), l);
    int jl = il - as.begin();
    auto ir = lower_bound(all(as), r);
    int jr = ir - as.begin();
    if (jl > 0 && !(jl % 2)) {
      ta += as[jl] - l;
    }
    if (jr > 0 && !(jr % 2)) {
      ta -= as[jr] - r;
    }
    ta += mem[jr + 1] - mem[jl + 1];
    out(ta);
  }
}
