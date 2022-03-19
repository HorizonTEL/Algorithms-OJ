#include<bits/stdc++.h>
#include<map>
using namespace std;

int main(){
	int a[1000100], count = 0, i, j, n;
	bool temp[1000100] = {0};
	long long int re = 1;
	cin>>n;
	for(i = 1; i <= n; i++)
		cin>>a[i];
	i = 1;
	while(i <= n){
		if(!temp[i]){
			map<int, int> b;
			j = i;
			while(!temp[j]){
				b[j] = 1;
				temp[j] = 1;
				j = a[j];
			}
			if(b[j]){
				count++;
				temp[j] = 1;
			}
		}
		i++;
	}
	while(count--)
		re = re * 2 % 998244353;
	cout<<re-1<<endl;
}
