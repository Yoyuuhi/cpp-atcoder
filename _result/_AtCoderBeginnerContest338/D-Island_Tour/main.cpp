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

  ll n, m;
  cin >> n >> m;
  auto xs = nis(m);

  ll sum0 = 0;
  vector<pair<ll, ll>> mem(n, {0, 0});
  rep2(i, 1, m) {
    int x0 = xs[i - 1], x1 = xs[i];
    x0--;
    x1--;
    if (x0 > x1) swap(x0, x1);
    if (x1 - x0 <= n / 2) {
      sum0 += x1 - x0;
      int l = x1 - x0;
      mem[x0].first += 1;
      mem[x0].second += l;
      mem[x1].first -= 1;
      mem[x1].second -= l;
    } else {
      sum0 += n - (x1 - x0);
      int l = n - (x1 - x0);
      mem[0].first += 1;
      mem[0].second += l;
      mem[x0].first -= 1;
      mem[x0].second -= l;
      mem[x1].first += 1;
      mem[x1].second += l;
    }
  }

  ll dSum = INFLL;
  rep2(i, 1, n) {
    mem[i].first += mem[i - 1].first;
    mem[i].second += mem[i - 1].second;
  }
  rep(i, n) dSum = min(dSum, mem[i].first * n - mem[i].second - mem[i].second);
  out(sum0 + dSum);
}
