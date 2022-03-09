#include<stdio.h>

int max(int x, int y){
	if(x > y)
		return x;
	return y;
}

int main(){
	int m, n, i, j;
	while(scanf("%d  %d", &m, &n) != EOF){
		int v[1005][1005], re[1005][1005] = {0};
		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++)
				scanf("%d", &v[i][j]);	
		}
		for(j = 0; j < n; j++){
			for(i = 0; i < m; i++){
				if(j == 0 & i == 0)
					re[i][j] = v[i][j];
				else if(j == 0)
					re[i][j] = re[i-1][j] + v[i][j];
				else if(i == 0)
					re[i][j] = re[i][j-1] + v[i][j];
				else
					re[i][j] = max(re[i-1][j], re[i][j-1]) + v[i][j];
			}
		}
		printf("%d\n", re[m-1][n-1]);
	}
	return 0;
}
