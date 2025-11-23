#include "done_task.h"

int done_task(char * path, int task_num){
	//fseek to the task_num * sizeof(Task) position in the file
	//set a Task block
	//fread onto the block, change the done to 1
	//fwrite that block onto the file
	
	FILE *fp = fopen(path, "rb+");
	if (!fp) {
		printf("FILE is NULL\n");
		return 0;
	}

	if (fseek(fp, (task_num-1) * sizeof(Task), SEEK_SET) == 1){
		printf("Error fseek\n");
		fclose(fp);
		return 0;
	}

	Task block;
	if (fread(&block, sizeof(Task), 1, fp) != 1){
		printf("Error fread\n");
		fclose(fp);
		return 0;
	}

	block.done = 1;

	if (!fwrite(&block, sizeof(Task), 1, fp)) {
		printf("Error fwrite\n");
		fclose(fp);
		return 0;
	}

	fclose(fp);
	return 1;
}
