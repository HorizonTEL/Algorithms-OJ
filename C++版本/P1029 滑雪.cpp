#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

typedef struct{
	int x;	// ���� 
	int y;	// ���� 
	int height;
	int dp;
}area;

bool cmpare(const area &a, const area &b)            //const����ӣ���Ȼ���Ŀǰ����Ϊɶ����return����tureʱ��a�����������ʾ����������
{
     return a.height < b.height;
}

int main(){
	int i, j, a ,b;
	while(scanf("%d %d", &a, &b) != EOF){
		area loca[10000], loca1[120][120];
		int re = 0, x ,y;
		for(i = 0; i < a; i++){
			for(j = 0; j < b; j++){
				scanf("%d", &loca[a * i + j].height);
				loca[a * i + j].dp = 1;
				loca[a * i + j].x = i;
				loca[a * i + j].y = j;
				// Ϊ�˷���Ѱ�� 
				loca1[i][j] = loca[a * i + j];
			}
		}
		sort(loca, loca+a*b, cmpare);
		for(i = 0; i < a*b; i++){
			x = loca[i].x, y = loca[i].y;
			if(x != 0 && loca1[x-1][y].height < loca1[x][y].height)
				loca1[x][y].dp = max(loca1[x-1][y].dp + 1, loca1[x][y].dp);
			if(y != 0 && loca1[x][y-1].height < loca1[x][y].height)
				loca1[x][y].dp = max(loca1[x][y-1].dp + 1, loca1[x][y].dp);
			if(x != (a - 1) && loca1[x+1][y].height < loca1[x][y].height)
				loca1[x][y].dp = max(loca1[x+1][y].dp + 1, loca1[x][y].dp);
			if(y != (b - 1) && loca1[x][y+1].height < loca1[x][y].height)
				loca1[x][y].dp = max(loca1[x][y+1].dp + 1, loca1[x][y].dp);
		}
		for(i = 0; i < a; i++){
			for(j = 0; j < b; j++)
				re = max(re, loca1[i][j].dp);
		}
		printf("%d\n", re);
	}
	return 0;
}
