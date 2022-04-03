/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:18:29 by ayassin           #+#    #+#             */
/*   Updated: 2022/04/03 09:35:17 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
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

t_cdlist	*ft_intdlstnew(int content);
void		ft_intdlstadd_front(t_cdlist **lst, t_cdlist *node);
void		ft_intdlstadd_back(t_cdlist **lst, t_cdlist *node);
void		ft_intdlstclear(t_cdlist **lst);
int			ft_intdlst_size(t_cdlist *lst);

t_cdlist	*nxtitem(t_cdlist *lst, int8_t direction);
void		ft_intdlstadd_sorted(t_cdlist **lst, t_cdlist *node, int8_t pref);
int8_t		repeated_num(t_cdlist *lst);

char		*swap_first2(t_cdlist **lst);
char		*rotate_up(t_cdlist **lst);
char		*rotate_down(t_cdlist **lst);
char		*top_push(t_cdlist **src, t_cdlist **dst);

int			inv_number(t_cdlist *lst, unsigned int n, int8_t dir, int8_t pref);
int			is_sorted(t_cdlist *lst, unsigned int n, int8_t dir, int8_t pref);
int			findmidian(t_cdlist *lst, int n, int8_t dir, int8_t pref);

char		*gsort(t_cdlist **lsta, t_cdlist **lstb, int n, int8_t pref);
char		*gsort2(t_cdlist **lsta, t_cdlist **lstb, int n, int8_t pref);

int			ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strjoin_ps(char **prestr, char *sufstr, int8_t freesuf);
int			o_atoi(char **str, int8_t *flag);

char		*optimal_traverse(t_cdlist **start, t_cdlist **end, int8_t pref);
void		save_move(char **mem, char *mv, int8_t pref);
void		merge_ops(char *str);

#endif