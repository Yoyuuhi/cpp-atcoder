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
T pow(T x, T n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
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
  vector<int> ts;
  vector<int> xs;
  rep(i, n) {
    int t, x;
    cin >> t >> x;
    x--;
    ts.push_back(t);
    xs.push_back(x);
  }

  segtree<int, op, e> st(n);
  rep(i, n) {
    int t = ts[i], x = xs[i];
    if (t == 1) st.set(x, st.get(x) + 1);
    if (t == 2) {
      int num = st.get(x);
      if (num > 0) {
        st.set(x, num - 1);
      } else {
        out(-1);
        return 0;
      }
    }
  }

  vector<bool> memSel(n, false);
  vector<int> memCol(n, 0);
  segtree<int, op, e> strev(n);
  for (int i = n - 1; i >= 0; i--) {
    int t = ts[i], x = xs[i];
    if (t == 2) {
      strev.set(x, strev.get(x) + 1);
    } else {
      if (memCol[x] < strev.get(x)) {
        memCol[x]++;
        memSel[i] = true;
      }
    }
  }

  int K = 0, tk = 0;
  vector<int> ans;
  rep(i, n) {
    int t = ts[i];
    if (t == 2) {
      tk--;
    } else {
      if (memSel[i]) {
        tk++;
        K = max(K, tk);
        ans.push_back(1);
      } else {
        ans.push_back(0);
      }
    }
  }
  out(K);
  outs(ans);
}
