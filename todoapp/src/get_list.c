#include "get_list.h"



Task * get_list(char *path, int *list_len){
	FILE *fp = fopen(path, "rb");
	if (!fp){
		fclose(fp);
		return NULL;
	}

	if (fseek(fp, 0, SEEK_END) != 0){
		printf("Error fseek\n");
		fclose(fp);
		return NULL;
	}

	int len = (int)ftell(fp);
	int length = len/(int)sizeof(Task);


	if (length == 0){
		fclose(fp);
		return NULL;
	}
	int capacity = STARTING_SIZE;
	Task *task_list = (Task *) malloc(capacity * sizeof(Task));

	int n = 0;
	rewind(fp);
	while (fread(&task_list[n], sizeof(Task), 1, fp) != 0) {
		if (n == capacity - 1){
			capacity *= 2;
			Task *tmp = (Task*)realloc(task_list, capacity * sizeof(Task));
			if (!tmp) {
				free(task_list);
				printf("Error allocating memory\n");
				fclose(fp);
				return NULL;
			} else {
				task_list = tmp;
			}
		}

		n++;
	} 
	*list_len = n;
	fclose(fp);

	return task_list;
}
