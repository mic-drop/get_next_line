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
	char *str;
	int bytes_read;

	if(fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = NULL;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if(buffer[0] == '\0')
			bytes_read = read(fd, buffer, BUFFER_SIZE);
 		if(bytes_read < 0) // If error
		{
			if(str)
				free(str);
			return (NULL);
		}
		// printf("This is buffer[bytes_read]: |%c|\n", buffer[bytes_read]);
		buffer[bytes_read] = '\0';
		str = ft_strjoin(str, buffer);
		// printf("This is str after join: |%s|\n", str);
		if(!str)
			return (NULL);
		if(ft_check_nl(buffer) != -1)
		{
			ft_shift_reset(buffer, ft_check_nl(buffer) + 1, BUFFER_SIZE);
			str = ft_get_line(str);
			// printf("This is str before return: |%s|\n", str);
			return (str);
		}
		reset_buffer(buffer);
	}
	if(str && *str)
		return (str);
	free(str);
	return (NULL);
}