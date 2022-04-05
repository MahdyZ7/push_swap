/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:14:08 by ayassin           #+#    #+#             */
/*   Updated: 2022/04/04 11:00:54 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// The main push_swap file

static char	*sort3(t_cdlist **lsta, int8_t pref);
static char	*sort6(t_cdlist **lsta, t_cdlist **lstb, int8_t pref);
static int	add_nums(int argv, char **argc, t_cdlist **lst_a);
static void	ft_sort(t_cdlist **lst_a, t_cdlist **lst_b, int n);
int			main(int argv, char **argc);

/* Sort list (lsta) when it has 3 or less numbers. ascending order for
(pref) >= 0*. descending order otherwise*/
static char	*sort3(t_cdlist **lsta, int8_t pref)
{
	int			inv;
	char		*str;
	t_cdlist	*t;

	str = NULL;
	while (is_sorted(*lsta, -1, 1, pref) != pref)
	{
		t = *lsta;
		inv = inv_number(*lsta, -1, 1, pref);
		if (inv == 3 || ft_intdlst_size(*lsta) == 2)
			save_move(&str, swap_first2(lsta), pref);
		else if (inv == 2 && !((t->content < t->next->content) ^ (pref >= 0)))
			save_move(&str, rotate_down(lsta), pref);
		else if (inv == 1 && !((t->content < t->prev->content) ^ (pref >= 0)))
			save_move(&str, swap_first2(lsta), pref);
		else
			save_move(&str, rotate_up(lsta), pref);
	}
	return (str);
}

/*Sort list (lsta) when it has 6 or less numbers using auxillary list (lstb).
ascending order for (pref) >= 0*. descending order otherwise*/
static char	*sort6(t_cdlist **lsta, t_cdlist **lstb, int8_t pref)
{
	char		*str;
	int			median;
	int			pushed;
	int			len;

	str = NULL;
	pushed = 0;
	len = ft_intdlst_size(*lsta);
	median = findmidian(*lsta, len, 1, pref);
	while (pushed < (len / 2) && len > 3)
	{
		if ((*lsta)->content < median)
		{
			save_move(&str, top_push(lsta, lstb), -pref);
			++pushed;
		}
		else
			save_move(&str, rotate_up(lsta), pref);
	}
	ft_strjoin_ps(&str, sort3(lsta, 1), 1);
	ft_strjoin_ps(&str, sort3(lstb, -1), 1);
	while (pushed--)
		save_move(&str, top_push(lstb, lsta), pref);
	return (str);
}

/* add arguments from string array (argc) to list (lsta)*/
static int	add_nums(int argv, char **argc, t_cdlist **lst_a)
{
	int		num;
	int8_t	f;
	char	*temp;

	num = 1;
	f = 0;
	temp = NULL;
	if (argv < 2)
		return (0);
	while (num < argv && !f)
	{
		temp = argc[num];
		while (*temp && !f)
		{
			while (*temp == 32 || (*temp >= 9 && *temp <= 13))
				temp++;
			if (*temp == '\0')
				break ;
			ft_intdlstadd_back(lst_a, ft_intdlstnew(o_atoi(&temp, &f)));
			if (*temp != '\0' && (*temp == '+' || *temp == '-'))
				f = 1;
		}
		num++;
	}
	return (f);
}

/* Sort list (lst_a) of size (n) using auxillary list (lst_b)*
and write no of moves to standard output*/
static void	ft_sort(t_cdlist **lst_a, t_cdlist **lst_b, int n)
{
	char	*moves;

	if (n < 7)
		moves = sort6(lst_a, lst_b, 1);
	else if (n < 120 && n > 80)
		moves = gsort2(lst_a, lst_b, n, 1);
	else
		moves = gsort(lst_a, lst_b, n, 1);
	if (moves)
	{
		merge_ops(moves);
		n = write(1, moves, ft_strlen(moves));
		free(moves);
	}
}

/* The push swap*/
int	main(int argv, char **argc)
{
	t_cdlist	*lst_a;
	t_cdlist	*lst_b;
	int8_t		f;

	lst_a = NULL;
	lst_b = NULL;
	f = 0;
	f = add_nums(argv, argc, &lst_a);
	f += repeated_num(lst_a);
	if (f)
		write(1, "Error\n", 6);
	else if (argv > 1)
		ft_sort(&lst_a, &lst_b, ft_intdlst_size(lst_a));
	ft_intdlstclear(&lst_a);
	ft_intdlstclear(&lst_b);
	return (0);
}
