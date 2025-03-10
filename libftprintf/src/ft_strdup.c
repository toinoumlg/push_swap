/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:34:41 by amalangu          #+#    #+#             */
/*   Updated: 2024/11/15 07:51:17 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Returns a pointer to a new string which is a duplicate of the string s.
// Memory for the new  string  is  obtained  with malloc().
char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dup;

	len = ft_strlen(s);
	i = 0;
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
