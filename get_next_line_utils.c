#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*my_get_line(char *buffer, int start, int end)
{
	char	*line;
	int		i;

	line = malloc(sizeof(char) * (end - start + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (start < end)
	{
		line[i] = buffer[start];
		i++;
		start++;
	}
	if (buffer[start] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*reset_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		buffer[i++] = 0;
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_shift_reset(char *buffer, int nl_index, int buff_size)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		buffer[i] = buffer[nl_index + i];
		i++;
	}
	while (i < buff_size)
		buffer[i++] = 0;
	buffer[i] = '\0';
	return (buffer);
}

int	ft_strlen(const char *src)
{
	int	size;

	size = 0;
	if (src == NULL)
		return (0);
	while (src[size])
		size++;
	return (size);
}
char	*ft_strjoin(char *s1, char *s2)
{
	int		final_size;
	int	i;
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

int	ft_check_nl(char *line)
{
	int	i;

	i = 0;
	while (i < ft_strlen(line) && line[i] != '\n')
		i++;
	if (line[i] != '\n')
		return (-1);
	return (i);
}

char	*ft_get_line(char *str)
{
	int i;
	int end;

	i = 0;
	end = ft_check_nl(str);
	while (i < end)
		i++;
	str[i++] = '\n';
	str[i] = '\0';
	return (str);
}