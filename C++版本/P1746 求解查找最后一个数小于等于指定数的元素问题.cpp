#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[110000], n, m;
	a[0] = -1;
	while(cin>>n>>m){
		int i, j;
		for(i = 1; i <= n; i++)
			cin>>a[i];
		for(i = 0; i < m; i++){
			int temp;
			cin>>temp;
			int start = 1, end = n, mid;
			while(start <= end){
				mid=(start + end) / 2;
				if(a[mid] <= temp)
			    	start = mid + 1;
			   	else
			    	end = mid - 1;
			  	}
			cout<<a[end]<<endl;
		}
	}
	return 0;
}
