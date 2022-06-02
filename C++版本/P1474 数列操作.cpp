#include<bits/stdc++.h>
#include<set>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		multiset<long long int> numbers;
		long long int temp, a , b;
		for(int i = 0; i < n; i++){
			cin>>temp;
			numbers.insert(temp);
		}
		while(numbers.size() > 1){
			a = *numbers.begin();
			numbers.erase(numbers.begin());
			b = *numbers.begin();
			numbers.erase(numbers.begin());
			numbers.insert(a * b + 1);
		}
		cout<<*numbers.begin()<<endl;
	}
}
