#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int M, N, R;
    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &R);
    int circles = M < N ? M / 2 : N / 2;
    vector< vector<int> > matrix(N);
    vector< vector<int> > map(N);
    
    for ( int i = 0; i < N; i++ )
    {
        for ( int j = 0; j < M; j++ )
        {
            int element;
            scanf("%d", &element);
            matrix[i].push_back(element);
            
            int circle;
            if ( M < N )
            {
                circle = j < M / 2 ? j : M - 1 - j;
                circle = N - 1 - i <= circle ? N - 1 - i : circle;
                circle = i <= circle ? i : circle;
            }
            else
            {
                circle = i < N /2 ? i : N - 1 - i;
                circle = j <= circle ? j : circle;
                circle = M - 1 - j <= circle ? M - 1 - j : circle;   
            }
            
            map[i].push_back(circle);
        }
    }
    
    for ( int c = 0; c < circles; c++ )
    {
        vector<int> circle_path;
        vector< pair<int,int> > idx;
        
        // move right
        int x = c;
        int y = c;
        while( y < M && map[x][y] == c )
        {
            idx.push_back(pair<int,int>(x,y));
            circle_path.push_back(matrix[x][y++]);
        }   
        // move down
        x++;
        y--;
        while( x < N && map[x][y] == c )
        {
           idx.push_back(pair<int,int>(x,y));
           circle_path.push_back(matrix[x++][y]);
        }
        // move left
        y--;
        x--;
        while ( y >= 0 && map[x][y] == c )
        {
            idx.push_back(pair<int,int>(x,y));
            circle_path.push_back(matrix[x][y--]);
        }
        
        // move up
        x--;
        y++;
        while ( x > c && map[x][y] == c )
        {
            idx.push_back(pair<int,int>(x,y));
            circle_path.push_back(matrix[x--][y]);
        }   
        
        for ( int i = 0; i < circle_path.size(); i++ )
        {
            int element = circle_path[(i + R) % circle_path.size()];
            matrix[idx[i].first][idx[i].second] = element;
        }
    }
    
    
    for ( int i = 0; i < N; i++ )
    {
        for ( int j = 0; j < M; j++ )
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
