#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct element
{
    int e;
    int prev;
    int max;
} element;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, n;
    cin >> T;
    for ( int i = 0; i < T; i++ )
    {
        cin >> n;
        vector<element> contignous(n);
        int non_contignous_max = 0;
	int contignous_max = 0;
        for ( int j = 0; j < n; j++ )
        {
            int e;
            cin >> e;
            if ( e > 0 )
                non_contignous_max += e;
            contignous[j].e = e;

            if ( j > 0 )
            {
 		 contignous[j].prev = contignous[j-1].e + e;
                 contignous[j].max = e > contignous[j].prev ? e : contignous[j].prev;

                 if ( contignous[j-1].max + e > contignous[j].max )
                     contignous[j].max = contignous[j-1].max + e;
		 if ( contignous_max < contignous[j].max)
                     contignous_max = contignous[j].max;
            }
            else
	    {
                 contignous[j].prev = 0;
                 contignous[j].max = e;
                 contignous_max = e;
            }
        }

	if ( contignous_max < 0 )
		non_contignous_max = contignous_max;

        cout << contignous_max << " " << non_contignous_max << endl;
    }
    return 0;
}

