#define _POSIX_C_SOURCE 200809L
#include "remove.h"



int remove_task(char *path, int task_num, int done){
	//first get the index of the task
	//get list, then loop through the list to find the task num with done value retturn index;
	//

	//goto index of the index +1 block fread that shit 
	//go to index index fwrite that shit
	// do this in a for loop from i = index to i < list_len - 1
	
	int list_len;
	Task *task_list = get_list(path, &list_len);
	int index = get_index(task_list, list_len, task_num, done);

	FILE *fp = fopen(path, "rb+");

	for (int i = index; i < list_len - 1; i++){
		go_to_index(fp, i);
		if (!fwrite(&(task_list[i+1]), sizeof(Task), 1, fp)){
			printf("Error fwrite\n");
			return 0;
		}
	}

	rewind(fp);
	if (fseek(fp, 0, SEEK_END) != 0) {
	  printf("Error fseek\n");
		fclose(fp);
		return 1;
	}
	int old_size = ftell(fp);
	int new_size = old_size - sizeof(Task);
	
	if (ftruncate(fileno(fp), new_size) != 0) {
		printf("Error ftruncate\n");
		fclose(fp);
		return 1;
	}

	fclose(fp);
	free(task_list);
	return 1;
}

