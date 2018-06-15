#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin >> q;
    for ( int i = 0; i < q; i++ )
    {
        int s, v, e;
        cin >> v >> e;
        vector< vector<int> > g(v);
        queue<int> bqueue;
        vector<int> distance(v,0);
        vector<bool> visited(v,0);
        for ( int edge = 0; edge < e; edge++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            g[v1-1].push_back(v2-1);
            g[v2-1].push_back(v1-1);
        }
        cin >> s;
        s -= 1;
        
        bqueue.push(s);
        while ( !bqueue.empty() )
        {
            int u = bqueue.front();
            bqueue.pop();
            for ( int j = 0; j < g[u].size(); j++ )
            {
		int vx = g[u][j];
                if ( !visited[vx] )
                {
                    distance[vx] = distance[u] + 1;
                    bqueue.push(vx);
		    visited[vx] = 1;
                }
            }
            visited[u] = 1;
        }
    }
    return 0;
}

