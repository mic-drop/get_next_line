#include <stdlib.h>

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