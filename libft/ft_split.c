/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaga     <k222ryousuke@gmail.com   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:14:45 by rkaga             #+#    #+#             */
/*   Updated: 2024/10/26 17:55:39 by rkaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_words(char const *s, char c)
{
	size_t	n;
	size_t	k;

	n = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		k = 0;
		while (*s && *s != c)
		{
			k++;
			s++;
		}
		if (k == 0)
			continue ;
		n++;
	}
	return (n);
}

static int	skip_split(char **s, char c)
{
	size_t	k;
	char	*s_;

	s_ = *s;
	k = 0;
	while (*s_ && *s_ == c)
		s_++;
	while (*s_ && *s_ != c)
	{
		k++;
		s_++;
	}
	*s = s_;
	return (k);
}

static void	*free_split(char **split, size_t num)
{
	char	*head;
	char	*t;
	size_t	i;

	head = *split;
	i = 0;
	while (i < num)
	{
		t = head + 1;
		free(head);
		head = t;
	}
	free(split);
	return (NULL);
}

void	ft_freesplit(char **strs)
{
	char	**head;
	char	**t;

	head = strs;
	while (*head)
	{
		t = head + 1;
		free(*head);
		head = t;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	num;
	size_t	k;

	i = 0;
	num = get_words(s, c);
	split = ft_calloc(num + 1, sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (i++ < num && *s)
	{
		k = skip_split((char **)&s, c);
		if (k == 0)
			continue ;
		split[i - 1] = ft_substr(s - k, 0, k);
		if (split[i - 1] == NULL)
			return (free_split(split, i - 1));
	}
	return (split);
}
