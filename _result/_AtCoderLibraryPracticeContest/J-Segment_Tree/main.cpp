#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
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
using Modint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;

int op(int a, int b) { return max(a, b); }
int e() { return -1; }
int target;
bool f(int val) { return val < target; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, q;
  cin >> n >> q;
  vector<int> as;
  rep(i, n) {
    int a;
    cin >> a;
    as.push_back(a);
  }

  segtree<int, op, e> st(as);
  rep(i, q) {
    int que;
    cin >> que;
    int x, y;
    cin >> x >> y;
    x--;
    if (que == 1) {
      st.set(x, y);
    } else if (que == 2) {
      out(st.prod(x, y));
    } else if (que == 3) {
      target = y;
      int j = st.max_right(x, f);
      out(j + 1);
    }
  }
}
