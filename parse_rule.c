/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rule.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 23:24:42 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/19 17:58:14 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		parse_template_no(char *line, char *reg, t_var *var)
{
	int		i;
	char	*temp;
	char	*newline;

	newline = line;
	i = 3;
	while (ft_isspace(newline[i]))
		i++;
	if (newline[i] < 33 || newline[i] > 126)
		format_rule_err(line, reg);
	temp = ft_strtrim(&newline[i], " \t");
	var->no = temp;
	if (reg[1] == '0')
		reg[1] = '1';
	else
		exist_rule_err(line, reg);
	temp = ft_strrchr(var->no, '.');
	if (temp[4] != 0 || (!ft_strnstr(var->no, ".xpm", ft_strlen(var->no))))
		extension_err(line, reg);
}

void		parse_template_so(char *line, char *reg, t_var *var)
{
	int		i;
	char	*temp;

	i = 3;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] < 33 || line[i] > 126)
		format_rule_err(line, reg);
	temp = ft_strtrim(&line[i], " \t");
	var->so = temp;
	if (reg[2] == '0')
		reg[2] = '1';
	else
		exist_rule_err(line, reg);
	temp = ft_strrchr(var->so, '.');
	if (temp[4] != 0 || (!ft_strnstr(var->so, ".xpm", ft_strlen(var->so))))
		extension_err(line, reg);
}

void		parse_template_we(char *line, char *reg, t_var *var)
{
	int		i;
	char	*temp;

	i = 3;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] < 33 || line[i] > 126)
		format_rule_err(line, reg);
	temp = ft_strtrim(&line[i], " \t");
	var->we = temp;
	if (reg[3] == '0')
		reg[3] = '1';
	else
		exist_rule_err(line, reg);
	temp = ft_strrchr(var->we, '.');
	if (temp[4] != 0 || (!ft_strnstr(var->we, ".xpm", ft_strlen(var->we))))
		extension_err(line, reg);
}

void		parse_template_ea(char *line, char *reg, t_var *var)
{
	int		i;
	char	*temp;

	i = 3;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] < 33 || line[i] > 126)
		format_rule_err(line, reg);
	temp = ft_strtrim(&line[i], " \t");
	var->ea = temp;
	if (reg[4] == '0')
		reg[4] = '1';
	else
		exist_rule_err(line, reg);
	temp = ft_strrchr(var->ea, '.');
	if (temp[4] != 0 || (!ft_strnstr(var->ea, ".xpm", ft_strlen(var->ea))))
		extension_err(line, reg);
}

void		parse_template_s(char *line, char *reg, t_var *var)
{
	int		i;
	char	*temp;

	i = 2;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] < 33 || line[i] > 126)
		format_rule_err(line, reg);
	temp = ft_strtrim(&line[i], " \t");
	var->s = temp;
	if (reg[5] == '0')
		reg[5] = '1';
	else
		exist_rule_err(line, reg);
	temp = ft_strrchr(var->s, '.');
	if (temp[4] != 0 || (!ft_strnstr(var->s, ".xpm", ft_strlen(var->s))))
		extension_err(line, reg);
}
