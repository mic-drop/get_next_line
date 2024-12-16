/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserra-p <mserra-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:22:09 by mserra-p          #+#    #+#             */
/*   Updated: 2024/12/16 19:26:52 by mserra-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];//Estado mantem-se ate ao final da xecuco do programa 
	char		*str;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE < 1)//he return value of open() is a file descriptor, a small, nonnegative integer
		return (NULL);
	str = NULL;
	bytes_read = 1;
	while (bytes_read > 0) //While not end of file or Error
	{
		if (buffer[0] == '\0') //If buffer is empty
			bytes_read = read(fd, buffer, BUFFER_SIZE); //Read buffer
		if (bytes_read < 0) //Was there an error reading? #1
			break ; //If so, get out
		str = ft_strjoin(str, buffer); //If no error, line joins whats in buffer #3
		if (!str)//
			return (NULL);
		if (ft_check_nl(buffer) != -1) //If buffer contains a new line #4
			return (ft_reset__and_return(buffer, str, BUFFER_SIZE));
		reset_buffer(buffer); //If buffer contains nl, so does str, so reset buffer #5 
	}
	if (str && *str && bytes_read == 0) //if there is a string and no errror was found
		return (str);// return string
	if(str)
		free(str); //If error, free str #2
	return (NULL);
}
