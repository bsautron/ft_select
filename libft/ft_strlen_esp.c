/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_esp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 00:52:17 by bsautron          #+#    #+#             */
/*   Updated: 2015/01/17 00:52:25 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen_esp(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] > ' ')
		i++;
	return (i);
}
