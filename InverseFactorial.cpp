#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#pragma GCC optimize ("O3")
using namespace std;

using bigint = unsigned long long;
bigint prime = 7760017;

bigint mul_mod(bigint a, bigint b, bigint m)
{
    if (!((a | b) & (0xFFFFFFFFULL << 32)))
        return a * b % m;

    bigint d = 0, mp2 = m >> 1;
    int i;
    if (a >= m) a %= m;
    if (b >= m) b %= m;
    for (i = 0; i < 64; ++i)
    {
        d = (d > mp2) ? (d << 1) - m : d << 1;
        if (a & 0x8000000000000000ULL)
            d += b;
        if (d >= m) d -= m;
        a <<= 1;
    }
    return d;
}

bigint PowerModulus(bigint a, bigint b, bigint m)
{
    bigint r = m == 1 ? 0 : 1;
    while (b > 0) {
        if (b & 1)
            r = mul_mod(r, a, m);
        b = b >> 1;
        a = mul_mod(a, a, m);
    }
    return r;
}


bigint divisor(bigint number)
{
    bigint i;
    for (i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return number / i;
        }
    }
    return 1;
}

bigint modDivide(bigint a, bigint b, bigint m)
{

    return mul_mod(a, PowerModulus(b, m - 2, m), m);

}

bigint sub_mod(bigint a, bigint b, bigint m)
{
    if (a >= b)
        return a - b;
    else
        return m - b + a;
}

bigint add_mod(bigint a, bigint b, bigint m)
{
    if (0 == b) return a;

    // return sub_mod(a, m-b, m);
    b = m - b;
    if (a >= b)
        return a - b;
    else
        return m - b + a;
}


//#define DEBUG

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    bigint NumberModulo = 0;
    bigint PowerModulo = 1;

    string s; 
    cin >> s; 

    for (int ci = 0; ci < s.size(); ci++) {

        char c = s[s.size() - ci - 1];
        int digit = c - '0';

        NumberModulo = add_mod(NumberModulo, mul_mod(PowerModulo, digit, prime), prime);

        PowerModulo = mul_mod(10, PowerModulo, prime);
    }


    if (NumberModulo == 1) {
        std::cout << "1\n"; 
        return 0; 
    }
    
    bigint i = 1;

    while (i++) {
        NumberModulo = modDivide(NumberModulo, i, prime);
        if (NumberModulo == 1) {
            std::cout << i << '\n';
            break; 
        }
    }
}
