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

void set_std_out(int *a, int num, std::string s) {
	freopen(s.c_str(), "w", stdout);
	for (int j = 0; j < num; j++) {
		printf("%d ", a[j]);
	}
	freopen("CON", "w", stdout);
}

void check_out(int *a, int num, std::string s) {
	freopen(s.c_str(), "r", stdin);
	int x;
	for (int j = 0; j < num; j++) {
		scanf("%d", &x);
		if (x != a[j]) {
			printf("Wrong answer!!!\n");
			exit(-1);
		}
	}
}

void benchmark_sort(void (*f)(int *, int), const char* sortType, int stdsort = 0) {
	printf("Testing performance of %s:\n", sortType);
	int num;
	for (int i = 0; i < MAX_GROUP; i++) {
		std::string file_name_in = FILE_PREFIX + std::to_string(i + 1) + FILE_IN_SUFFIX;
		std::string file_name_out = FILE_PREFIX + std::to_string(i + 1) + FILE_OUT_SUFFIX;
		freopen(file_name_in.c_str(), "r", stdin);
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

		if (stdsort) {
			set_std_out(a, num, file_name_out);
		} else {
			check_out(a, num, file_name_out);
			printf("The answer is correct.\n");
		}
		free(a);
	}
	puts("");
}


int main() {
	generate_test_cases();

	benchmark_sort(std_sort, "std::sort()", true);

	benchmark_sort(quick_sort1, "QuickSort1()");
	benchmark_sort(quick_sort2, "QucickSort2()");
	benchmark_sort(merge_sort, "MergeSort()");

	return 0;
}
