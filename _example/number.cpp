// https://algo-logic.info/is-prime/
/*  is_prime(n)
    入力：整数 n
    出力：nが素数かの真偽値
    計算量：O(√n)
*/
bool is_prime(long long n) {  // is n prime or not
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

/*  make_is_prime(N)
    入力：整数 N
    出力：N までの数字が素数か判定したベクトル（i番目がtrueならiは素数）
    計算量：O(nloglogn)
*/
vector<bool> make_is_prime(int N) {
  vector<bool> prime(N + 1, true);
  if (n >= 0) prime[0] = false;
  if (n >= 1) prime[1] = false;
  for (int i = 2; i * i <= N; i++) {
    if (!prime[i]) continue;
    for (int j = i * i; j <= N; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}

vector<int> get_primes(int N) {
  vector<int> primes;
  vector<bool> prime(N + 1, true);
  if (n >= 0) prime[0] = false;
  if (n >= 1) prime[1] = false;
  for (int i = 2; i <= N; i++) {
    if (!prime[i]) continue;
    for (int j = i * i; j <= N; j += i) {
      prime[j] = false;
    }
    primes.push_back(i);
  }
  return primes;
}

// https://algo-logic.info/euclidean-algolithm/
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

// https://algo-logic.info/divisor/
vector<long long> divisor(long long n) {
  vector<long long> ret;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n) ret.push_back(n / i);
    }
  }
  sort(ret.begin(), ret.end());
  // 昇順に並べる
  return ret;
}

// https://algo-logic.info/prime-fact/
/*  prime_factor(n)
    入力：整数 n
    出力：nの素因数分解
    計算量：O(√n)前後
*/
template <typename T>
vector<pair<T, T>> prime_factor(T n) {
  vector<pair<T, T>> ret;
  for (T i = 2; i * i <= n; i++) {
    if (n % i != 0) continue;
    T tmp = 0;
    while (n % i == 0) {
      tmp++;
      n /= i;
    }
    ret.push_back(make_pair(i, tmp));
  }
  if (n != 1) ret.push_back(make_pair(n, 1));
  return ret;
}
