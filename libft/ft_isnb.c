#include "libft.h"

int	ft_isnb(char *nb)
{
	if (*nb == '-')
		nb++;
	while (*nb != '\0')
	{
		if (ft_isdigit(*nb) == 0)
			return (0);
		nb++;
	}
	return (1);
}
