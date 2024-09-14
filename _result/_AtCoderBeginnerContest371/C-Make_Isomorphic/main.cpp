#include <bits/stdc++.h>

#include <atcoder/all>
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
typename enable_if<is_same_v<T, ll> || is_same_v<T, int> ||
                       is_same_v<T, unsigned int>,
                   void>::type
out(T value) {
  cout << value << endl;
}
template <typename T>
typename enable_if<is_same_v<T, mint>, void>::type out(T value) {
  cout << value.val() << endl;
}
template <typename T>
typename enable_if<is_same_v<T, vector<ll>> || is_same_v<T, vector<int>>,
                   void>::type
outs(T value) {
  for (auto v : value) cout << v << " ";
  cout << endl;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;
  vector<vector<bool>> x1(n, vector<bool>(n, false));
  int mg;
  cin >> mg;
  rep(i, mg) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    x1[u][v] = true;
    x1[v][u] = true;
  }
  vector<vector<bool>> x2(n, vector<bool>(n, false));
  int mh;
  cin >> mh;
  rep(i, mh) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    x2[a][b] = true;
    x2[b][a] = true;
  }

  vector<vector<ll>> ax(n, vector<ll>(n, 0));
  rep2(i, 1, n) {
    rep2(j, i + 1, n + 1) {
      ll a;
      cin >> a;
      ax[i - 1][j - 1] = a;
      ax[j - 1][i - 1] = a;
    }
  }

  ll ans = INFLL;
  vector<int> vs;
  rep(i, n) vs.push_back(i);
  do {
    ll ta = 0;
    rep(i, n) {
      rep2(j, i + 1, n) {
        int ii = vs[i];
        int jj = vs[j];

        if (x1[i][j] != x2[ii][jj]) ta += ax[ii][jj];
      }
    }
    ans = min(ans, ta);
  } while (next_permutation(all(vs)));
  out(ans);
}
