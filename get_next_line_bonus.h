#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h> 
# include <stdlib.h>
# include <stddef.h>
# define OPEN_MAX 1024

size_t	ft_strlen(const char*s);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(const char *s1);

size_t	ft_linelen(const char*s);

char	*ft_linedup(const char *s1);

int		get_next_line(int fd, char **line);

#endif