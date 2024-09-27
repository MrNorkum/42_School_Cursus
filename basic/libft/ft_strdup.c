#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t		len;
	char		*dup;

	len = ft_strlen(s1) + 1;
	dup = malloc(sizeof(char) * len);
	if (!dup)
		return (0);
	return (ft_strlcpy(dup, s1, len), (char *)dup);
}
