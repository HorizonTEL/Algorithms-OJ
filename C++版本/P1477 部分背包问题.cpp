#include<stdio.h>
typedef struct{
	int m;
	int v;
	double e;	// 每单位重量的价值 
}goods;

int main(){
	int n, t, i, j;
	while(scanf("%d  %d", &n, &t) != EOF){
		goods goods[150], temp;
		for(i = 0; i < n; i++){
			scanf("%d %d", &goods[i].m, &goods[i].v);
			goods[i].e = (double) goods[i].v / (double) goods[i].m;
		}
		for(i = 0; i < n - 1; i++){
			for(j = 0; j < n - i - 1 ; j++){
				if(goods[j].e < goods[j+1].e){
					temp = goods[j];
					goods[j] = goods[j+1];
					goods[j+1] = temp;
				}
			}
		}
		double re = 0.0;
		int weight = 0;
		for(i = 0; i < n; i++){
			if(weight + goods[i].m > t){
				re += (t - weight) * goods[i].e;
				break;
			}
			re += goods[i].v;
			weight += goods[i].m;
		}
		printf("%.2lf\n", re);
	}
	return 0;
}
