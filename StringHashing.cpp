#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
using namespace std;


using ll = int64_t;
ll P, Q, R;
bool no_prime_mod_check;


using bigint = unsigned long long;

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


vector<bigint> DPPowerModSub;
vector<bigint> DP;
vector<bigint> Power;
vector<bigint> PowerDP2;

bigint modDivide(bigint a, bigint b, bigint m)
{

    //can we actually divide on the spot? 

    if (DPPowerModSub[b] == 0)
        DPPowerModSub[b] = PowerModulus(Power[b], m - 2, m); 

    return mul_mod(a, DPPowerModSub[b], m);

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


//Primes: 

bigint prime = 281474976710597;

bigint Hash(string& Input, ll First, ll Last) {

    bigint Result = 0;
    bigint previousPower = 1; 

    for (auto Character = First; Character < Last; Character++) {




        bigint x = mul_mod(Input[Character], previousPower, prime);
        Result = add_mod(Result, x, prime);
        DP[Character] = Result;
        
        Power[Character] = previousPower; 

        previousPower = mul_mod(previousPower, 32, prime); 

    }

    return Result;

}

bigint TestHash(string& Input, ll First, ll Last) {

    bigint Result = 0;

    for (auto Character = First; Character < Last; Character++) {
        bigint x = mul_mod(Input[Character], PowerModulus(32, Character - First, prime), prime);
        Result = add_mod(Result, x, prime);

    }

    return Result;

}


bigint SubHash(std::string& Text, ll First, ll Last) {


    bigint powmod = Power[First];

    bigint FirstHash, LastHash = DP[Last - 1];

    if (First == 0)
        FirstHash = 0;
    else
        FirstHash = DP[First - 1];

    bigint S = sub_mod(LastHash, FirstHash, prime);
    bigint T = modDivide(S, First, prime);


    return T;


}

struct Query {
    int First, Last;

};

int main() {
   std::ios_base::sync_with_stdio(false);
std::cin.tie(nullptr);
    vector<Query> Queries;
    Queries.resize(3000000);
    Power.resize(300000); 
    DPPowerModSub = std::vector<bigint>(300000, 0); 

    string Text;
    int QueuryCount;
    cin >> Text;
    cin >> QueuryCount;

    DP.resize(Text.size());

    for (int i = 0; i < QueuryCount; i++) {

        cin >> Queries[i].First;
        cin >> Queries[i].Last;     
    }

    Hash(Text, 0, Text.size());

    bigint tot = 0; 

    for (int i = 0; i < QueuryCount; i++) {

        std::cout << SubHash(Text, Queries[i].First, Queries[i].Last) << '\n';
    }

}
