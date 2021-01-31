
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct	s_info{
	int		R[2];
	char	*NO;
	char	*SO;
	char	*EA;
	char	*WE;
	char	*S;
	int		F[3];
	int		C[3];
	char	**map;
}				t_info;

void		take_r(char *s, t_info *var)
{
	int i;
	int k;
	int j;
	char appoggio[15];

	i = 0;
	k = 0;
	while (s[i])
	{
		while (is_space(s[i]) && s[i])
			i++;
		j = 0;
		while ((s[i] >= '0' && s[i] <= '9') && s[i])
		{
			appoggio[j] = s[i];
			i++;
			j++;
		} 
		appoggio[j] = 0;
		if (k < 2 && appoggio[0])
		{
			var->R[k] = ft_atoi(appoggio);
			k++;
		}
		i++;
	}
}

void		take_rgb(char *s, t_info *var, char c)
{
	int i;
	int j;
	int k;
	char *appoggio;

	i = 1;
	k = 0;
	if (!(appoggio = malloc(4)))
		return ;
	while (is_space(s[i]))
		i++;
	while (ft_isdigit(s[i]))
	{
		j = 0;
		while (ft_isdigit(s[i]))
		{
			appoggio[j] = s[i];
			i++;
			j++;
		}
		appoggio[j] = 0;
		if (c == 'F') 
			var->F[k]= ft_atoi(appoggio);
		if (c == 'C') 
			var->C[k]= ft_atoi(appoggio);
		k++;
		if (s[i + 1])
			i++;
	}
}

char		*take_path(char *s, t_info *var)
{
	int i;
	int j;
	char *appoggio;

	i = 2;
	if (!(appoggio = malloc(ft_strlen(s))))
		return (0);
	while (is_space(s[i]))
		i++;
	j = 0;
	while (!is_space(s[i]) && s[i] > 32)
	{
		appoggio[j] = s[i];
		i++;
		j++;
	} 
	appoggio[j] = 0;
	appoggio = alloc(appoggio, 1);
	return (appoggio);
}

void		find_value(char *line, t_info *var)
{
	char	*out;

	if ((out = ft_strnstr(line, "R", ft_strlen(line))))
		take_r(out, &(*var));
	if ((out = ft_strnstr(line, "NO", ft_strlen(line))))
		var->NO = take_path(out, &(*var));
	if ((out = ft_strnstr(line, "SO", ft_strlen(line))))
		var->SO = take_path(out, &(*var));
	if ((out = ft_strnstr(line, "WE", ft_strlen(line))))
		var->WE = take_path(out, &(*var));
	if ((out = ft_strnstr(line, "EA", ft_strlen(line))))
		var->EA = take_path(out, &(*var)); 
	if ((out = ft_strnstr(line, "S ", ft_strlen(line))))
		var->S = take_path(out, &(*var));
	if ((out = ft_strnstr(line, "F", ft_strlen(line))))
		take_rgb(out, &(*var), 'F');
	if ((out = ft_strnstr(line, "C", ft_strlen(line))))
		take_rgb(out, &(*var), 'C');
	if (out)
		free(out);
}

int parsing(int fd, t_info *var)
{
	char *line;
	int i;
	int r;


	r = 1;
	while (r == 1)
	{
		r = get_next_line(fd, &line);
		find_value(line, &(*var));
		printf("%s\n", line);
	}
	printf("R|%d %d| NO|%s| SO|%s| \nWE|%s| EA|%s| S|%s| F|%d %d %d| C|%d %d %d|\n", 
		var->R[0], var->R[1], var->NO, var->SO, var->WE, var->EA, var->S, var->F[0], 
		var->F[1], var->F[2], var->C[0], var->C[1], var->C[2]);
	return (1);
}

int main()
{
	int fd;
	t_info var;
	char *line;

	fd = open("info.cub", O_RDONLY);
	parsing(fd, &var);
}