#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>
using namespace std;

uint64_t calc(uint64_t n, uint64_t m) {
    uint64_t result = 1;
    for (uint64_t i = n * m - 1; i > 1; --i) {
        result *= i;
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        uint64_t n, m;
        cin >> n >> m;
        
        cout << calc(n, m) << endl;
        
    }
    return 0;
}
