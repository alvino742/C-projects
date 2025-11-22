#include "add.h"

int add_list(char *path, char *task_name){
		FILE *fp = fopen(path, "ab+");
		if (fseek(fp, 0, SEEK_END) != 0) {
				printf("error with fseek\n");
				fclose(fp);
				return 0;
		}
		Task task;
		strcpy(task.name, task_name);
		task.done = 0;

		if (!(fwrite(&task, sizeof(task), 1, fp))) {
				perror("fwrite");
				fclose(fp);
				return 0;
		}
		fclose(fp);
		return 1;
}
