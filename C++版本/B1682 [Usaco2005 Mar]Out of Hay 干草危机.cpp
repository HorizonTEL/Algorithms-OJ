#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,fat[5001],x,y,v,shu,ans,bian,maxn=-1;
struct chengshi
{
    int x,y,v;
}a[200001];

int fa(int x)
{
    if(fat[x]!=x) fat[x]=fa(fat[x]);
    return fat[x];
}

void lian(int x,int y)
{
    int aa=fa(x),bb=fa(y);
    if(aa!=bb) fat[aa]=bb;
}

int cmp(chengshi a,chengshi b) //¿ìÅÅµÄcmpº¯Êý
{
    if(a.v<b.v) return 1;
    else return 0;
}

int max(int a,int b) {return a>b?a:b;}

int main()
{
    while(cin>>n>>m){
	    for(int i=1;i<=m;i++)
	    {
	        cin>>x>>y>>v;
	        a[i].x=x;
	        a[i].y=y;
	        a[i].v=v;
	    }
	    for(int i=1;i<=n;i++) fat[i]=i;
	    sort(a+1,a+m+1,cmp);
	    for(int i=1;i<=m;i++)
	    {
	        if(fa(a[i].x)!=fa(a[i].y))
	        {
	            lian(a[i].x,a[i].y);
	            ans+=a[i].v;
	            bian++;
	            maxn=max(maxn,a[i].v);
	        }
	    }
	    cout<<maxn<<endl;
	}
    return 0;
}
