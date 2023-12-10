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

int h, w;
vector<vector<int>> ax, bx;

int calc1(vector<int> R, vector<int> C) {
  int ans = 0;
  vector<bool> memR(h, false);
  rep(i, h) {
    int r = R[i];
    int count = 0;
    rep(ii, h) {
      if (memR[ii]) {
        count++;
        continue;
      }
      if (r == ii) {
        ans += ii - count;
        memR[ii] = true;
        break;
      }
    }
  }
  vector<bool> memC(w, false);
  rep(j, w) {
    int c = C[j];
    int count = 0;
    rep(jj, w) {
      if (memC[jj]) {
        count++;
        continue;
      }
      if (c == jj) {
        ans += jj - count;
        memC[jj] = true;
        break;
      }
    }
  }
  return ans;
}

int calc() {
  vector<int> R;
  rep(i, h) R.push_back(i);
  vector<int> C;
  rep(j, w) C.push_back(j);
  int ans = INF;
  do {
    do {
      vector<vector<int>> temp;
      for (auto i : R) {
        vector<int> t;
        for (auto j : C) {
          t.push_back(ax[i][j]);
        }
        temp.push_back(t);
      }
      if (temp == bx) ans = min(ans, calc1(R, C));
    } while (next_permutation(all(C)));
  } while (next_permutation(all(R)));

  if (ans != INF) return ans;
  return -1;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> h >> w;
  ax.resize(h);
  bx.resize(h);
  rep(i, h) ax[i] = nis(w);
  rep(i, h) bx[i] = nis(w);
  out(calc());
}
