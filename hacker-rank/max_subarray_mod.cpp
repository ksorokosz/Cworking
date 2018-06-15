#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long T, n, m;
    cin >> T;
    for ( int i = 0; i < T; i++ )
    {
        cin >> n >> m;
        map<long, int> remainders;
        map<long, int>::iterator it;
	    long max = 0;
        long sum = 0;
        for ( int j = 0; j < n; j++ )
        {
            long e;
            cin >> e;
            e %= m;
            sum += e;
            sum %= m;
                        
            remainders[sum] = j;
        }
        
        long prefix = (*remainders.begin()).first;
        int index  = (*remainders.begin()).second;
        for ( it = remainders.begin(); it != remainders.end(); it++ )
        {
            if ( (*it).second < index )
            {
                long difference = (*it).first - prefix;
                if ( max < m - difference )
                    max = m - difference;
            }
            if ( max < (*it).first )
                max = (*it).first;
            
            prefix = (*it).first;
            index  = (*it).second;
        }
        
        printf("%ld\n", max);
    }
    return 0;
}

