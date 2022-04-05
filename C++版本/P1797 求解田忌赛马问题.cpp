#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
	int n, i, j, ii, jj;
	while(cin>>n){
		int qiwei[100001], tianji[100001], re = 0;
		for(i = 0; i < n; i++)
			cin>>tianji[i];
		for(i = 0; i < n; i++)
			cin>>qiwei[i];
		sort(tianji, tianji + n);
		sort(qiwei, qiwei + n);
		i = 0, j = 0, ii = n - 1, jj = n - 1;
		while(i <= ii){
			if(tianji[ii] > qiwei[jj]){
				re++;
				ii--, jj--;
			}
			else if(tianji[ii] < qiwei[jj])
			{
				re--;
				jj--, i++;
			}
			else{
				if(tianji[i] > qiwei[j]){
					re++;
					i++, j++;
				}
				else{
					if(tianji[i] < qiwei[jj])
						re--;
					i++, jj--;
				}
			}
		}
		cout<<re * 200<<endl;
	}
	return 0;
}
