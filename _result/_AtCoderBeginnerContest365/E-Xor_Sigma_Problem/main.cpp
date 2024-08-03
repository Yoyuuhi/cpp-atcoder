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
template <typename T>
T tpow(T x, int n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

long long calculate_xor_sum(const vector<ll>& A) {
  int N = A.size();
  long long total_sum = 0;

  // 各ビット位置について計算
  for (int bit = 0; bit < 28; ++bit) {  // 28ビット以内の数値
    vector<int> count_ones(N + 1, 0);
    vector<int> odd_count_ones(N + 1, 0);
    vector<int> even_count_ones(N + 1, 0);

    // 各位置までのビット数の累積を計算
    for (int i = 1; i <= N; ++i) {
      count_ones[i] = count_ones[i - 1] + ((A[i - 1] >> bit) & 1);

      odd_count_ones[i] += odd_count_ones[i - 1];
      if (count_ones[i] % 2 == 1) odd_count_ones[i]++;
      even_count_ones[i] += even_count_ones[i - 1];
      if (count_ones[i] % 2 == 0) even_count_ones[i]++;
    }

    long long bit_sum = 0;
    rep(i, N - 1) {
      if (count_ones[i] % 2 == 0) {
        bit_sum += odd_count_ones[N] - odd_count_ones[i + 1];
      } else {
        bit_sum += even_count_ones[N] - even_count_ones[i + 1];
      }
    }

    total_sum += bit_sum * (1 << bit);
  }

  return total_sum;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;
  auto as = nis(n);

  out(calculate_xor_sum(as));
}
