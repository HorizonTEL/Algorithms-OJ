#include<bits/stdc++.h>
#include<string>
using namespace std;

string mi[8];
int temp[8][8] = {0};		// 存放方向,上左下右 

void find_road(int x, int y){
	mi[x][y] = 'K';
	if(x == 7 && y == 7)
		return;
	// 下 
	if(x < 7 && mi[x+1][y] == 'O'){
		temp[x+1][y] = 3;
		find_road(x+1, y);
	}
	// 右
	else if(y < 7 && mi[x][y+1] == 'O'){
		temp[x][y+1] = 4;
		find_road(x, y+1);
	}
	// 左 
	else if(y > 0 && mi[x][y-1] == 'O'){
		temp[x][y-1] = 2;
		find_road(x, y-1);
	}
	// 上 
	else if(x > 0 && mi[x-1][y] == 'O'){
		temp[x-1][y] = 1;
		find_road(x-1, y);
	}
	else{
		mi[x][y] = 'P';
		if(temp[x][y] == 1)
			find_road(x+1, y);
		else if(temp[x][y] == 2)
			find_road(x, y+1);
		else if(temp[x][y] == 3)
			find_road(x-1, y);
		else if(temp[x][y] == 4)
			find_road(x, y-1);
	}
}

int main(){
	int t, n, i, j, k;
	string a;
	while(cin>>a){
		mi[0] = a;
		for(i = 1; i < 8; i++)
			cin>>mi[i];
		find_road(0, 0);
		for(i = 0; i < 8; i++){
			for(j = 0; j < 8; j++){
				if(mi[i][j] == 'K')
					cout<<' ';
				else if(mi[i][j] == 'X')
					cout<<'X';
				else
					cout<<'O';
			}
			cout<<endl;
		}
	}
	return 0;
}
