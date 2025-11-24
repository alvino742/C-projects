#include "clear.h"

int clear_all(char *path) {
	FILE *fp = fopen(path, "wb");
	if (!fp) {
		fclose(fp);
		return 0;
	}
	fclose(fp);
	return 1;
}
