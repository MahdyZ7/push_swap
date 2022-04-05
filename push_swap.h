/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:18:29 by ayassin           #+#    #+#             */
/*   Updated: 2022/04/04 11:00:18 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

/* Circular Double Linked list with int "content" and pointer to next and prev
 * node*/
typedef struct s_intdlist
{
	int					content;
	struct s_intdlist	*next;
	struct s_intdlist	*prev;
}		t_cdlist;

// push_swap_list.c : Basic List functions

t_cdlist	*ft_intdlstnew(int content);
void		ft_intdlstadd_front(t_cdlist **lst, t_cdlist *node);
void		ft_intdlstadd_back(t_cdlist **lst, t_cdlist *node);
void		ft_intdlstclear(t_cdlist **lst);
int			ft_intdlst_size(t_cdlist *lst);

// push_swap_list_comp.c : Complimintary list operations

t_cdlist	*nxtitem(t_cdlist *lst, int8_t direction);
void		ft_intdlstadd_sorted(t_cdlist **lst, t_cdlist *node, int8_t pref);
int8_t		repeated_num(t_cdlist *lst);

// push_swap.ops.c : official stack operations

char		*swap_first2(t_cdlist **lst);
char		*rotate_up(t_cdlist **lst);
char		*rotate_down(t_cdlist **lst);
char		*top_push(t_cdlist **src, t_cdlist **dst);

// push_swap_list_data.c : reveals data about the list

int			inv_number(t_cdlist *lst, unsigned int n, int8_t dir, int8_t pref);
int			is_sorted(t_cdlist *lst, unsigned int n, int8_t dir, int8_t pref);
int			findmidian(t_cdlist *lst, int n, int8_t dir, int8_t pref);

// push_swap_sort2.c : sort big lists

void		save_move(char **mem, char *mv, int8_t pref);
char		*gsort(t_cdlist **lsta, t_cdlist **lstb, int n, int8_t pref);

// push_swap_sort3.c : sort some regular lists

char		*gsort2(t_cdlist **lsta, t_cdlist **lstb, int n, int8_t pref);

// push_swap_utils.c : (somtimes modified) libft functions used

int			ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strjoin_ps(char **prestr, char *sufstr, int8_t freesuf);
int			o_atoi(char **str, int8_t *flag);

// push_swap_optimization.c : optimize moves

char		*optimal_traverse(t_cdlist **start, t_cdlist **end, int8_t pref);
void		merge_ops(char *str);

#endif