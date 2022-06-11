#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int n, T;

struct mooncake{
	int time;
	int deadline;
	int happy;
};

int cmp(mooncake x, mooncake y){
	return x.deadline < y.deadline;
}

ll dp[10005], pret[10005], preh[10005];
bool check[10005];
mooncake a[10005];

int main(){
	cin >> n >> T;
	ll ans = 0;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i].time >> a[i].deadline >> a[i].happy ;
	sort(a + 1, a + n + 1, cmp);
	
	a[n + 1].time = 0;
	a[n + 1].deadline = 10000000; 
	a[n + 1].happy = 0;
	check[0] = true;
	
	for(int i = 1; i <= n; i++){
		preh[i] += preh[i - 1] + a[i].happy ;
		pret[i] = pret[i - 1] + a[i].time ;
		check[i] = check[i - 1] && pret[i] <= a[i].deadline && pret[i] <= T;
	}
	
	for(int i = n; i >= 0; --i){
		for(int j = T; j >= a[i + 1].time ; --j)
			dp[j] = max(dp[j], dp[j - a[i + 1].time ]+ a[i + 1].happy);
	
		if(check[i])
			ans = max(ans, dp[min( (ll)T , a[i + 1].deadline -1ll) - pret[i]] + preh[i]);
	}
	cout << ans;
}
