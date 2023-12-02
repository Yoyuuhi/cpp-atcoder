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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, m, l;
  cin >> n >> m >> l;
  auto as = nis(n);
  auto bs = nis(m);
  vector<pair<int, int>> pas;
  rep(i, n) { pas.push_back({as[i], i + 1}); }
  vector<pair<int, int>> pbs;
  rep(i, m) { pbs.push_back({bs[i], i + 1}); }

  sort(all(pas), greater<pair<int, int>>());
  sort(all(pbs), greater<pair<int, int>>());

  set<pair<int, int>> st;
  rep(i, l) {
    int c, d;
    cin >> c >> d;
    st.insert({c, d});
  }

  vector<ll> anss;
  for (auto pa : pas) {
    for (auto pb : pbs) {
      if (st.find({pa.second, pb.second}) == st.end()) {
        anss.push_back(pa.first + pb.first);
        break;
      }
    }
  }
  sort(all(anss), greater<ll>());
  out(anss[0]);
}
