#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, k, s;
    scanf("%d", &n);
    scanf("%d", &k);
    vector<long> a(n);
    vector<int> remainders(n,0);
    vector<int> count(k, 0);
    
    for ( int i = 0; i < n; i++ )
    {
        scanf("%ld", &a[i]);
        remainders[i] = a[i] % k;
        count[remainders[i]]++;
    }
    
    s = (count[0] > 0); // only one number divisionable by k might be in the set
    for ( int i = 1; i <= k / 2; i++ )
    {
	if ( i != k - i )
	{
		if ( count[i] > count[k - i])
		    s += count[i];
		else
		    s += count[k - i];
	}
	else
		s += (count[i] > 0);
    }
    printf("%d\n", s);
    
    return 0;
}
