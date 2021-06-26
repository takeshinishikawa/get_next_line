#include "get_next_line.h"

size_t	ft_strlen(const char*s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	counter;
	char	*strjoin;

	counter = 0;
	if (!s1 || !s2)
		return (NULL);
	strjoin = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (strjoin == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		strjoin[counter] = *s1;
		s1++;
		counter++;
	}
	while (*s2 != '\0')
	{
		strjoin[counter] = *s2;
		s2++;
		counter++;
	}
	strjoin[counter] = '\0';
	return (strjoin);
}

char	*ft_strdup(const char *s1)
{
	void	*dst;
	size_t	counter;
	size_t	s1_size;

	s1_size = ft_strlen(s1) + 1;
	dst = (char *)malloc(s1_size);
	counter = 0;
	if (dst == NULL)
		return (NULL);
	while (counter < s1_size)
	{
		((unsigned char *)dst)[counter] = ((unsigned char *)s1)[counter];
		counter++;
	}
	return (dst);
}

size_t	ft_linelen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_linedup(const char *s1)
{
	void	*dst;
	size_t	counter;
	size_t	s1_size;

	s1_size = ft_linelen(s1);
	dst = (char *)malloc(s1_size + 1);
	counter = 0;
	if (dst == NULL)
		return (NULL);
	while (counter < s1_size)
	{
		((unsigned char *)dst)[counter] = ((unsigned char *)s1)[counter];
		counter++;
	}
	((unsigned char *)dst)[counter] = '\0';
	return (dst);
}
