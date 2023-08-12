// https://atcoder.jp/contests/abc308/tasks/abc308_f
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

bool comp(vector<ll> &a1, vector<ll> &a2) { return a1[0] < a2[0]; }
auto compare = [](vector<ll> &a1, vector<ll> &a2) -> bool {
  // bigger one is top
  return a1[1] < a2[1];
};
;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, m;
  cin >> n >> m;
  vector<ll> ps(n);
  rep(i, n) cin >> ps[i];
  sort(all(ps));
  vector<ll> ls(m), ds(m);
  rep(i, m) cin >> ls[i];
  rep(i, m) cin >> ds[i];

  vector<vector<ll>> lds(m);
  rep(i, m) lds[i] = {ls[i], ds[i]};
  sort(all(lds), comp);

  priority_queue<vector<ll>, vector<vector<ll>>, decltype(compare)> pq(compare);
  ll idx = 0;
  ll ans = 0;
  for (auto p : ps) {
    while (idx < m && lds[idx][0] <= p) {
      pq.push({lds[idx][0], lds[idx][1]});
      idx++;
    }
    if (!pq.empty()) {
      auto pp = pq.top();
      pq.pop();
      ans += p - pp[1];
    } else {
      ans += p;
    }
  }
  out(ans)
}
