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

long long pow(long long x, long long n) {
  long long ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;

  // a*k^(b+1)+k^b=n
  // k = n
  ll ans = 1;

  rep2(b, 2, 41) {
    ll base = 2;
    ll B = pow(base, b);
    while (B < n) {
      ll res = n - B;
      if (res % (B * base) == 0) {
        ans++;
      }
      base++;
      B = pow(base, b);
    }
    if (B == n) ans++;
  }

  ll k = 2;
  while (k * k < n) {
    if (n % (k * k) == k) {
      ans++;
    }
    k++;
  }

  // k = n-1
  if (n > 2) ans++;
  n--;
  ll a = 2;
  while (n / a >= a) {
    if (n % a == 0) {
      ll b = n / a;
      ans += a == b ? 1 : 2;
    }
    a++;
  }
  out(ans);
}
