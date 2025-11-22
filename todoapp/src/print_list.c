#include "print_list.h"


Task * get_list(char *path, int *list_len){
	FILE *fp = fopen(path, "rb");
	if (!fp){
		return NULL;
	}

	if (fseek(fp, 0, SEEK_END) != 0){
		printf("Error fseek\n");
		return NULL;
	}

	int len = (int)ftell(fp);
	int length = len/(int)sizeof(Task);
	*list_len = length; 

	if (length == 0){
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
				return NULL;
			} else {
				task_list = tmp;
			}
		}

		n++;
	} 

	return task_list;
}

int print_list(char * path){
	int list_len;
	Task *task_list = get_list(path, &list_len);
	if (!task_list) {
		free(task_list);
		return 0;
	}
	printf("Tasks pending: \n");
	for (int i = 0; i < list_len; i++){
		printf("%s\n", task_list[i].name);
	}
	free(task_list);
	return 1;
}
