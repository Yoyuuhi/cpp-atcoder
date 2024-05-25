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

vector<vector<ll>> lrs;
int op(int a, int b) { return a + b; }
int e() { return 0; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<ll> nums;
  rep(i, n) {
    ll l, r;
    cin >> l >> r;
    lrs.push_back({l, r});
    nums.push_back(l);
    nums.push_back(r);
  }

  sort(all(lrs));
  sort(all(nums));
  map<int, int> mem;
  int idx = 0;
  rep(i, nums.size()) {
    int num = nums[i];
    if (mem.find(num) == mem.end()) {
      mem[num] = idx;
      idx++;
    }
  }

  ll ans = 0;
  segtree<ll, op, e> st(idx + 2);
  st.set(mem[lrs[0][1]], 1);
  rep2(i, 1, n) {
    ans += st.prod(mem[lrs[i][0]], idx + 2);
    st.set(mem[lrs[i][1]], st.get(mem[lrs[i][1]]) + 1);
  }
  out(ans);
}
