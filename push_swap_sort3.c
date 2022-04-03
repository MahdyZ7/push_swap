/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:10:13 by ayassin           #+#    #+#             */
/*   Updated: 2022/04/03 22:35:04 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_cdlist	*findend(t_cdlist *lst, int n, int order, int8_t pref)
{
	int			count;
	t_cdlist	*aux;
	t_cdlist	*temp;

	count = 1;
	aux = NULL;
	if (n > ft_intdlst_size(lst) || n < 0)
		n = ft_intdlst_size(lst);
	if (order > n || order < 0)
		order = n;
	ft_intdlstadd_sorted(&aux, ft_intdlstnew(lst->content), pref);
	temp = nxtitem(lst, 1);
	while (temp != lst && count++ < n)
	{
		ft_intdlstadd_sorted(&aux, ft_intdlstnew(temp->content), pref);
		temp = nxtitem(temp, 1);
	}
	count = 1;
	while (count++ < order)
		aux = nxtitem(aux, 1);
	while (aux->content != lst->content)
		lst = lst->next;
	ft_intdlstclear(&aux);
	return (lst);
}

static int	dist(t_cdlist *start, t_cdlist *end)
{
	int			count1;
	int			count2;
	t_cdlist	*temp;

	count1 = 0;
	count2 = 0;
	temp = start;
	while (temp != end)
		temp = temp->prev + (++count1 * 0);
	temp = start;
	while (temp != end)
		temp = temp->next + (++count2 * 0);
	if (count1 < count2)
		return (count1);
	return (count2);
}

static char	*pull_inorder(t_cdlist **src, t_cdlist **dest, int n, int8_t pref)
{
	char		*moves;
	t_cdlist	*max;
	t_cdlist	*max2;
	int			flag;

	moves = NULL;
	flag = 0;
	while (n > 0)
	{
		max = findend(*src, n, 1, -pref);
		max2 = findend(*src, n--, 2, -pref);
		if ((dist(*src, max) - dist(*src, max2)) < 2 || flag)
		{
			ft_strjoin_ps(&moves, optimal_traverse(src, &max, -pref), 1);
			save_move (&moves, top_push(src, dest), pref);
			if (flag > 0)
				save_move (&moves, swap_first2(dest), pref + (--flag * 0));
		}
		else
		{
			ft_strjoin_ps(&moves, optimal_traverse(src, &max2, -pref), 1);
			save_move (&moves, top_push(src, dest), pref + (++flag * 0));
		}
	}
	return (moves);
}

char	*gsort2(t_cdlist **lsta, t_cdlist **lstb, int n, int8_t pref)
{
	int			percentile;
	int			pushed;
	char		*moves;

	percentile = findend(*lsta, n, 38, pref)->content;
	pushed = 0;
	moves = NULL;
	if (is_sorted(*lsta, n, 1, pref) == pref)
		return (moves);
	while (pushed < 38 - 1)
	{
		if ((*lsta)->content < percentile && pref >= 0)
		{
			save_move(&moves, top_push(lsta, lstb), -pref);
			++pushed;
		}
		else
			save_move(&moves, rotate_up(lsta), pref);
	}
	ft_strjoin_ps(&moves, gsort(lsta, lstb, n - pushed, pref), 1);
	ft_strjoin_ps(&moves, pull_inorder(lstb, lsta, pushed, pref), 1);
	return (moves);
}
