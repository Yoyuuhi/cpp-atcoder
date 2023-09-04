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
using mint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;

pair<int, int> op1(pair<int, int> a, pair<int, int> b) {
  return -a.first - a.second < -b.first - b.second ? a : b;
}
pair<int, int> op2(pair<int, int> a, pair<int, int> b) {
  return -a.first + a.second < -b.first + b.second ? a : b;
}
pair<int, int> op3(pair<int, int> a, pair<int, int> b) {
  return a.first - a.second < b.first - b.second ? a : b;
}
pair<int, int> op4(pair<int, int> a, pair<int, int> b) {
  return a.first + a.second < b.first + b.second ? a : b;
}
pair<int, int> e1() { return {-INF, 0}; }
pair<int, int> e2() { return {INF, 0}; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<pair<int, int>> ps(n);
  rep(i, n) {
    int p;
    cin >> p;
    ps[i] = {i, p - 1};
  }
  sort(all(ps));

  vector<int> ans(n, INF);
  segtree<pair<int, int>, op1, e1> st1(n);
  segtree<pair<int, int>, op2, e1> st2(n);
  for (auto p : ps) {
    pair<int, int> r1 = st1.prod(0, p.second);
    if (r1.first != -INF) {
      int val = p.first + p.second - r1.first - r1.second;
      ans[p.first] = min(ans[p.first], val);
    }
    pair<int, int> r2 = st2.prod(p.second, n);
    if (r2.first != -INF) {
      int val = p.first - p.second - r2.first + r2.second;
      ans[p.first] = min(ans[p.first], val);
    }

    st1.set(p.second, p);
    st2.set(p.second, p);
  }
  segtree<pair<int, int>, op3, e2> st3(n);
  segtree<pair<int, int>, op4, e2> st4(n);
  for (int i = n - 1; i >= 0; i--) {
    auto p = ps[i];
    pair<int, int> r1 = st3.prod(0, p.second);
    if (r1.first != -INF) {
      int val = -p.first + p.second + r1.first - r1.second;
      ans[p.first] = min(ans[p.first], val);
    }
    pair<int, int> r2 = st4.prod(p.second, n);
    if (r2.first != -INF) {
      int val = -p.first - p.second + r2.first + r2.second;
      ans[p.first] = min(ans[p.first], val);
    }

    st3.set(p.second, p);
    st4.set(p.second, p);
  }

  for (auto a : ans) cout << a << " ";
  cout << endl;
}
