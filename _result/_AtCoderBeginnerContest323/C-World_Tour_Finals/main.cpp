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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> as(m);
  rep(i, m) {
    int a;
    cin >> a;
    as[i] = {a, i};
  }
  vector<string> ss(n);
  rep(i, n) cin >> ss[i];

  vector<int> scores(n, 0);
  rep(i, n) {
    scores[i] += i + 1;
    rep(j, m) {
      auto c = ss[i][j];
      if (c == 'o') {
        scores[i] += as[j].first;
      }
    }
  }

  sort(all(as), greater<pair<int, int>>());
  rep(i, n) {
    int count = 0;
    int score = scores[i];
    bool poss = true;
    rep(J, n) {
      if (i == J) continue;
      if (scores[J] >= score) {
        poss = false;
        break;
      }
    }
    if (poss) {
      out(count);
      continue;
      ;
    }
    for (auto a : as) {
      int j = a.second;
      if (ss[i][j] == 'o') continue;
      count++;
      score += a.first;
      bool poss = true;
      rep(J, n) {
        if (i == J) continue;
        if (scores[J] >= score) {
          poss = false;
          break;
        }
      }
      if (poss) {
        out(count);
        break;
      }
    }
  }
}
