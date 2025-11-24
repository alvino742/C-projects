#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>

#include "struct.h"


void go_to_index(FILE *fp,int index);

int get_index(Task * task_list, int list_len, int task_num, int done);

#endif

