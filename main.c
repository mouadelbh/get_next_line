#include "get_next_line_bonus.h"
#include <stdio.h>

int main(void) {
	int fd1, fd2;
	// Open the files for reading
	fd1 = open("get_next_line_bonus.h", O_RDONLY);
	fd2 = open("get_next_line.h", 'r');

	char *line = get_next_line(fd1);
	char *line2 = get_next_line(fd2);

	while (line) {
		printf("File 1: %s", line);
		free(line);
		printf("File 2: %s", line2);
		free(line2);
		line2 = get_next_line(fd2);
		line = get_next_line(fd1);
	}
	return 0;
}
