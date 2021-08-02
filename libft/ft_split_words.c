#include "libft.h"
#include <stdio.h>

static int ft_check_space(char c)
{
    if (c == '\t' || c == '\v' || c == '\f' || c == '\r'
		|| c == '\n' || c == ' ')
        return (1);
    return (0);
}

static char	*find_chain(char *str, int *size)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (flag != 1)
	{
		while ((str[i] != '\0') &&  ft_check_space(str[i]) == 0)
			i++;
		if (i > 0)
			flag = 1;
		else
		{
			str++;
			i = 0;
		}
	}
	*size = i;
	return (str);
}

static int	count_lines(char *str)
{
	int	i;
	int	count;

	count = 0;
	while (*str != '\0')
	{
		i = 0;
		while (*str && ft_check_space(*str) == 1)
			str++;
		while (str[i] && ft_check_space(str[i]) == 0)
			i++;
		if (i)
			count++;
		str = str + i;
	}
	return (count);
}

static char	*copy(char *str, int size)
{
	int		i;
	char	*chain;

	i = 0;
	if (size == -1)
	{
		while (str[i] != '\0')
			i++;
		size = i;
	}
	chain = (char *)malloc(sizeof(char) * (size + 1));
	if (chain == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		chain[i] = *str;
		str++;
		i++;
	}
	chain[i] = '\0';
	return (chain);
}

static char	**ft_check(char *str, int *lines)
{
	char	**tab;

	if (str == NULL)
		return (NULL);
	*lines = count_lines(str);
	tab = (char **)malloc(sizeof(char *) * (*lines + 1));
	if (tab == 0)
		return (0);
	return (tab);
}

char	**ft_split_space(const char *s)
{
	char	**tab;
	int		i;
	int		lines;
	int		size_chain;
	char	*str;

	i = 0;
	str = (char *)s;
	tab = ft_check(str, &lines);
	if (tab == NULL)
		return (NULL);
	while (i < lines)
	{
		str = find_chain(str, &size_chain);
		tab[i] = copy(str, size_chain);
		while (size_chain > 0)
		{
			size_chain--;
			str++;
		}
		i++;
	}
	tab[i] = 0;
	return (&tab[0]);
}
