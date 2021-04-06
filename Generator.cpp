#include "Base.h"


void generate_random(int num, int id)
{
    std::string file_name = FILE_PREFIX + std::to_string(id) + FILE_SUFFIX;
    FILE* f=freopen(file_name.c_str(), "w", stdout);
    if(!f)
    {
    	freopen("CON","w",stdout);
		puts("Directory Data doesn't exist.");
		exit(1);
	}
    printf("%d\n", num);
    printf("%d",rand());
    for (int i = 1; i < num; i++)
    {
        printf("%d ", rand());
    }
    freopen("CON","w",stdout);
}

