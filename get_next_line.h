/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserra-p <mserra-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:44:57 by mserra-p          #+#    #+#             */
/*   Updated: 2025/01/02 15:57:05 by mserra-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h> //open close
# include <stdio.h> // print
# include <stdlib.h> //free
# include <unistd.h> //read write

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*reset_buffer(char *buffer);
size_t		ft_strlen(const char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_check_nl(char *line);
char	*ft_reset__and_return(char *buffer, char *str, int buff_size);
#endif
