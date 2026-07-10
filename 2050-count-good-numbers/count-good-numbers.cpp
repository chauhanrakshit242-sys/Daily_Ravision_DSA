class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long x, long long n) {
        if (n == 0)
            return 1;

        long long half = power(x, n / 2);

        if (n % 2 == 0)
            return (half * half) % MOD;

        return (((half * half) % MOD) * x) % MOD;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % MOD;
    }
};