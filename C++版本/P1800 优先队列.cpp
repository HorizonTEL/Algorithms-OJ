#include<bits/stdc++.h>
using namespace std;

void swap(int &x, int &y, int &count){
	int temp = x;
	x = y;
	y = temp;
	count++;
}

void max_heap(int heap[], int i, int length, int &count){
	int l = i * 2, r = i * 2 + 1, largest = i;
	if(l <= length && heap[l] > heap[largest])
		largest = l;
	if(r <= length && heap[r] > heap[largest])
		largest = r;
	if(largest != i){
		swap(heap[i], heap[largest], count);
		max_heap(heap, largest, length, count);
	}
}

int max_heap_pop(int heap[], int &length, int &count){
	if(length < 1)
		exit(0);
	int re = heap[1];
	heap[1] = heap[length];
	length -= 1;
	max_heap(heap, 1, length, count);
	return re;
}

void insert_heap(int heap[], int &length, int key, int &count){
	length++;
	heap[length] = key;
	int i = length;
	while(i > 1 && heap[i / 2] < heap[i]){
		swap(heap[i / 2], heap[i], count);
		i /= 2;
	}
}

int main(){
	int heap[100010], length = 0, q, opt, x, count;
	cin>>q;
	while(q--){
		cin>>opt;
		if(opt == 1){
			cin>>x;
			count = 0;
			insert_heap(heap, length, x, count);
			cout<<count<<endl;
		}
		else{
			count = 1;
			cout<<max_heap_pop(heap, length, count)<<" ";
			cout<<count<<endl;
		}
	}
	return 0;
}
