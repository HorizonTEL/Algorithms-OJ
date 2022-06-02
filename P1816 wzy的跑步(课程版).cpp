#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int n, m, k, i, j, temp;
		int re[10010], shui[10010] = {0};
		cin>>n>>m>>k;
		for(i = 0; i <= n; i++)
			re[i] = 99999;
		for(i = 0; i < m; i++){
			cin>>temp;
			shui[temp] = 1;
		}
		re[1] = shui[1];
		for(i = 1; i <= n; i++){
			for(j = max(1, i - k); j < i; j++){
				re[i] = min(re[i], re[j] + shui[i]);
			}
		}
		cout<<re[n]<<endl;
	}
	return 0;
}
