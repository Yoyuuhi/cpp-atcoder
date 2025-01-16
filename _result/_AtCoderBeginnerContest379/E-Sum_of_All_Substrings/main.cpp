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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  string s;
  cin >> n >> s;

  vector<int> mem;
  vector<ll> ss(n, 0);
  rep(i, n) ss[i] = (i + 1) * (s[i] - '0');
  ll sum = 0, res = 0;
  for (auto num : ss) sum += num;

  for (int i = n - 1; i >= 0; i--) {
    mem.push_back((sum + res) % 10);
    res = (sum + res) / 10;

    sum -= ss[i];
  }

  if (res > 0) cout << res;
  for (int i = mem.size() - 1; i >= 0; i--) cout << mem[i];
  outl;
}
