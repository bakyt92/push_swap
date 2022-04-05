


#include "get_next_line.h"
#include <stdio.h>

char	*ft_line_write(char *line, char *main_str)
{
	int	i;

	i = 0;
	while (main_str[i] && main_str[i] != '\n')
	{
		line[i] = main_str[i];
		i++;
	}
	if (main_str[i] == '\n')
	{
		line[i] = main_str[i];
		i++;
	}
	else
	{
		line[i] = '\0';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_del_one_line(char *main_str)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (main_str[i] && main_str[i] != '\n')
		i++;
	if (!main_str[i])
	{
		free(main_str);
		return (NULL);
	}
	temp = (char *) malloc(sizeof(char) * (ft_strlen(main_str) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (main_str[i] != '\0')
		temp[j++] = main_str[i++];
	temp[j] = '\0';
	free(main_str);
	return (temp);
}

char	*ft_get_one_line(char *main_str)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	if (!main_str[i])
		return (NULL);
	while (main_str[i] && main_str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	line = ft_line_write(line, main_str);
	return (line);
}

char	*ft_read_text(int fd, char *str_main)
{
	ssize_t	byte_read;
	char	buf[BUFFER_SIZE + 1];

	byte_read = 1;
	while (!ft_strchr(str_main, '\n') && byte_read != 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(str_main);
			return (NULL);
		}
		buf[byte_read] = '\0';
		str_main = ft_strjoin(str_main, buf);
	}
	return (str_main);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str_main;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	str_main = ft_read_text(fd, str_main);
	if (!str_main)
		return (NULL);
	line = ft_get_one_line(str_main);
	str_main = ft_del_one_line(str_main);
	return (line);
}