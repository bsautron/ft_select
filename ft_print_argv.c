/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 16:28:54 by bsautron          #+#    #+#             */
/*   Updated: 2015/02/23 18:20:13 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <term.h>

static void	ft_print_each_word(int i)
{
	t_lstdc		*tmp;
	char		*res;

	tmp = ft_get_link_by_id(i);
	res = tgetstr("cm", NULL);
	tputs(tgoto(res, (i / g_win->height) *
		(g_win->len_bigger + 1), i % g_win->height), 1, ft_outc);
	if (tmp->selected == 1)
		ft_make_instruction("so", NULL);
	ft_putstr_fd(ft_get_link_by_id(i)->str, g_win->fd);
	ft_make_instruction("se", NULL);
}

static void	ft_re_go(void)
{
	t_lstdc		*tmp;
	char		*res;

	if (g_win->pos > g_win->nb_argv)
		g_win->pos = g_win->nb_argv;
	tmp = ft_get_link_by_id(g_win->pos - 1);
	tputs(tgoto(res, ((g_win->pos - 1) / g_win->height) *
		(g_win->len_bigger + 1), (g_win->pos - 1) % g_win->height), 1, ft_outc);
	ft_make_instruction("us", NULL);
	if (tmp->selected)
		ft_make_instruction("so", NULL);
	ft_putstr_fd(ft_get_link_by_id(g_win->pos - 1)->str, g_win->fd);
	ft_make_instruction("ue", NULL);
	ft_make_instruction("se", NULL);
}

void		ft_print_argv(void)
{
	size_t		i;
	t_lstdc		*tmp;

	i = 0;
	if (g_win->nb_argv == 0)
	{
		ft_tcg(1);
		exit(0);
	}
	if (g_win->sp == 0)
		ft_putendl_fd("La fenetre est trop petite", g_win->fd);
	else
	{
		while (g_win->list && i < g_win->list->len)
		{
			ft_print_each_word(i);
			i++;
			if (i > g_win->nb_argv)
				i = 1;
		}
		ft_re_go();
	}
}
