/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 02:26:45 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/01 02:27:52 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		str_len(char **str)
{
	int	i;

	i = 0;
	while (str[i] && (ft_strcmp(str[i], "\n")))
		i++;
	return (i);
}

void	error(void)
{
	printf("ERROR\n");
	exit(0);
}

void	free_split(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
