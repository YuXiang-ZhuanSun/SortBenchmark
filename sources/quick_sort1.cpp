#include "sort.h"

void QuickSort1(int *a, int l, int r) {
	int i = l, j = r, pivot = a[(l + r) / 2];
	while (i <= j) {
		while (a[i] < pivot) {
			i++;
		}
		while (a[j] > pivot) {
			j--;
		}
		if (i <= j) {
			std::swap(a[i++], a[j--]);
		}
	}
	if (l < j) {
		QuickSort1(a, l, j);
	}
	if (i < r) {
		QuickSort1(a, i, r);
	}
}

void quick_sort1(int *a, int num) {
	QuickSort1(a, 0, num - 1);
}
