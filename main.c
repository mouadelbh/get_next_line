#include "get_next_line.h"
int main()
{
	int fd = open("get_next_line.h", 'r');
	char *line = get_next_line(fd);
		// printf("%s", line);

	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);

	}
	// system("a.out");
	free(line);
}
