#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m, i, j, end = 0, len, first, re = 0;
	cin>>n>>m;
	for(i = 0; i < n; i++){
		cin>>first>>len;
		if(end >= m)
			continue;
		if(first > end){
			if(first >= m)
				re = re + m - end;
			else
				re = re + first - end;
			end = first + len;
		}
		else if(first <= end && (first + len >= end))
			end = first + len;
	}
	if(end < m)
		re = re + m - end;
		
	cout<<re<<endl;
}
