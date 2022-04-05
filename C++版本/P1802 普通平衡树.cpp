#include <cstdio>
#include <algorithm>
const int maxlog = 25;
const int MAXN = 100010;
using namespace std;
// 摘自洛谷题解，只能借鉴别人的答案orz 
namespace trie{
	int id = 2;//此时id = 2 
	int ch[MAXN * maxlog][2];
	int sz[MAXN * maxlog];
	//int nval[MAXN * maxlog];
	int newnode(){
		ch[id][0] = ch[id][1] = sz[id] = 0;
		return id++;
	}				
	void ins(int x,int d){			
		int u = 1;			
		for(int i = maxlog - 1;i >= 0;i--){			
			int v = (x >> i) & 1;//必须是左移x 			
			if(!ch[u][v]) ch[u][v] = newnode();			
			u = ch[u][v];		
			sz[u] += d;//sz[1] = 0; 	
		}				
		//nval[u] += d;				
	}										
	int kth(int k){
		int u = 1;
		int x = 0;
		for(int i = maxlog - 1;i >= 0;i--){
			if(sz[ch[u][0]] >= k){	///////////////////////////> >=						
				u = ch[u][0]; 
			}
			else{
				x |= (1 << i);
				k -= sz[ch[u][0]];
				u = ch[u][1];
			}
		}
		return x;
	}
	int nlt(int x){
		int ans = 0;
		int u = 1;
		for(int i = maxlog - 1;i >= 0;i--){
			if((x >> i) & 1){
				ans += sz[ch[u][0]];
				u = ch[u][1];
			}
			else{
				u = ch[u][0];
			}
			if(!u) break;//不必有的 
		}             
		return ans;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
	}	
	void clear(){
		ch[1][0] = ch[1][1] = 0;
		id = 2;
	} 
	int pre(int x){
		int ans;
		//ins(x,1);
		ans = kth(nlt(x));
		//ins(x,-1);
		return ans;
	}
	int next(int x){
		int ans;
		//ins(x,1);
		ans = kth(nlt(x+1)+1);
		//ins(x,-1);
		return ans;
	}
} 

const int num = 10000000; 
int main(){
	 int n;
	 scanf("%d",&n);
	 for(int i = 0;i < n;i++){
	 	int ord,t;
	 	scanf("%d%d",&ord,&t);
		switch(ord){
			case 1:trie::ins(t + num,1);break;
			case 2:trie::ins(t + num,-1);break;
			case 3:printf("%d\n",trie::nlt(t + num) + 1);break;
			case 4:printf("%d\n",trie::kth(t) - num);break;
			case 5:printf("%d\n",trie::pre(t + num) - num);break;
			case 6:printf("%d\n",trie::next(t + num) - num);break;
		}
	}
	return 0;
} 
