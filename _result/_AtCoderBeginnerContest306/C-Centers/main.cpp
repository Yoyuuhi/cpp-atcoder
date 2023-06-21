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

vector<pair<int, int>> ax;

bool comp(pair<int, int> &a1, pair<int, int> &a2) {
  return a1.second < a2.second;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  ax.assign(n, {-1, 3 * n + 1});
  rep(i, n) ax[i].first = i + 1;
  rep(i, 3 * n) {
    int a;
    cin >> a;
    if (ax[a - 1].second > 3 * n) {
      ax[a - 1].second = -i - 1;
    } else if (ax[a - 1].second < 0) {
      ax[a - 1].second = i + 1;
    }
  }
  sort(all(ax), comp);
  rep(i, n) cout << ax[i].first << " ";
  cout << endl;
}
