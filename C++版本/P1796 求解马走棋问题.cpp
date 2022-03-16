#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m, i, j;
	cin>>m>>n;
	int temp[700][700] = {0};
	temp[1][1] = 1;
	for(j = 2; j <= m; j++){
		for(i = 1; i <= n; i++){
			if(j >= 3){
				if(i >= 2)
					temp[i][j] += temp[i-1][j-2];
			}
			if(j >= 2){
				if(i >= 3)
					temp[i][j] += temp[i-2][j-1];
			}
		}
	}
	cout<<temp[n][m]<<endl;
	return 0;
}
