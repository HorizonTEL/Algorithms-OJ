#include<bits/stdc++.h>
#include<set>
using namespace std;

int main(){
    int minSize, maxSize, n;
    while(cin>>minSize>>maxSize){
    	cin>>n;
    	int fish[10000];
	    for(int i = 0; i < n; i++)
	        cin>>fish[i];
	    int res = 0;
	    for(int k = minSize; k <= maxSize; k++){
	        bool flag = true;
	        for(int i = 0; i < n; i++){
	            if(k >= fish[i] * 2 && k <= fish[i] * 10){
	                flag = false;
	                break;
	            }
	            if(fish[i] <= k * 10 && fish[i] >= k * 2){
	                flag = false;
	                break;
	            }
	        }
	        if(flag)
	            res++;
	    }
    	cout<<res;
	}
    return 0;
}
