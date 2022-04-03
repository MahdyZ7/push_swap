/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:19:48 by ayassin           #+#    #+#             */
/*   Updated: 2022/04/03 13:12:32 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Basic push swap stack operations

char	*swap_first2(t_cdlist **lst);
char	*rotate_down(t_cdlist **lst);
char	*rotate_down(t_cdlist **lst);
char	*top_push(t_cdlist **src, t_cdlist **dst);

/*swap first two items in the list*/
char	*swap_first2(t_cdlist **lst)
{
	int	temp;

	if (!(lst && *lst && (*lst)->next != *lst))
		return ("");
	temp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = temp;
	return ("s");
}

/* rotate the list up (second item becomes first)*/
char	*rotate_up(t_cdlist **lst)
{
	if (!(lst && *lst && (*lst)->next != *lst))
		return ("");
	*lst = (*lst)->next;
	return ("r");
}

/* rotate the list down (last item is first)*/
char	*rotate_down(t_cdlist **lst)
{
	if (!(lst && *lst && (*lst)->prev != *lst))
		return ("");
	*lst = (*lst)->prev;
	return ("rr");
}

/*the first item of stack (src) is removed and placed in stack (dest)*/
char	*top_push(t_cdlist **src, t_cdlist **dst)
{
	t_cdlist	*temp;
	t_cdlist	*skp;

	if (!(src && dst && *src))
		return ("");
	temp = *src;
	if (*src == (*src)->next)
		*src = NULL;
	else
	{
		skp = (*src)->prev;
		skp->next = (*src)->next;
		*src = (*src)->next;
		(*src)->prev = skp;
	}
	temp->next = NULL;
	temp->prev = NULL;
	ft_intdlstadd_front(dst, temp);
	return ("p");
}
