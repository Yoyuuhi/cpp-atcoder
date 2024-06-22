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

struct S {
  int idx;
  ll height;
};

int op(int a, int b) { return max(a, b); }
int e() { return -1; }
int target;
bool f(int val) { return val < target; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;
  auto hs = nis(n);

  map<ll, bool> mh;
  for (auto h : hs) mh[h] = true;
  vector<ll> dh;
  for (auto m : mh) dh.push_back(m.first);
  map<ll, int> mem;
  rep(i, dh.size()) mem[dh[i]] = i;

  segtree<int, op, e> st(dh.size());
  auto N = dh.size();
  st.set(mem[hs[0]], 0);

  vector<ll> ans;
  ans.push_back(hs[0]);
  rep2(i, 1, n) {
    ll h = hs[i];
    auto idx = st.prod(mem[h], N);
    if (idx == -1) {
      ans.push_back(h * (i + 1));
    } else {
      ans.push_back(ans[idx] + min(h, hs[idx]) * (i - idx));
    }
    st.set(mem[h], i);
  }

  for (auto a : ans) {
    cout << a + 1 << " ";
  }
  outl;
}
