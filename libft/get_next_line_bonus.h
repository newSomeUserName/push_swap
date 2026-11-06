/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 00:14:12 by jlucotte          #+#    #+#             */
/*   Updated: 2026/10/21 20:12:22 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "libft.h"

# define LINE_END '\n'
# define MAX_FD 1024

char	*get_next_line(int fd);

char	*gnl_strjoin(char *s1, char *s2, int size1, int size2);
int		gnl_strchr_index(char *str, char c);

#endif