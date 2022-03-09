#include<stdio.h>
#include<math.h>

char a[700][700];

void fun(int n, int x, int y){
	if(n == 1){
		a[x][y] = 'X';
		return ;
	}
	int size = (int) pow(3.0, n-2);
	fun(n-1, x, y);
	fun(n-1, x, y + 2 * size);
	fun(n-1, x + size, y + size);
	fun(n-1, x + 2 * size, y);
	fun(n-1, x + 2 * size, y + 2 * size);
	return;
}

int main(){
	int i, j, n;
	while(scanf("%d", &n) != EOF){
		int size = (int) pow(3.0, n-1);
		for(i = 0; i < size; i++){
			for(j = 0; j < size; j++)
				a[i][j] = ' ';
		}
		fun(n, 0, 0);
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
				printf("%c", a[i][j]);
			printf("\n");	
		}
		printf("-\n");
	}
	return 0;
}
