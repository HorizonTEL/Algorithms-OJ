#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
	int n, m, i, j;
	while(cin>>n>>m){
		int vex[300], cha[300];
		for(i = 0; i < n;i ++)
			cin>>vex[i];
		sort(vex, vex + n);
		for(i = 1; i < n; i++)
			cha[i-1] = vex[i] - vex[i-1];
		sort(cha, cha + n - 1);
		int re = vex[n - 1] - vex[0] + 1;
		while(m >= 2){
			re = re - cha[--n-1] + 1;
			m--;
		}
		cout<<re<<endl;
	}
	return 0;

