
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	int				i;

	str = (unsigned char *) b;
	i = 0;
	while (i < (int) len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}
