/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:21:27 by nkarpeko          #+#    #+#             */
/*   Updated: 2024/01/30 18:31:40 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*saveptr;
	char		*end;

	if (!str)
		str = saveptr;
	if (!str)
		return (NULL);
	while (*str && ft_strchr(delim, *str))
		str++;
	if (!*str)
	{
		saveptr = NULL;
		return (NULL);
	}
	end = str;
	while (*end && !ft_strchr(delim, *end))
		end++;
	if (*end)
	{
		*end = '\0';
		saveptr = end + 1;
	}
	else
		saveptr = NULL;
	return (str);
}
