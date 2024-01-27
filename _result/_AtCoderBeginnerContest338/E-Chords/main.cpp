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

int op(int a, int b) { return max(a, b); }
int e() { return -1; }
int target;
bool f(int val) { return val < target; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<vector<int>> abn;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    abn.push_back({a, b});
  }
  sort(all(abn));

  vector<int> as, bs;
  for (auto ab : abn) {
    as.push_back(ab[0]);
    bs.push_back(ab[1]);
  }
  segtree<int, op, e> st(bs);
  rep(i, n - 1) {
    int b0 = abn[i][1];
    int r = lower_bound(all(as), b0 + 1) - as.begin();
    int b1 = st.prod(i + 1, r);
    if (b1 >= b0) {
      out("Yes");
      return 0;
    }
  }
  out("No");
}
