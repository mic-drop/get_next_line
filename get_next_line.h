#ifndef GET_NEXT_LINE_H

#define GET_NEXT_LINE_H

char *get_next_line(int fd);
char    *my_get_line(char *buffer, int start, int end);
char    *reset_buffer(char *buffer);
#endif