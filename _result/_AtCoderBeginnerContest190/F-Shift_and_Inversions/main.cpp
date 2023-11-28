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

int op(int a, int b) { return a + b; }
int e() { return 0; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  auto as = nis(n);

  vector<ll> mem(n, 0);
  segtree<ll, op, e> st(n);
  for (int i = n - 1; i >= 0; i--) {
    st.set(as[i], 1);
    mem[i] = st.prod(0, as[i]);
  }
  ll ans = 0;
  for (auto m : mem) ans += m;

  rep(i, n) {
    out(ans);
    ll num = st.prod(0, as[i]);
    ans -= num;
    ans += n - 1 - num;
  }
}
