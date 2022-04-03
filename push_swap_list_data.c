/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:45:21 by ayassin           #+#    #+#             */
/*   Updated: 2022/04/03 12:07:23 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// functions that analyzes the list

int	inv_number(t_cdlist *lst, unsigned int n, int8_t dir, int8_t pref);
int	is_sorted(t_cdlist *lst, unsigned int n, int8_t dir, int8_t pref);
int	findmidian(t_cdlist *lst, int n, int8_t dir, int8_t pref);

/* Returns the inversion number of the list (lst) based on size (n),
direction of travel (dir), and order prefrence (pref)*/
int	inv_number(t_cdlist *lst, unsigned int n, int8_t dir, int8_t pref)
{
	int				inv;
	unsigned int	count_j;
	t_cdlist		*temp_i;
	t_cdlist		*temp_j;

	inv = 0;
	temp_i = lst;
	while (nxtitem(temp_i, dir) != lst && n)
	{
		count_j = 1;
		temp_j = nxtitem(temp_i, dir);
		while (temp_j != lst && count_j < n)
		{
			if (temp_i->content > temp_j->content && pref >= 0)
				++inv;
			else if (temp_i->content < temp_j->content && pref < 0)
				++inv;
			temp_j = nxtitem(temp_j, dir);
			++count_j;
		}
		temp_i = nxtitem(temp_i, dir);
		--n;
	}
	return (inv);
}

/* Returns (pref) if the list (lst) is sorted based on size (n), 
direction of travel (dir), and sorting prefrance (pref). 0 for unsorted*/
int	is_sorted(t_cdlist *lst, unsigned int n, int8_t dir, int8_t pref)
{
	unsigned int	sorted;
	unsigned int	len;	

	sorted = 0;
	len = ft_intdlst_size(lst);
	if (!lst || n == 0)
		return (pref);
	if (n > len)
		n = len;
	while (sorted < n - 1)
	{
		if ((lst->content) > nxtitem(lst, dir)->content && pref >= 0)
			return (0);
		else if ((lst->content) < nxtitem(lst, dir)->content && pref < 0)
			return (0);
		lst = nxtitem(lst, dir);
		++sorted;
	}
	return (pref);
}

/*Returns ~median numbers in list (lst) based on size (n),
direction of travel (dir), and prefrence (pref).*/
int	findmidian(t_cdlist *lst, int n, int8_t dir, int8_t pref)
{
	int			count;
	int			median;
	t_cdlist	*aux;
	t_cdlist	*temp;

	count = 1;
	median = 0;
	aux = NULL;
	ft_intdlstadd_sorted(&aux, ft_intdlstnew(lst->content), pref);
	temp = nxtitem(lst, dir);
	while (temp != lst && count < n)
	{
		ft_intdlstadd_sorted(&aux, ft_intdlstnew(temp->content), pref);
		temp = nxtitem(temp, dir);
		++count;
	}
	count = count / 2;
	while (count-- > 0)
		aux = nxtitem(aux, dir);
	if (aux)
		median = aux->content;
	ft_intdlstclear(&aux);
	return (median);
}