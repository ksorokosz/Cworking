#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge
{
  int begin;
  int end;
  long weight;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int q = 1;
    for ( int t = 0; t < q; t++ )
    {
        int s, v, e;
        scanf("%d", &v);
        scanf("%d", &e);
        vector< vector<Edge> > g(v);
        vector<long> weights(v, INT_MAX);
        vector<bool> flags(v, false);
        long cost = 0;
        
        for ( int edge = 0; edge < e; edge++)
        {
            int v1, v2;
            long w;
            scanf("%d", &v1);
            scanf("%d", &v2);
            scanf("%ld", &w);
            Edge egf = { v1 - 1, v2 - 1, w };
            Edge egr = { v2 - 1, v1 - 1, w };
            g[v1-1].push_back(egf);
            g[v2-1].push_back(egr);
        }
        scanf("%d", &s);
        s -= 1;
        weights[s] = 0;
        
        for ( int i = 0; i < v; i++ )
        {
            long minimum = INT_MAX;
            int u;
            for ( int j = 0; j < weights.size(); j++ )
            {
                if ( weights[j] < minimum && !flags[j] ) 
                {
                    minimum = weights[j];
                    u = j;
                }
            }
            flags[u] = true;
            cost += minimum;
            
            for ( int j = 0; j < g[u].size(); j++ )
            {
                int vx = g[u][j].end;
                long weight = g[u][j].weight;
                if ( !flags[vx] && weights[vx] > weight ) // not in tree and minimum
                {
                    weights[vx] = weight;
                }
            }
        }
        
        printf("%ld\n", cost);
    }
    
    return 0;
}
