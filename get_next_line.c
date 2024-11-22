
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif


char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int		bytes_read;
    static int start;
    int end;
    char *line;


    printf("This is buffer %s #\n", buffer);
    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    printf("This is start %d\n", start);
    printf("This is buffer[start]: %c\n", buffer[start]);
    printf("This is bytes_read %d\n", bytes_read);
    if(start >= bytes_read)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if(bytes_read <= 0)
            return (NULL);
        start = 0;
    }
    end = start;
    while (end < bytes_read && buffer[end] != '\n')
        end++;
    if(bytes_read != 0)
    {
        line = get_line(buffer, start, end);
        start = ++end;
        return (line);
    }
	return (NULL);
}