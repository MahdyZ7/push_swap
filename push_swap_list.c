/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:28:17 by ayassin           #+#    #+#             */
/*   Updated: 2022/04/04 10:17:12 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Circular double linked list basic operations

t_cdlist	*ft_intdlstnew(int content);
void		ft_intdlstadd_front(t_cdlist **lst, t_cdlist *node);
void		ft_intdlstadd_back(t_cdlist **lst, t_cdlist *node);
void		ft_intdlstclear(t_cdlist **lst);
int			ft_intdlst_size(t_cdlist *lst);

/* Malloc a node that has content and return it*/
t_cdlist	*ft_intdlstnew(int content)
{
	t_cdlist	*node;

	node = (t_cdlist *)malloc(sizeof(*node));
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/*Add node at the start of thr list (lst)*/
void	ft_intdlstadd_front(t_cdlist **lst, t_cdlist *node)
{
	if (!lst || !node)
		return ;
	if (*lst)
	{
		node->prev = (*lst)->prev;
		node->prev->next = node;
		node->next = *lst;
		node->next->prev = node;
		*lst = node;
		return ;
	}
	node->next = node;
	node->prev = node;
	*lst = node;
}

/*Add node to the end of the list (lst)*/
void	ft_intdlstadd_back(t_cdlist **lst, t_cdlist *node)
{
	t_cdlist	*back;

	if (!lst || !node)
		return ;
	if (*lst == NULL)
	{
		*lst = node;
		node->next = node;
		node->prev = node;
		return ;
	}
	back = (*lst)->prev;
	node->next = back->next;
	node->prev = back;
	back->next = node;
	(*lst)->prev = node;
}

/*clear the whole list*/
void	ft_intdlstclear(t_cdlist **lst)
{
	t_cdlist	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		if ((*lst)->prev)
			(*lst)->prev->next = NULL;
		temp = *lst;
		*lst = (*lst)->next;
		free (temp);
	}
}

/*Return list size*/
int	ft_intdlst_size(t_cdlist *lst)
{
	int			len;
	t_cdlist	*temp;

	len = 0;
	if (lst)
		++len;
	else
		return (len);
	temp = lst->next;
	while (temp != lst)
	{
		++len;
		temp = temp->next;
	}
	return (len);
}
