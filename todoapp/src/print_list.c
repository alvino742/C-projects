#include "print_list.h"



int print_list(char * path){
	int list_len;
	Task *task_list = get_list(path, &list_len);
	if (!task_list) {
		return 0;
	}
	printf("\n === Tasks pending: ===\n");
	int task_pending = 0;
	for (int i = 0; i < list_len; i++){
		if (task_list[i].done == 0) {
			task_pending += 1;
			printf("%d |  ", task_pending);
			printf("%s\n", task_list[i].name);
		}
	}

	printf("\n === Tasks done: === \n");
	int task_done = 0;
	for (int j = 0; j < list_len; j++) {
		if (task_list[j].done == 1){
			task_done += 1;
			printf("%d |  ", task_done);
			printf("%s\n", task_list[j].name);
		}
	}
	if (task_done == 0){
		printf("You stupid beta have not finished any tasks GET WORKING NOW\n");
	}
	free(task_list);
	printf("\n");
	return 1;
}
