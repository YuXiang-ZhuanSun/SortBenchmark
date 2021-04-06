#include "Sort.h"
int * MergeSort(int *a, int *b, int l, int r) {
	if (l == r) {
		return b;
	}
	int mid = (l + r) / 2;
	MergeSort(b, a, l, mid);
	MergeSort(b, a, mid + 1, r);
	int lp = l, rp = mid + 1, bp = l;
	while (lp <= mid && rp <= r) {
		if (a[lp] < a[rp]) {
			b[bp] = a[lp];
			lp++;
			bp++;
		} else {
			b[bp] = a[rp];
			rp++;
			bp++;
		}
	}
	while (lp <= mid) {
		b[bp] = a[lp];
		lp++;
		bp++;
	}
	while (rp <= r) {
		b[bp] = a[rp];
		rp++;
		bp++;
	}
	return b;
}

void merge_sort(int *a,int num){
	int *b=(int *)malloc(sizeof(int)*num);
	MergeSort(a,b,0,num-1);
	free(b);
} 
