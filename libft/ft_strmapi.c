/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labrown <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:51:04 by labrown           #+#    #+#             */
/*   Updated: 2017/12/18 15:51:06 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int i, char c))
{
	char			*newstr;
	unsigned int	i;

	i = 0;
	newstr = NULL;
	if (s)
	{
		newstr = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
		if (newstr)
		{
			while (*(s + i))
			{
				*(newstr + i) = (*f)(i, *(s + i));
				i++;
			}
			*(newstr + i) = '\0';
		}
	}
	return (newstr);
}
