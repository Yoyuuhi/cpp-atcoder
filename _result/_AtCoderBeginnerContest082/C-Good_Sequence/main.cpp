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

  int n;
  cin >> n;
  vector<ll> as(n);
  rep(i, n) cin >> as[i];

  map<ll, ll> mem;
  for (auto a : as) mem[a]++;
  ll ans = 0;
  for (auto m : mem) {
    ll k = m.first;
    ll v = m.second;
    if (v >= k) {
      ans += v - k;
    } else {
      ans += v;
    }
  }
  out(ans);
}
