#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
	int n, k;
	while(cin>>n>>k){
		int i, j, temp = 1, input, re = 0;
		vector<int> m;
		for(i = 1; i <= n; i++){
			cin>>input;
			if(input == k){
				while(temp * 2 <= i)
					temp *= 2;
				m.push_back(i - temp);
			}
		}
		i = 0;
		for(i = 0; i < m.size(); i++){
			if(re >= m[i])
				re += 1;
			else
				re = m[i] + 1;
		}
		cout<<re<<endl;
	}
}

