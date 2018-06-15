#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

struct PathPoint {
	int id;
	long distance;
};

struct OrderByDistance
{
    bool operator() (PathPoint const &a, PathPoint const &b) { return a.distance < b.distance; }
};

struct Edge
{
  int begin;
  int end;
  long weight;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int q;
    scanf("%d", &q);
    for ( int i = 0; i < q; i++ )
    {
        int s, v, e;
        scanf("%d", &v);
        scanf("%d", &e);
        vector< vector<Edge> > g(v);
        priority_queue<PathPoint, std::vector<PathPoint>, OrderByDistance> pqueue;
        vector<long> distance(v, INT_MAX);
        
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
        distance[s] = 0;
        
        for ( int i = 0; i < distance.size(); i++ )
        {
            PathPoint pp = { i, distance[i] };
            pqueue.push(pp);
        }
        
        while ( !pqueue.empty() )
        {
            PathPoint u = pqueue.top();
            pqueue.pop();
            
            for ( int j = 0; j < g[u.id].size(); j++ )
            {
		        int v = g[u.id][j].end;
                long weight = g[u.id][j].weight;
                
                if ( distance[u.id] != INT_MAX && distance[v] > distance[u.id] + weight )
                {
                    distance[v] = distance[u.id] + weight; // update shortest distance

                    PathPoint pp = { v, distance[v] };
                    pqueue.push(pp);
                } 
            }
        }
        
        for ( int i = 0; i < distance.size(); i++ )
        {
            if ( distance[i] == INT_MAX )
                distance[i] = -1;
            if ( i != s )
                printf("%ld ", distance[i]);
        }
        printf("\n");
    }
    
    return 0;
}

