#include<stdio.h>
int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		if(n == 2){
			int a, b;
			scanf("%d %d", &a, &b);
			if(a > b)
				printf("%.1lf\n", (double)b);
			else
				printf("%.1lf\n", (double)a);
		}
		else{
			int sum = 0, temp;
			for(int i = 0; i < n; i++){
				scanf("%d", &temp);
				sum += temp;
			}
			printf("%.1lf\n", (double)sum / 2.0);
		}
	}
	return 0;
}
