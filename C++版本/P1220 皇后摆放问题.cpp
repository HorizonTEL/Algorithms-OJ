#include<bits/stdc++.h>
#include<vector>
using namespace std;

int exist_x[9] = {0}, exist_y[9] = {0}, exist_sum[17] = {0}, exist_m[17] = {0}; 

void keen_question(int i, int &re){
	if(i > 8)
		re++;
	else if(exist_x[i]){
		keen_question(i+1, re);
	}
	else{
		int j;
		for(j = 1; j <= 8; j++){
			if(exist_y[j] == 0 && exist_m[i - j + 8] == 0 && exist_sum[i + j] == 0){
				exist_y[j] = 1, exist_sum[i + j] = 1, exist_m[i - j + 8] = 1;
				keen_question(i+1, re);
				exist_y[j] = 0, exist_sum[i + j] = 0, exist_m[i - j + 8] = 0;
			}
		}	
	}
} 

int main(){
	int  re = 0, i, j, temp;
	for(i = 1; i <= 8; i++){
		for(j = 1; j <= 8; j++){
			cin>>temp;
			if(temp){
				exist_x[i] = 1, exist_y[j] = 1, exist_sum[i + j] = 1, exist_m[i - j + 8] = 1;
			}
		}
	}
	keen_question(1, re);
	cout<<re<<endl;
}
