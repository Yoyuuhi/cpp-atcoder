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
  int a0;
  int num0;
  int a1;
  int num1;
};

S op(S A, S B) {
  map<int, int> ms;
  ms[A.a0] += A.num0;
  ms[A.a1] += A.num1;
  ms[B.a0] += B.num0;
  ms[B.a1] += B.num1;
  vector<vector<int>> mem;
  for (auto m : ms) mem.push_back({m.first, m.second});
  sort(all(mem), greater<vector<int>>());

  if (mem.size() == 1) {
    return S{mem[0][0], mem[0][1], 0, 0};
  } else {
    return S{mem[0][0], mem[0][1], mem[1][0], mem[1][1]};
  }
}
S e() { return S{0, 0, 0, 0}; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, q;
  cin >> n >> q;
  auto as = nis(n);

  vector<S> AS;
  for (auto a : as) AS.push_back(S{a, 1, 0, 0});
  segtree<S, op, e> st(AS);
  rep(i, q) {
    int que;
    cin >> que;
    if (que == 1) {
      int p, x;
      cin >> p >> x;
      p--;
      st.set(p, S{x, 1, 0, 0});
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      out(st.prod(l, r).num1);
    }
  }
}
