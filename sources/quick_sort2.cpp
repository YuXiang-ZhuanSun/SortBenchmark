#include "sort.h"

void QuickSort2(int *a, int l, int r) {
	if (l >= r) {
		return ;
	}
	std::swap(a[l], a[(l + r) / 2]);
	int i = l, j = r, pivot = a[l];
	while (i < j) {
		while (i < j && a[j] >= pivot) {
			j--;
		}
		a[i] = a[j];
		while (i < j && a[i] <= pivot) {
			i++;
		}
		a[j] = a[i];
	}
	a[i] = pivot;
	QuickSort2(a, l, i - 1);
	QuickSort2(a, i + 1, r);
}

void quick_sort2(int *a, int num) {
	QuickSort2(a, 0, num - 1);
}
