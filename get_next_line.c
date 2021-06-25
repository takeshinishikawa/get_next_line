#include <stdio.h>
#include "get_next_line.h"

int	ft_transfer_line(char **read_content, char **line)
{
	size_t	i;
	char	*aux;

	i = 0;
	while ((*read_content)[i] != '\n' && (*read_content)[i] != '\0')
		i++;
	if ((*read_content)[i] == '\n')
	{
		*line = ft_linedup(*read_content);
		aux = ft_strdup((*read_content) + i + 1);
		free(*read_content);
		*read_content = aux;
		return (1);
	}
	*line = ft_strdup(*read_content);
	free(*read_content);
	return (0);
}

static int	found_line(char *read_content)
{
	int	i;

	i = 0;
	if (read_content == NULL)
		return (0);
	while (read_content[i])
	{
		if (read_content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static void	ft_cpy_content(char **read_content, char *buffer)
{
	if (!*read_content && !buffer)
		return ;
	else if (!*read_content && buffer)
		*read_content = ft_strdup(buffer);
	else
		*read_content = ft_strjoin(*read_content, buffer);
	return ;
}

int	get_next_line(int fd, char **line)
{
	static char	*read_content;
	int			char_read;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL || line == NULL || fd == -1 || BUFFER_SIZE <= 0)
		return (-1);
	char_read = 1;
	while (char_read > 0 && found_line(read_content) == 0)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		buffer[char_read] = '\0';
		ft_cpy_content(&read_content, buffer);
	}
	free(buffer);
	if (char_read == -1)
		return (-1);
	return (ft_transfer_line(&read_content, line));
}
