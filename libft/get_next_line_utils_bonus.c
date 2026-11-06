/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucotte <jlucotte@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 17:12:47 by jlucotte          #+#    #+#             */
/*   Updated: 2026/10/21 15:36:46 by jlucotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strjoin(char *s1, char *s2, int size1, int size2)
{
	char	*new_str;
	char	*start;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = malloc(size1 + size2 + 1);
	start = new_str;
	if (new_str == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		*new_str = *s1;
		s1++;
		new_str++;
	}
	while (*s2 != '\0')
	{
		*new_str = *s2;
		new_str++;
		s2++;
	}
	*new_str = '\0';
	free(s1 - size1);
	free(s2 - size2);
	return (start);
}

int	gnl_strchr_index(char *str, char c)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (index);
		index++;
	}
	return (-1);
}
