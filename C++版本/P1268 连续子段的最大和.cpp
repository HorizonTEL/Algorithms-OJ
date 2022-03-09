#include<stdio.h>
int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int i = 0, max, temp, re;
		for(i = 0; i < n; i++){
			scanf("%d", &temp);
			if(i == 0)
				max = temp, re = temp;
			else{
				if(max >= 0)
					max += temp;
				else
					max = temp;
				if(re < max)
					re = max;
			}
		}
		printf("%d\n", re);
	}
	return 0;
}
