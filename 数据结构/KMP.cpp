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
void getnextval(int next[],string sc)
{
    int i,n;
    int nextval[MaxSize];
    n = sc.length();
    for(i = 1; i < n; i++)
    {
        if(sc[i] == sc[next[i]])
        nextval[i] = nextval[next[i]];
        else
        nextval[i] = next[i];
    }
    for(i = 0; i < n; i++)
    cout<<nextval[i]<<' ';
    cout<<endl;
    return;
}
int KMP(string s,string sc)
{
    int n,i,m,ans = 0,k;
    int next[MaxSize];
    n = sc.length();
    m = s.length();
    getnext(next,sc);
    for(i = 0; i < n; i++)
    cout<<next[i]<<' ';
    cout<<endl;
    getnextval(next,sc);
    k = -1,i = 0;
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