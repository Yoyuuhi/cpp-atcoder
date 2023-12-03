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

int n, q;
vector<int> cs;
vector<tuple<int, int, int>> rls;
int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n >> q;
  cs = nis(n);
  rls.resize(q);
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    rls.push_back({r, l, i});
  }
  sort(all(rls));

  vector<int> ans(q);
  fenwick_tree<int> ft(n + 1);
  vector<int> lastappear(n + 1, -1);
  int rnow = -1;
  for (auto rl : rls) {
    int l = get<1>(rl);
    int r = get<0>(rl);
    int i = get<2>(rl);
    while (rnow < r) {
      int nr = rnow + 1;
      int c = cs[nr];
      if (lastappear[c] != -1) ft.add(lastappear[c], -1);
      ft.add(nr, 1);
      lastappear[c] = nr;
      rnow++;
    }
    ans[i] = ft.sum(l, r + 1);
  }
  for (auto a : ans) out(a);
}
