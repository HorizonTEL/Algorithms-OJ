#include<bits/stdc++.h>
#include<map>
#include <algorithm>
using namespace std;

int main(){
	int t, n, i, j, k;
	cin>>t;
	for(k = 0; k < t; k++){
		cin>>n;
		int a[2100], b[2100], c[2100], d[2100], re = 0;
		map<int,int> t1;
		for(j = 0; j < n; j++)
			scanf("%d %d %d %d", &a[j], &b[j], &c[j], &d[j]);
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++)
				t1[a[i] + b[j]]++;
		}
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if(t1.count(-c[i] - d[j]))
					re += t1[-c[i] - d[j]];
			}
				
		}
		printf("%d\n", re);
	}
	return 0;
}