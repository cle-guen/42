
#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr(int fd, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(fd, str[i]);
		i++;
	}
}

void	read_file(char *path)
{
	int read_ret;
	int fd;
	char buffer;
	
	read_ret = 1;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(2, "cheat\n");
		return;
	}
	while (read_ret)
	{
		read_ret = read(fd, &buffer, 1);
		if (read_ret == -1)
		{
			ft_putstr(2, "cheatu\n");
			return;
		}
		if (read_ret == 0)
			return;
		ft_putchar(1, buffer);
	}
	close(fd);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr(2, "File name missing.\n");
	if (argc == 2)
		read_file(argv[1]);
	if (argc > 2) 
		ft_putstr(2, "Too many arguments.\n");
	return (0);
}
