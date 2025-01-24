
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*source;
	unsigned char		*dest;

	source = (const unsigned char *) src;
	dest = (unsigned char *) dst;
	if (dest == source)
		return (dst);
	if (dest > source)
		while (len--)
			dest[len] = source[len];
	else
		while (len--)
			*dest++ = *source++;
	return (dst);
}
