#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

char    *my_get_line(char *buffer, int start, int end)
{
    char    *line;
    int i;

    line = malloc(sizeof(char) * (end - start +2));
    if(!line)
        return (NULL);
    i = 0;
    while(start < end)
    {
        line[i] = buffer[start];
        i++;
        start++;
    }
    if(buffer[start] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

char    *reset_buffer(char *buffer)
{
    int i;
    
    i = 0;
    while(buffer[i])
        buffer[i++] = '\0';
    return (buffer);
}

char    *ft_shift_reset(char *buffer, int nl_index, int buff_size)
{
    int i;

    i = 0;
    while (nl_index < buff_size - nl_index)
        buffer[i++] = buffer[nl_index++ + 1];
    while (nl_index < buff_size)
        buffer[nl_index++] = '\0';
    return (buffer);
}

size_t	ft_strlen(const char *src)
{
	int	size;

	size = 0;
    if(src == NULL)
        return (0);
	while (src[size])
		size++;
	return (size);
}
char	*ft_strjoin(char *s1, char *s2)
{
	int		final_size;
	size_t	i;
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

int ft_check_nl(char *line)
{
    int i;

    i = 0;

    while(i < ft_strlen(line) && line[i] != '\n')
        i++;
    if(line[i] != '\n')
        return (-1);
    return (i);
}

char *ft_get_line(char * str)
{
    int i;
    int end;
    char *line;

    i = 0;
    end = ft_check_nl(str);
    line = malloc(sizeof(char) * end + 1);
    if(!line)
        return (NULL);
    while(i <= end)
    {
        line[i] = str[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}