#include "remove.h"

void go_to_index(FILE *fp,int index){
	if (fseek(fp, index * sizeof(Task), SEEK_SET) == 1){
		printf("Error fseek\n");
		return;
	}
}

int remove_task(char *path, int task_num, int done){
	//first get the index of the task
	//get list, then loop through the list to find the task num with done value retturn index;
	//
	//fseek to the index location, 

	

	//fseek to the task_num location plus 1 block
	//fread the block onto a Task block;
	//fseek to the location before that;
	//fwrite the task block onto the memory.
	//
	//get_list then get the list_len
	//int task_index = task_num - 1;
	//all in a for loop from i = task_index to i = list_len -2
	//fseek to 

}
