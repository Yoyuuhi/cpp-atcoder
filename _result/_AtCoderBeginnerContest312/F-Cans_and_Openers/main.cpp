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

fenwick_tree<ll> fCount0;
fenwick_tree<ll> fSum01;
fenwick_tree<ll> fSum1;
int l, c0, c1;

int bs(int ok, int ng, bool f(int)) {
  if (!f(ok)) return -1;
  if (f(ng)) return ng;
  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    if (f(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}
bool f0(int r) { return fCount0.sum(l, r + 1) <= c0; }
bool f1(int r) { return (r - l + 1) - fCount0.sum(l, r + 1) <= c1; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;
  // 0: 必要、1: 不要
  vector<pair<ll, ll>> t01s;
  vector<ll> t2s;
  rep(i, n) {
    ll t, x;
    cin >> t >> x;
    if (t == 2) {
      t2s.push_back(x);
    } else {
      t01s.push_back({x, (t + 1) % 2});
    }
  }
  sort(all(t01s), greater<pair<ll, ll>>());
  sort(all(t2s), greater<ll>());

  fCount0 = fenwick_tree<ll>(t01s.size() + 1);
  rep(i, t01s.size()) if (!t01s[i].second) fCount0.add(i, 1);
  fSum01 = fenwick_tree<ll>(t01s.size() + 1);
  rep(i, t01s.size()) fSum01.add(i, t01s[i].first);
  fSum1 = fenwick_tree<ll>(t01s.size() + 1);
  rep(i, t01s.size()) if (t01s[i].second) fSum1.add(i, t01s[i].first);

  l = 0;
  c1 = m;
  int n0 = t01s.size() - 1;
  ll sum = 0;
  int r = bs(l, n0, f1);
  if (r >= 0) sum = fSum1.sum(l, r + 1);

  for (auto t2 : t2s) {
    c0 += t2;
    m--;
    if (!m) break;
    l = 0;
    r = bs(l, n0, f0);
    r = min(r, m - 1);
    ll sumt = fSum01.sum(l, r + 1);
    if (r < m - 1) {
      c1 = m - r - 1;
      l = r + 1;
      r = bs(l, n0, f1);
      sumt += fSum1.sum(l, r + 1);
    }
    sum = max(sum, sumt);
  }
  out(sum);
}
