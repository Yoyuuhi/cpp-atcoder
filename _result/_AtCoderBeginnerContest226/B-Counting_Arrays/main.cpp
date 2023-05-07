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

int n;
vector<vector<int>> ax;

bool comp(vector<int> &a1, vector<int> &a2) {
  if (a1.size() != a2.size()) return a1.size() < a2.size();
  rep(i, a1.size()) {
    if (a1[i] != a2[i]) {
      return a1[i] < a2[i];
    }
  }
  return false;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n;
  rep(i, n) {
    int l;
    cin >> l;
    vector<int> as(l);
    rep(j, l) { cin >> as[j]; }
    ax.push_back(as);
  }
  sort(all(ax), comp);
  int ans = n;

  rep2(i, 1, n) {
    vector<int> a1 = ax[i - 1];
    vector<int> a2 = ax[i];
    if (a1.size() != a2.size()) continue;
    bool same = true;
    rep(j, a1.size()) {
      if (a1[j] != a2[j]) same = false;
    }
    if (same) ans--;
  }
  out(ans);
}
