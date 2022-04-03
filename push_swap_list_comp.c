/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_comp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 08:24:57 by ayassin           #+#    #+#             */
/*   Updated: 2022/04/03 12:07:35 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Complimentary file of list operations

t_cdlist	*nxtitem(t_cdlist *lst, int8_t direction);
void		ft_intdlstadd_sorted(t_cdlist **lst, t_cdlist *node, int8_t pref);
int8_t		repeated_num(t_cdlist *lst);

/*Returns the next item form a list (lst) if dircetion>=0, 
otherwise return prev*/
t_cdlist	*nxtitem(t_cdlist *lst, int8_t direction)
{
	if (direction >= 0)
		return (lst->next);
	return (lst->prev);
}

/*Used to add items (node) in a sorted manner to list (lst).
smallest to largest if pref >= 0, largest to smallest otherwise*/
void	ft_intdlstadd_sorted(t_cdlist **lst, t_cdlist *node, int8_t pref)
{
	t_cdlist	*t;

	if (!(lst && *lst != NULL))
	{
		if (lst)
			ft_intdlstadd_front(lst, node);
		return ;
	}
	t = *lst;
	while (((pref < 0) ^ (node->content >= t->content)) && ((t->next) != *lst))
		t = t->next;
	if (((pref < 0) ^ (node->content >= t->content)))
		t = *lst;
	else if (t == *lst)
	{
		ft_intdlstadd_front(lst, node);
		return ;
	}
	ft_intdlstadd_front(&t, node);
}

/*Returns 1 if the list (lst) has a repaeated number, 0 otherwise*/
int8_t	repeated_num(t_cdlist *lst)
{
	t_cdlist		*temp_i;
	t_cdlist		*temp_j;

	if (!lst)
		return (0);
	temp_i = lst;
	while (temp_i->next != lst)
	{
		temp_j = temp_i->next;
		while (temp_j != lst)
		{
			if (temp_i->content == temp_j->content)
				return (1);
			temp_j = temp_j->next;
		}
		temp_i = temp_i->next;
	}
	return (0);
}
