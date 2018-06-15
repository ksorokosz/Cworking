#include <bits/stdc++.h>
#include <vector>
using namespace std;

int partition( vector<int>& arr, int lo, int hi )
{
    int p = arr[lo];
    int i = lo - 1;
    int j = hi + 1;
    
    // hoare partition scheme
    while ( true )
    {
        do {
            i++;
        }while ( arr[i] < p );
        
        do {
            j--;
        }while ( arr[j] > p );
        
        if ( i >= j )
            return j;
               
        // swap
        int element = arr[i];
        arr[i] = arr[j];
        arr[j] = element;
    }
}

void quicksort(vector <int> &arr, int lo, int hi) 
{
   // Complete this function
   if ( lo < hi )
   {
       int p = partition(arr, lo, hi);
       quicksort(arr, lo, p);
       quicksort(arr, p+1, hi);
   }
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quicksort(arr, 0, arr.size() - 1);

    for ( int i = 0; i < arr.size(); i++ )
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

