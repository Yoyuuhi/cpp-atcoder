#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS) \
  for (auto X : XS) cout << X << " ";
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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, t;
  cin >> n >> t;
  map<ll, ll> mem1;
  mem1[0] = n;
  vector<ll> mem2(n, 0);

  ll ans = 1;
  rep(i, t) {
    ll a, b;
    cin >> a >> b;
    a--;

    ll num1 = mem2[a];
    ll num2 = num1 + b;
    mem2[a] = num2;
    mem1[num1]--;
    if (mem1[num1] == 0) ans--;
    if (mem1.find(num2) == mem1.end() || mem1[num2] == 0) ans++;
    mem1[num2]++;
    out(ans);
  }
}
