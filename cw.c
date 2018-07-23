#include "cw.h"

void	ft_file_name(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (i != 0 && str[++i] == 's' && str[++i] == '\0')
				return 	;
			exit(ft_printf("BAD NAME\n"));
		}
		i++;
	}
}

void	ft_fill_info(char *answer, int fd, char *str, int max)
{
	int		i;
	int		len;

	i = 0;
	len = 1;
	while (*str == ' ')
		str++;
	if (*str++ != '\"')
		exit(ft_printf("ERROR1\n"));
	while (str[i] && str[i] != '\"')
	{
		i++;
		len++;
		if (str[i] == '\0' || str[i] == '\"')
		{
			if (len > max)
				exit(ft_printf("ERROR2\n"));
			ft_strncat(answer, str, i);
			if (str[i] == '\"')
				break ;
			ft_strcat(answer, "\n");
			len++;
			get_next_line(fd, &str);
			i = 0;
		}
	}
}

void	ft_read_header(int fd)
{
	header_t h;
	char	*str;

	h.magic = COREWAR_EXEC_MAGIC;
	while (1)
	{
		get_next_line(fd, &str);
		if (ft_strncmp(str, ".name", 4) == 0)
		{
			str += 5;
			ft_fill_info(h.prog_name, fd, str, PROG_NAME_LENGTH);
			ft_printf("name %s\n",h.prog_name);
		}
		else if (ft_strncmp(str, ".comment", 8) == 0)
		{
			str += 8;
			ft_fill_info(h.comment, fd, str, COMMENT_LENGTH);
			ft_printf("com %s\n",h.comment);
			break ;
		}
		else
			exit(ft_printf("ERROR3\n"));
	}
}

int		main (int argc, char *argv[])
{
	int		fd;
	char	*str;

	if (argc != 2)
	{
		ft_printf("ER1\n");
		return (0);
	}
	ft_file_name(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	ft_read_header(fd);
	return (0);
	// while (get_next_line(fd, &str))
	// {
	// 	while (*str == ' ' || *str == '\t')
	// 		str++;
	// }
}