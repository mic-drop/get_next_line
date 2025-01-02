/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserra-p <mserra-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:01:47 by mserra-p          #+#    #+#             */
/*   Updated: 2025/01/02 18:48:48 by mserra-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*reset_buffer(char *buffer)
{
	int	i;

	if(!buffer)
		return (buffer);
	i = 0;
	while (buffer[i])
		buffer[i++] = 0;
	buffer[i] = '\0';
	return (buffer);
}

size_t	ft_strlen(const char *src)
{
	size_t	size;

	size = 0;
	if (src == NULL)
		return (0);
	while (src[size] != '\0'){
		size++;
	}
	return (size);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		final_size;
	int		i;
	char	*new_str;

	i = 0;
	final_size = (ft_strlen(s1) + ft_strlen(s2));
	new_str = malloc(final_size + 1);
	if (new_str == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	free(s1);
	while (*s2)
	{
		new_str[i] = *s2;
		s2++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	ft_check_nl(char *line) //gives index before NL
{
	size_t	i;

	i = 0;
	if(!line)
		return (-1);
	while (i < ft_strlen(line) && line[i] != '\n')
		i++;
	if (line[i] != '\n')
		return (-1);
	return (i);
}

char	*ft_reset__and_return(char *buffer, char *str, int buff_size)
{
	int	i;
	int	nl_index;//nl_index is actually nl index
	int	end;

	i = 0;
	nl_index = ft_check_nl(buffer) + 1; //check_nl gives actual index, we give plus one to start ahead
	while (buffer[i] != '\0')
	{
		buffer[i] = buffer[nl_index + i];
		i++;
	}
	while (i < buff_size)
		buffer[i++] = 0;
	buffer[i] = '\0';
	i = 0;
	end = ft_check_nl(str);
	while (i < end)
		i++;
	str[i++] = '\n';
	str[i] = '\0';
	return (str);
}
