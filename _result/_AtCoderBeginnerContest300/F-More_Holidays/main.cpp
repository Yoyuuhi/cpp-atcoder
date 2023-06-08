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

  ll n, m, k;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  vector<ll> mem(n + 1, 0);
  rep(i, n) {
    if (s[i] == 'x') mem[i + 1] += 1;
    mem[i + 1] += mem[i];
  }
  ll l = mem[n];

  ll ans = 0;
  rep(i, n) {
    ll ta = 0;
    ll count = k;
    auto it = lower_bound(all(mem), mem[i] + k + 1);
    if (it != mem.end()) {
      ans = max(ans, (ll)(it - mem.begin() - i - 1));
      continue;
    }
    ta += n - i;
    count -= mem[n] - mem[i];

    ll t = count / l;
    if (t + 1 >= m) {
      ans = max(ans, ta + n * (m - 1));
      continue;
    }
    ta += t * n;
    count %= l;
    it = lower_bound(all(mem), count + 1);
    ans = max(ans, (ll)(it - mem.begin() + ta - 1));
  }
  out(ans)
}
