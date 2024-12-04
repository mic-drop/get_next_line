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

	str = NULL;
	bytes_read = 1;
	if(fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (bytes_read != 0)
	{
		if(buffer[0] == 0)
			bytes_read = read(fd, buffer, BUFFER_SIZE);
 		if(bytes_read == 0) // If nothing else to read
			return (NULL);
   		while(ft_check_nl(buffer) == -1) //While we don't find a nl, keep concatnating
		{
			// printf("Buff: %s\n",buffer);
			// printf("%d\n",ft_check_nl(buffer));
			str = ft_strjoin(str, buffer);
			// printf("%s\n", str);
			printf("|%c|",buffer[0]);
			reset_buffer(buffer);
			printf("|%c|",buffer[0]);
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			printf("|%c|",buffer[0]);
		}
		if(str)
		{
			str = ft_strjoin(str, "\n");
			return (str);
		}
		str = ft_get_line(buffer);
		ft_shift_reset(buffer, ft_check_nl(buffer), BUFFER_SIZE);
		return (str);
	}
	return (NULL);
}