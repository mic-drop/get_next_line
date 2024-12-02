#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int bytes_read;
	static int start;
	int end;
	char *line;
	static int current_fd;

    printf("fd: %d\n", fd);
	printf("curret_fd: %d\n", current_fd);
	printf("start: %d\n", start);
	printf("bytes_read: %d\n", bytes_read);
	if (current_fd == 0 || fd != current_fd)
	{
		current_fd = fd;
        reset_buffer(buffer);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
        start = 0;
	}
/*     printf("after read fd: %d\n", fd);
	printf("after read curret_fd: %d\n", current_fd);
	printf("after read start: %d\n", start);
	printf("after read bytes_read: %d\n", bytes_read); */
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (start >= bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (NULL);
		start = 0;
	}
	end = start;
	while (end < bytes_read && buffer[end] != '\n')
		end++;
	if (bytes_read != 0)
	{
		line = my_get_line(buffer, start, end);
		start = ++end;
		return (line);
	}
	return (NULL);
}