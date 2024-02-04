/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:59:19 by nkarpeko          #+#    #+#             */
/*   Updated: 2024/01/30 18:31:21 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_free_char_arr(char **arr)
{
	int	idx;

	idx = -1;
	if (!arr)
		return ;
	if (*arr)
	{
		while (arr[++idx])
			free(arr[idx]);
		free(arr);
	}
	arr = NULL;
}
