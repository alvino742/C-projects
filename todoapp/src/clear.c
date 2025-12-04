#include "clear.h"
#include "remove.h"

int clear_all(char *path) {
	FILE *fp = fopen(path, "wb");
	if (!fp) {
		fclose(fp);
		return 0;
	}
	fclose(fp);
	return 1;
}


int clear_done(char *path) {
	int list_len;
	Task *task_list = get_list(path, &list_len);
	int task_done = 0;
	for (int j = 0; j < list_len; j++) {
		if (task_list[j].done == 1){
			task_done += 1;
		}
	}
	for (int i = 1; i < task_done+1; i++) {
		if (!remove_task(path, 1, 1)){
			free(task_list);
			return 0;
		}
	}
	free(task_list);
	return 1;
}
