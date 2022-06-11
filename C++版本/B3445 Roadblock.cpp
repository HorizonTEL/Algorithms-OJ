#include<bits/stdc++.h>
using namespace std;

const int inf = 99999999;
int n, m;

int vis[255], dist[255];

struct edge{
	int v, w;
	int num;
};

struct qnode{
	int v, w;
	bool operator< (const qnode &a) const
	{
		return w > a.w ;
	}
};
priority_queue<qnode> q;
vector<edge> mp[255];

void create_edge(int u, int v, int w){
	mp[u].push_back((edge){v, w});
	mp[v].push_back((edge){u, w});
}

void change(int u, int x){
	mp[u][x].w *= 2;
}

void change2(int u, int x){
	mp[u][x].w /= 2; 
}

int dijkstra(int s){
	for(int i = 1; i <= n; i++){
		vis[i] = 0;
		dist[i] = inf;
	}
	dist[s] = 0;
	q.push((qnode){s, 0});
	while(!q.empty()){
		qnode Top = q.top() ;
		q.pop();
		int u = Top.v ;
		int value = Top.w ;
		if(vis[u])
			continue;
		vis[u] = 1;
		for(int i = 0; i < mp[u].size() ; i++){
			int v = mp[u][i].v;
			if(!vis[v] && dist[v] > dist[u] + mp[u][i].w){
				dist[v] = dist[u] + mp[u][i].w;
				q.push((qnode){v, dist[v]}); 
			}
		}
	}
	return dist[n];
}
int main(){
	cin >> n >> m;
	int u, v, w;
	for(int i = 1; i <= m ; i++){
		cin >> u >> v >> w;
		create_edge(u, v, w);
	}
	int tm1 = dijkstra(1);
	int maxn = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < mp[i].size() ; j++){
			change(i, j);
			maxn = max(maxn, dijkstra(1));
			change2(i, j);
		}
	}
	
	cout << maxn - tm1 << endl;
}
