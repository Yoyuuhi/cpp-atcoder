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
ll ni() {
  ll ret;
  cin >> ret;
  return ret;
}
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}

bool comp(pair<int, int>& a1, pair<int, int>& a2) {
  if (a1.first != a2.first) return a1.first > a2.first;
  return a1.second < a2.second;
}

void compression(vector<int>& a) {
  set<int> s(a.begin(), a.end());
  map<int, int> d;
  int cnt = 0;
  for (auto x : s) d[x] = cnt++;
  for (auto& x : a) x = d[x];
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
  auto bs = nis(n);
  compression(as);
  compression(bs);
  map<pair<int, int>, int> d;
  rep(i, n) d[{as[i], bs[i]}]++;

  vector<pair<int, int>> mem;
  for (auto m : d) mem.push_back(m.first);
  sort(all(mem), comp);

  segtree<int, op, e> st(d.size());
  ll ans = 0;
  for (auto m : mem) {
    int b = m.second;
    ll cnt = d[m];
    ans += cnt * (cnt + st.prod(0, b + 1));
    st.set(b, cnt + st.get(b));
  }
  out(ans);
}
