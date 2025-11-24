#include <stdio.h>
#include <string.h>
#include "main.h"


//todo now  


int main(int argc, char **argv) {
	char *path = "task.bin";
	char *command = argv[1];

	if (strcmp(command, "add") == 0){
			char *task_name = argv[2];
			if (!add_list(path, task_name)){
					printf("error adding\n");
					return 1;
			}
			printf("Task added succeessfully\n");
	}
	
	else if (strcmp(command, "list") == 0) {
		if (!print_list(path)){
			printf("No task created yet.\n");
			return 1;
		}
	}

	else if (strcmp(command, "done") == 0) {
		char *endptr;
		int task_num = strtol(argv[2], &endptr, 10);
		if (endptr == argv[2]) {
			printf("No conversion performed\n");
			return 1;
		}
		if (!done_task(path, task_num)){
			printf("Error marking task done\n");
			return 1;
		}
		printf("Task marked as done! Good job beta.\n");
	}

	else if (strcmp(command, "undone") == 0){
		;
	}

	else if (strcmp(command, "remove") == 0) {
		char *endptr;
		int task_num = strtol(argv[2], &endptr, 10);
		if (endptr == argv[2]){
			printf("No conversion performed\n");
			return 1;
		}
		if (!remove_task(path, task_num)){
			printf("Error removing task\n");
			return 1;
		}
		printf("Task removed!\n");
	}
	
	else if(strcmp(command, "clear") == 0) {
		if (strcmp(argv[2], "all") == 0) {
			if (!clear_all(path)) {
				printf("Error clearing file\n");
				return 1;
			}
			printf("Tasks cleared successfully\n");
		}
	}


	return 0;
}
