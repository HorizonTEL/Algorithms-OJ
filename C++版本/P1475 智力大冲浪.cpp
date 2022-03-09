#include<stdio.h>
int main(){
	int n, m;
	while(scanf("%d", &m) != EOF){
		scanf("%d", &n);
		int goods[1000][2], time[600] = {0}, i, j, temp, re = 0;
		for(i = 0; i < n; i++)
			scanf("%d", &goods[i][0]);
		for(i = 0; i < n; i++)
			scanf("%d", &goods[i][1]);
		for(i = 0; i < n - 1; i++){
			for(j = 0; j < n - i - 1; j++){
				if(goods[j][1] < goods[j+1][1] || (goods[j][1] == goods[j+1][1] && goods[j][0] > goods[j+1][0])){
					temp = goods[j][0];
					goods[j][0] = goods[j+1][0];
					goods[j+1][0] = temp;
					
					temp = goods[j][1];
					goods[j][1] = goods[j+1][1];
					goods[j+1][1] = temp;
				}
			}
		}
		for(i = 0; i < n; i++){
			for(j = goods[i][0]; j >= 1; j--){
				if(time[j] == 0)
					break;
			}
			if(j == 0)
				re += goods[i][1];
			else
				time[j] = 1;
		}
		printf("%d\n", m - re);
	}
	return 0;
}
