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

template <typename T>
vector<pair<T, T>> prime_factor(T n) {
  vector<pair<T, T>> ret;
  for (T i = 2; i * i <= n; i++) {
    if (n % i != 0) continue;
    T tmp = 0;
    while (n % i == 0) {
      tmp++;
      n /= i;
    }
    ret.push_back(make_pair(i, tmp));
  }
  if (n != 1) ret.push_back(make_pair(n, 1));
  return ret;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;
  auto as = nis(n);

  ll cz = 0;
  ll ans = 0;
  map<ll, ll> mem;
  rep(i, n) {
    auto a = as[i];
    if (a == 0) {
      ans += i;
      cz++;
      continue;
    }

    auto ps = prime_factor(a);
    ll num = 1;
    for (auto pp : ps) {
      auto p = pp.first, c = pp.second;
      if (c % 2 == 1) num *= p;
    }
    ans += cz;
    if (mem.find(num) != mem.end()) {
      ans += mem[num];
    }
    mem[num] += 1;
  }
  out(ans);
}
