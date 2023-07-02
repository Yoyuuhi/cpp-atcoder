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

  int ha, wa;
  cin >> ha >> wa;
  vector<string> ax(ha);
  rep(i, ha) cin >> ax[i];
  int ca = 0;
  rep(i, ha) {
    rep(j, wa) {
      if (ax[i][j] == '#') ca++;
    }
  }

  int hb, wb;
  cin >> hb >> wb;
  vector<string> bx(hb);
  int cb = 0;
  rep(i, hb) cin >> bx[i];
  rep(i, hb) {
    rep(j, wb) {
      if (bx[i][j] == '#') cb++;
    }
  }

  int hx, wx;
  cin >> hx >> wx;
  vector<string> xx(hx);
  rep(i, hx) cin >> xx[i];

  rep2(ia, -ha, hx + 1) {
    rep2(ja, -wa, wx + 1) {
      rep2(ib, -hb, hx + 1) {
        rep2(jb, -wb, wx + 1) {
          bool poss = true;
          int tca = 0;
          int tcb = 0;
          rep(i, hx) {
            rep(j, wx) {
              if (!poss) continue;
              char sa = '.';
              char sb = '.';

              int iia = i - ia;
              int jja = j - ja;
              int iib = i - ib;
              int jjb = j - jb;
              if (iia >= 0 && iia < ha && jja >= 0 && jja < wa) {
                sa = ax[iia][jja];
                if (sa == '#') tca++;
              }

              if (iib >= 0 && iib < hb && jjb >= 0 && jjb < wb) {
                sb = bx[iib][jjb];
                if (sb == '#') tcb++;
              }
              char s = '.';
              if (sa == '#' || sb == '#') s = '#';
              if (s != xx[i][j]) poss = false;
            }
          }
          if (tca < ca || tcb < cb) poss = false;

          if (poss) {
            out("Yes");
            return 0;
          }
        }
      }
    }
  }
  out("No");
}
