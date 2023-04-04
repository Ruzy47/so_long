/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:29:01 by rugrigor          #+#    #+#             */
/*   Updated: 2022/10/12 12:02:14 by rugrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	to_find = ".ber";
	while (str[i])
	{
		n = 0;
		if (str[i] == to_find[n] && str[i] != '\0')
		{
			while (str[i + n] == to_find[n])
			{
				n++;
				if (to_find[n] == '\0' && str[i + n] == '\0')
					return (0);
			}
		}
		i++;
	}
	return (1);
}
