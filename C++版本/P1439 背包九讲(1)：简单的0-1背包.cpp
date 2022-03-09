#include<stdio.h>

int max(int x, int y){
	if(x > y)
		return x;
	return y;
}

int main(){
	int v, n, i, j;
	while(scanf("%d", &v) != EOF){
		scanf("%d", &n);
		int temp[30][2000] = {0}, x, goods[30][2];	// 体积,价值 
		for(i = 0; i < n; i++)
			scanf("%d %d", &goods[i][0], &goods[i][1]);
		// 冒泡排序，先按照体积大小对商品排序
		for(i = 0; i < n - 1; i++){
			for(j = 0; j < n - i - 1; j++){
				if(goods[j][0] > goods[j+1][0]){
					x = goods[j][0];
					goods[j][0] = goods[j+1][0];
					goods[j+1][0] = x;
					
					x = goods[j][1];
					goods[j][1] = goods[j+1][1];
					goods[j+1][1] = x;
				}
			}
		}
		for(j = 1; j <= v; j++){
			for(i = 0; i < n; i++){
				if(goods[i][0] > j)
					break;
				if(i == 0)
					temp[i][j] = goods[i][1];
				else
					temp[i][j] = max(temp[i-1][j-goods[i][0]] + goods[i][1], temp[i-1][j]);
			}
		}
		int re = 0;
		for(i = 0; i < n; i++){
			re = max(re, temp[i][v]);
		}
		printf("%d\n", re);
	}
}
