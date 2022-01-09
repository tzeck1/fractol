/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:00:47 by tzeck             #+#    #+#             */
/*   Updated: 2022/01/03 15:32:11 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit_string(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] < 48 || input[i] > 57)
		{
			if (input[i] != '-' && input[i] != '+')
				return (0);
			if ((input[i] == '-' || input[i] == '+')
				&& (input[i + 1] < 48 || input[i + 1] > 57))
				return (0);
		}
		i++;
	}
	return (1);
}
