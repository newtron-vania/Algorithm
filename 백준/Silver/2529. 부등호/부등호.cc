#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(vector<int> &perm, vector<char> &vec)
{
    for(int i=0; i<vec.size(); i++)
    {
        if(vec[i]=='<' && perm[i] > perm[i+1]) return false;
        if(vec[i]=='>' && perm[i] < perm[i+1]) return false;
    }
    return true;
}

int main(void)
{
    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int k;
    cin >> k;
    
    vector<char> vec(k);
    for(int i=0; i<k; i++)
    {
        cin >> vec[i];
    }
    
    vector<int> small(k+1);
    vector<int> big(k+1);
    
    for(int i=0; i<=k; i++)
    {
        small[i] = i;
        big[i] = 9-i;
    }
    
    do
    {
        if(check(small, vec)) break;
    }while(next_permutation(small.begin(),small.end()));
    
    do
    {
        if(check(big, vec)) break;
    }while(prev_permutation(big.begin(), big.end()));
    
    for(int i=0; i<big.size(); i++)
    {
        cout << big[i];
    }
    cout << '\n';
    
    for(int i=0; i<small.size(); i++)
    {
        cout << small[i];
    }
    cout << '\n';
    
    return 0;
}