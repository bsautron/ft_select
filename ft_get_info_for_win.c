/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info_for_g_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 04:22:04 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/22 16:46:27 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_win	*g_win;

static size_t	ft_get_len_bigger_word(t_lstrep *lst)
{
	size_t		len;
	size_t		i;

	len = ft_strlen(lst->first->str);
	i = 0;
	while (i < lst->len)
	{
		if (len < ft_strlen(lst->first->str))
			len = ft_strlen(lst->first->str);
		lst->first = lst->first->next;
		i++;
	}
	return (len);
}

static int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void			ft_get_info_for_win(void)
{
	struct winsize	winsize;

	ioctl(0, TIOCGWINSZ, &winsize); 
	g_win->nb_argv = g_win->list->len;
	g_win->width = winsize.ws_col;
	g_win->height = winsize.ws_row;
	g_win->len_bigger = ft_get_len_bigger_word(g_win->list);
	g_win->col = (g_win->nb_argv - 1) / g_win->height + 1;
	g_win->raw = ft_min(g_win->nb_argv, g_win->height); 
}
