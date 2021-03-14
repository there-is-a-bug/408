#include <iostream>
#include <algorithm>
int MaxSize = 10000;
using namespace std;
void getnext(int next[],string sc)
{
    int n;
    n = sc.length();
    next[0] = -1;next[1] = 0;
    int k = -1,j = 0;
    while(j < n)
    {
        if(sc[k] == sc[j] || k == -1)
        {
            k++;j++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}
int KMP(string s,string sc)
{
    int n,i,m,ans = 0,k;
    int next[MaxSize];
    n = sc.length();
    m = s.length();
    k = -1,i = 0;
    getnext(next,sc);
    while(i < m)
    {
        if(sc[k] == s[i] || k == -1)
        {
            k++;i++;
        }
        else
        {
            k = next[k];
        }
        if(k == n)
        {
            ans = i - n;
            break;
        }
    }
    return ans;
}
int main()
{
    int ans;
    string s;
    getline(cin,s);
    string sc;
    getline(cin,sc);
    ans = KMP(s,sc);
    cout<<ans<<endl;
    return 0;
}