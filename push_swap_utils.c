/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:22:09 by ayassin           #+#    #+#             */
/*   Updated: 2022/04/03 22:13:12 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// libft functions used

int		ft_strlen(const char *s);
int		ft_strjoin_ps(char **prestr, char *sufstr, int8_t freesuf);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* Returns length of string*/
int	ft_strlen(const char *s)
{
	int	len;

	if (s == NULL)
		return (0);
	len = -1;
	while (s[++len])
		;
	return (len);
}

/* join strinig (sufstr) to the end of (prestr) and returns the joined string.
prestr is freed and sufstr is freed if(freesuf) is true (Modified)*/
int	ft_strjoin_ps(char **prestr, char *sufstr, int8_t freesuf)
{
	int		i1;
	int		i2;
	char	*fullstr;

	i1 = 0;
	i2 = 0;
	fullstr = (char *)malloc(ft_strlen(*prestr) + ft_strlen(sufstr) + 1);
	if (fullstr == NULL)
		return (0);
	while (*prestr && (*prestr)[i1])
	{
		fullstr[i1] = (*prestr)[i1];
		++i1;
	}
	while (sufstr && sufstr[i2])
		fullstr[i1++] = sufstr[i2++];
	fullstr[i1] = 0;
	if (*prestr)
		free (*prestr);
	if (freesuf)
		free (sufstr);
	*prestr = fullstr;
	return (1);
}

/* Returns the first occurenc of char "c" in string "s" (null inclusive).
Returns NULL otherwise*/
char	*ft_strchr(const char *s, int c)
{
	int	pos;

	pos = 0;
	c = (unsigned char) c;
	while (s[pos])
	{
		if (s[pos] == c)
			return ((char *)&(s[pos]));
		pos++;
	}
	if (s[pos] == c)
		return ((char *)&(s[pos]));
	return (0);
}

/* Compare the first "n" chars from strings "s1" & "s2".
Return the diffrence in the first char or 0 if no diffrence is found*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	if (!n)
		return (0);
	while (pos < (n - 1) && s1[pos] && s2[pos] && (unsigned char)s1[pos]
		== (unsigned char)s2[pos])
		pos++;
	return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
}

/*ASCII string "str" converted and returned as an integer (Modified)*/
int	o_atoi(char **str, int8_t *flag)
{
	int				sign;
	unsigned int	num;

	sign = 1;
	num = 0;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	if (**str < '0' || **str > '9')
		(*flag)++;
	while (**str >= '0' && **str <= '9' && !(*flag))
	{
		num = num * 10 + **str - '0';
		if ((num >> 31) && !(sign == -1 && ((num - 1) >> 31 == 0)))
			(*flag)++;
		(*str)++;
	}
	return (num * sign);
}
