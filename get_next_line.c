/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserra-p <mserra-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:22:09 by mserra-p          #+#    #+#             */
/*   Updated: 2024/12/05 16:35:00 by mserra-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*str;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = NULL;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (buffer[0] == '\0')
			bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
		if (ft_check_nl(buffer) != -1)
			return (ft_reset__and_return(buffer, str, BUFFER_SIZE));
		reset_buffer(buffer);
	}
	if (str && *str && bytes_read == 0)
		return (str);
	free(str);
	return (NULL);
}
