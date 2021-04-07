#include "Base.h"


void generate_test_cases() {
	puts("Test cases are generating...");
	puts("");
	srand(time(NULL));
	for (int i = 0; i < MAX_GROUP; i++) {
		generate_random(num[i], i + 1);
	}
	puts("Test cases generated successfully.");
	puts("");
}


void benchmark_sort(void (*f)(int *, int), const char* sortType) {
	printf("Testing performance of %s:\n",sortType);
	int num;
	for (int i = 0; i < MAX_GROUP; i++) {
		std::string file_name = FILE_PREFIX + std::to_string(i + 1) + FILE_SUFFIX;
		freopen(file_name.c_str(), "r", stdin);
		scanf("%d", &num);
		int *a = (int *)malloc(num * sizeof(int));
		for (int j = 0; j < num; j++) {
			scanf("%d", a + j);
		}
		clock_t begin = clock();
		f(a, num);
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("Time cost of sorting %d numbers using %s is %lfs.\n", num, sortType, time_spent);
		free(a);
	}
	puts("");
}


int main() {
	generate_test_cases();
	benchmark_sort(std_sort, "std::sort()");
	benchmark_sort(quick_sort,"QuickSort()");
	benchmark_sort(merge_sort,"MergeSort()");
	
	return 0;
}
