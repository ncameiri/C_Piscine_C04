/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncameiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:45:03 by ncameiri          #+#    #+#             */
/*   Updated: 2020/11/02 17:59:52 by ncameiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

int		ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

bool	is_base_valid(char *str)
{
	char	*curr;
	int		index;
	int		jndex;

	curr = str;
	if (str == 0 || ft_strlen(str) <= 1)
		return (false);
	while (*curr)
	{
		if (*curr == '\t' || *curr == '\n' || *curr == '\v' || *curr == '\f'
			|| *curr == '\r' || *curr == ' ' || *curr == '+' || *curr == '-')
			return (false);
		curr++;
	}
	index = 0;
	while (index < curr - str)
	{
		jndex = index + 1;
		while (jndex < curr - str)
			if (str[index] == str[jndex++])
				return (false);
		index++;
	}
	return (true);
}

void	ft_putnbr_base_recursiva(int number, char *base, int baseleng)
{
	if (number == -2147483648)
	{
		ft_putnbr_base_recursiva(number / baseleng, base, baseleng);
		write(1, &(base[-(number % baseleng)]), 1);
		return ;
	}
	if (number < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base_recursiva(-number, base, baseleng);
		return ;
	}
	if (number > baseleng - 1)
		ft_putnbr_base_recursiva(number / baseleng, base, baseleng);
	write(1, &(base[number % baseleng]), 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	baseleng;

	if (!is_base_valid(base))
		return ;
	baseleng = ft_strlen(base);
	ft_putnbr_base_recursiva(nbr, base, baseleng);
}
