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

long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int l;
  cin >> l;

  ll d = 1;
  rep2(i, 1, 12) d *= i;
  vector<ll> as;
  for (ll i = l - 1; i >= l - 11; i--) as.push_back(i);
  ll ans = 1;
  for (auto a : as) {
    ll g = gcd(a, d);
    a /= g;
    d /= g;
    ans *= a;
  }
  out(ans);
}
