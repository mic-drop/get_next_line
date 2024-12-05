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
			// buffer[bytes_read] = '\0';
 		if(bytes_read < 0) // If error
		{
			if(str)
				free(str);
			return (NULL);
		}
		// printf("This is buffer[bytes_read]: |%c|\n", buffer[bytes_read]);
		// printf("This is buffer before join: |%s|\n", buffer);
		str = ft_strjoin(str, buffer);
		// printf("This is str after join: |%s|\n", str);
		if(!str)
			return (NULL);
		if(ft_check_nl(buffer) != -1)
		{

			// printf("This is buffer before reset: |%s|\n", buffer);
			// printf("This is check nl index: %d\n", ft_check_nl(buffer));
			ft_shift_reset(buffer, ft_check_nl(buffer) + 1, BUFFER_SIZE);
			// printf("This is buffer after reset: |%s|\n", buffer);
			str = ft_get_line(str);
			// printf("This is str before return: |%s|\n", str);
			return (str);
		}
		// printf("###This is buffer before reset: |%s|\n", buffer);
		reset_buffer(buffer);
	}
	if(str && *str)
		return (str);
	free(str);
	return (NULL);
}