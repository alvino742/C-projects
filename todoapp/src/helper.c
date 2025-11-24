#include "helper.h"


void go_to_index(FILE *fp,int index){
	if (fseek(fp, index * sizeof(Task), SEEK_SET) == 1){
		printf("Error fseek\n");
		fclose(fp);
		return;
	}
}

int get_index(Task * task_list, int list_len, int task_num, int done){
	int task_iter = 0;
	int index = 0;
	for (int i = 0; i < list_len; i++){
		if (task_list[i].done == done) {
			task_iter += 1;
			if (task_iter == task_num) {
				index = i;
				break;
			}
		}
	}
	return index;
}
