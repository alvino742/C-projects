#ifndef REMOVE_H
#define REMOVE_H

#include <unistd.h> 
#include <stdio.h>

#include "struct.h"
#include "get_list.h"
#include "helper.h"

int remove_task(char *path, int task_num, int done);

#endif
