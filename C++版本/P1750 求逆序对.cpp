#include<bits/stdc++.h>
using namespace std;

int temp[500010];

void merge_sort(int *q, int first, int end, long long int &re){
	if(first >= end)
		return;
	int mid = (first + end) / 2;
	merge_sort(q, first, mid, re);
	merge_sort(q, mid+1, end, re);
	int i = first, j = mid + 1, k = 0;
	while(i <= mid && j <= end){
		if(q[i] <= q[j])
			temp[k++] = q[i++];
		else{
			temp[k++] = q[j++];
			re = re + mid - i + 1;
		}
	}
	while(i <= mid)
		temp[k++] = q[i++];
	while(j <= end)
		temp[k++] = q[j++];
	for(i = first, j = 0; i <= end; i++, j++)
		q[i] = temp[j];
}

int main(){
	int n, in[500010], i;
	long long re = 0;
	cin>>n;
	for(i = 0; i < n; i++)
		cin>>in[i];
	merge_sort(in, 0, n - 1, re);
	cout<<re<<endl;
}
