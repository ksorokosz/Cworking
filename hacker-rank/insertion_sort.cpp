#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n = 0;
    scanf("%d", &n);
    vector<int> a(n);
    for ( int i = 0; i < n; i++ )
        scanf("%d", &a[i]);
    for ( int i = 1; i < n; i++ )
    {
        int element = a[i];
        int j = i - 1;
        while( j >= 0 && a[j] > element)
        {
            a[j+1] = a[j];
            j--;
            
            for ( int k = 0; k < n; k++ )
                printf("%d ", a[k]);
            printf("\n");
        }
        a[j+1] = element;
        if ( j != i - 1 )
        {
            for ( int k = 0; k < n; k++ )
                printf("%d ", a[k]);
            printf("\n");
        }
    }
    return 0;
}

