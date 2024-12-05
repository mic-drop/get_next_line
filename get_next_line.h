#include <unistd.h>

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

char	*get_next_line(int fd);
char	*my_get_line(char *buffer, int start, int end);
char	*reset_buffer(char *buffer);
int	ft_strlen(const char *src);
char	*ft_strjoin(char *s1, char *s2);
int	ft_check_nl(char *line);
char *ft_get_line(char * str);
char    *ft_shift_reset(char *buffer, int nl_index, int buff_size);
char	*ft_reset__and_return(char *buffer, char *str, int buff_size);
char *clean_exit(char *str);
#endif