#include "done_task.h"

int set_task_done(char * path, int task_num, int done){
	//fseek to the task_num * sizeof(Task) position in the file
	//set a Task block
	//fread onto the block, change the done to 1
	//fwrite that block onto the file
	
	int list_len;
	Task *task_list = get_list(path, &list_len);
	int index = get_index(task_list, list_len, task_num, !done);

	
	FILE *fp = fopen(path, "rb+");
	if (!fp) {
		printf("FILE is NULL\n");
		return 0;
	}

	go_to_index(fp, index);

	Task block;
	if (fread(&block, sizeof(Task), 1, fp) != 1){
		printf("Error fread\n");
		fclose(fp);
		return 0;
	}

	block.done = done;

	go_to_index(fp, index);

	if (!fwrite(&block, sizeof(Task), 1, fp)) {
		printf("Error fwrite\n");
		fclose(fp);
		return 0;
	}

	fclose(fp);
	free(task_list);
	return 1;
}
