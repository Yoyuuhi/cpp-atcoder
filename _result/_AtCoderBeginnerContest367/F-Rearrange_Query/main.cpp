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

struct RandomNumberGenerator {
  mt19937 mt;

  RandomNumberGenerator()
      : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

  int operator()(int a, int b) {  // [a, b)
    uniform_int_distribution<int> dist(a, b - 1);
    return dist(mt);
  }

  int operator()(int b) {  // [0, b)
    return (*this)(0, b);
  }
};

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, q;
  cin >> n >> q;
  auto as = nis(n);
  auto bs = nis(n);

  RandomNumberGenerator r;
  vector<ll> hs(n + 1);
  rep(i, n + 1) hs[i] = r.operator()(1000000007);

  vector<ll> has(n + 1, 0), hbs(n + 1, 0);
  rep(i, n) {
    has[i + 1] = hs[as[i]] + has[i];
    hbs[i + 1] = hs[bs[i]] + hbs[i];
  }

  rep(i, q) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    l1--;
    r1--;
    l2--;
    r2--;

    if (r1 - l1 != r2 - l2) {
      out("No");
      continue;
    }

    cout << ((has[r1 + 1] - has[l1]) == (hbs[r2 + 1] - hbs[l2]) ? "Yes" : "No")
         << endl;
  }
}
