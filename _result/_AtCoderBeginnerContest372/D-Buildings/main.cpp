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

int op(int a, int b) { return max(a, b); }
int e() { return -1; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;
  auto hs = nis(n);
  vector<ll> ans(n + 1, 0);

  segtree<int, op, e> st(n + 2);
  st.set(hs[0], 0);
  rep2(i, 1, n) {
    int h = hs[i];

    auto a = st.prod(h + 1, n + 2);
    if (a == -1) {
      ans[1]++;
      ans[i + 1]--;
    } else {
      ans[a + 1]++;
      ans[i + 1]--;
    }

    st.set(h, i);
  }

  rep2(i, 1, n + 1) {
    ans[i] += ans[i - 1];
    cout << ans[i] << ' ';
  }
  outl;
}
