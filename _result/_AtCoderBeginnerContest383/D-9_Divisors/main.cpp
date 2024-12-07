#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS)                      \
  for (auto X : XS) cout << X << " "; \
  cout << endl;
#define outl cout << endl;
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
using mint = atcoder::modint1000000007;
const int INF = numeric_limits<int>::max() / 2;
const ll INFLL = numeric_limits<ll>::max() / 2;
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}
template <typename T>
T tpow(T x, int n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

vector<ll> get_primes(ll N) {
  vector<ll> primes;
  vector<bool> prime(N + 1, true);
  prime[0] = false;
  prime[1] = false;
  for (ll i = 2; i <= N; i++) {
    if (!prime[i]) continue;
    for (ll j = i * i; j <= N; j += i) {
      prime[j] = false;
    }
    primes.push_back(i);
  }
  return primes;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;
  n = sqrt(n);

  ll ans = 0;
  auto ps = get_primes(n + 1);

  int r = ps.size() - 1;
  rep(l, ps.size()) {
    while (ps[l] * ps[r] > n) r--;
    if (l >= r) break;
    ans += r - l;
  }
  for (auto p : ps) {
    if (tpow(p, 8) <= n * n) {
      ans++;
    } else {
      break;
    }
  }

  out(ans);
}
