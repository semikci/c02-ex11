/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekmekci <sekmekci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 03:49:06 by sekmekci          #+#    #+#             */
/*   Updated: 2023/09/10 16:18:08 by sekmekci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void cassign(int *f)
{
	
}

int	return_size(char *a)
{
	int	p;
	
	p = 0;
	while((a[p] != '\0') || (a[p+1] != '\0'))
		p++;
		
	return p;
}

char *fonkk(char *a,char *g,int b)
{
	int i;
	int size;

	i=0;
	size = return_size(a);
	
	while(i <= size + 2)
	{
		if(b == i)
		{
			g[i] = ' ';
			i++;
			g[i] = ' ';
			i++;
			g[i] = ' ';
			i++;
		}
		g[i] = a[i-2];
		i++; 
	}
	return g;
}

void	ft_putstr_non_printable(char *str)
{
	int	size;
	int		i;
	int		k;
	char	*a;
	int		b;
	
	size = return_size(str);
	
	char g[size +2];

	a = "0123456789abcdef";
	i = 0;
	while (i < size)
	{
		if (str[i] < 32 || str[i] > 126)
		{
			/*str = fonkk(str,g,i);*/
			b = i;
			k = str[i];
			str = fonkk(str,g,i);
			str[b + 1] = '\\';
			str[b + 2] = a[k / 16];
			str[b + 3] = a[k % 16];
		
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		write(1, &g[i], 1);
		i++;
	}
}

int	main(void)
{
	char	str[23] =  "Coucou\0 tu vas bien ?"; 

	ft_putstr_non_printable(str);
}
