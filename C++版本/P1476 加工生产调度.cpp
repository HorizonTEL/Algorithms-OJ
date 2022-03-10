#include<stdio.h>

typedef struct{
	int a;
	int b;
	int ab;
	int m;
	int if_a;
}time;

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		time all[1200], al[1200], temp;
		int i, j, k;
		for(i = 0; i < n; i++)
			scanf("%d", &all[i].a);
		for(i = 0; i < n; i++){
			scanf("%d", &all[i].b);
			all[i].ab = all[i].a - all[i].b;
			if(all[i].ab > 0){
				all[i].m = all[i].b;
				all[i].if_a = 0;
			}
			else{
				all[i].m = all[i].a;
				all[i].if_a = 1;
			}
		}
		for(i = 0; i < n - 1; i++){
			for(j = 0; j < n - i - 1; j++){
				if(all[j].m > all[j+1].m){
					temp = all[j];
					all[j] = all[j+1];
					all[j+1] = temp;
				}
			}
		}
		j = 0, k = n - 1;
		for(i = 0; i < n; i++){
			if(all[i].if_a == 0)
				al[k--] = all[i];
			else
				al[j++] = all[i];
		}
		int re = 0, des = 0;
		for(i = 0; i < n; i++){
			if(al[i].ab < des){
				des -= al[i].ab;
				re += al[i].b;
			}
			else{
				re = re + al[i].a + al[i].b - des;
				des = al[i].b;
			}
		}
		printf("%d\n", re);
	}
	return 0;
}
