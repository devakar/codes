#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;


// It is NOT mandatory to use the provided template. You can handle the IO section differently.

int main() {
    /* The code required to enter n,k, candies is provided*/

    int N, K;
    int unfairness = numeric_limits<int>::max();
    cin >> N >> K;
    int candies[N];
    for (int i=0; i<N; i++)
        cin >> candies[i];
    
    /** Write the solution code here. Compute the result, store in  the variable unfairness --
    and output it**/
    
    int asc[K];
    int min;
    sort(candies,candies+N);
    for(int j=0;j<N-K+1;j++)
        {
        min=candies[j+K-1]-candies[j];
        if(min<unfairness)
            unfairness=min;
        
    }
    
    
    cout << unfairness << "\n";
    return 0;
}
