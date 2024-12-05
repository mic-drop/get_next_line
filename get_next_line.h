/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserra-p <mserra-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:44:57 by mserra-p          #+#    #+#             */
/*   Updated: 2024/12/05 16:58:37 by mserra-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*reset_buffer(char *buffer);
int		ft_strlen(const char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_check_nl(char *line);
char	*ft_reset__and_return(char *buffer, char *str, int buff_size);
#endif
