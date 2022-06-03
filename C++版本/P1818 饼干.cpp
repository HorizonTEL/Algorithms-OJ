#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, q, w[200100];
	while(cin>>n>>q){
		int i, j, req;
		w[0] = 0;
		for(i = 1; i <= n; i++){
			cin>>w[i];
			w[i] += w[i-1];
		}
		for(i = 0; i < q; i++){
			cin>>req;
			int start = 1, mid, end = n;
			while(start < end){
				mid = (start + end) / 2;
				if(w[mid] < req)
					start = mid + 1;
				else if (w[mid] > req)
					end = mid;
				else{
					start = mid;
					break;
				}
					
			}
			cout<<start<<" ";
		}
		cout<<endl;
	}
}
