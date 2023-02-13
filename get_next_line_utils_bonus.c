/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svilaca- <svilaca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:00:37 by svilaca-          #+#    #+#             */
/*   Updated: 2023/02/13 20:40:02 by svilaca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		i;
	int		j;
	int		size_s1;
	int		size_s2;

	i = -1;
	j = -1;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	dst = malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (++i < size_s1)
		dst[i] = s1[i];
	while (++j < size_s2)
		dst[i + j] = s2[j];
	dst[i + j] = '\0';
	free(s1);
	return (dst);
}

int	clean_buffer(char *buffer)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (buffer[++i])
	{	
		if (j >= 0 || (buffer[i] == '\n' && ++j))
			buffer[j++] = buffer[i];
		buffer[i] = '\0';
	}
	return (j != -1);
}
