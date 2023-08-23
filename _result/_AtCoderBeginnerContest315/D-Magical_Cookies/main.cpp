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

bool poss(vector<int> vec) {
  int count = 0;
  int vm = 0;
  for (auto v : vec) {
    vm = max(vm, v);
    if (v) count++;
  }
  return count == 1 && vm > 1;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int h, w;
  cin >> h >> w;
  vector<string> cx(h);
  rep(i, h) cin >> cx[i];

  vector<vector<int>> memR(h, vector<int>(26, 0));
  vector<vector<int>> memC(w, vector<int>(26, 0));
  vector<bool> pR(h, false);
  vector<bool> pC(w, false);
  rep(i, h) {
    rep(j, w) {
      if (cx[i][j] == '.') continue;
      memR[i][cx[i][j] - 'a'] += 1;
      memC[j][cx[i][j] - 'a'] += 1;
    }
  }

  bool ctn = true;
  while (ctn) {
    ctn = false;
    vector<int> passedR;
    vector<int> passedC;

    rep(i, h) {
      if (pR[i] || !poss(memR[i])) continue;
      ctn = true;
      passedR.push_back(i);
    }
    rep(j, w) {
      if (pC[j] || !poss(memC[j])) continue;
      ctn = true;
      passedC.push_back(j);
    }

    for (auto i : passedR) {
      rep(j, w) {
        if (pC[j] || cx[i][j] == '.') continue;
        memC[j][cx[i][j] - 'a'] -= 1;
        cx[i][j] = '.';
      }
      pR[i] = true;
    }
    for (auto j : passedC) {
      rep(i, h) {
        if (pR[i] || cx[i][j] == '.') continue;
        memR[i][cx[i][j] - 'a'] -= 1;
        cx[i][j] = '.';
      }
      pC[j] = true;
    }
  }

  int ans = 0;
  rep(i, h) {
    rep(j, w) {
      if (cx[i][j] != '.') ans++;
    }
  }
  out(ans);
}
