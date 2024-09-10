#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 1000001;  
bool primes[MAX_N];

void SieveOfEratosthenes() {
    memset(primes, true, sizeof(primes));
    primes[0] = primes[1] = false;

    for (int p = 2; p * p < MAX_N; p++) {
        if (primes[p] == true) {
            for (int i = p * p; i < MAX_N; i += p)
                primes[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    SieveOfEratosthenes();

    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        cout << (primes[x] ? "YES\n" : "NO\n");
    }

    return 0;
}