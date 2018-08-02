/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:38:55 by jfleisch          #+#    #+#             */
/*   Updated: 2018/02/21 16:42:57 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t				ft_strlen(const char *str)
{
	size_t			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
