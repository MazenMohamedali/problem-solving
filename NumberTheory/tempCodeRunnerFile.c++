map<int , int> primeFactorization(ll n) {
    map < int , int > res;
    for(int i = 2; i < N; i++) {
        int k, v = 0;
        if(isPrimes[i]) {
            k = i;
            while (n % isPrimes[i])
            {
                ++v;
                n /= isPrimes[i];
            }
            if(v > 0) {
                res.insert(k, v);
                v = 0;
            }
        }
    }
    if(n != 1)
        res[n]++;
    return res;
}