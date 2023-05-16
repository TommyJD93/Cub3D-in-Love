/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 05:12:53 by aperrone          #+#    #+#             */
/*   Updated: 2023/05/14 05:27:56 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub.h"

char	*ft_strjoin_elements(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;
	char	*old_str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	old_str = str;
	str = ft_strjoin(str, ".cub");
	free(old_str);
	return (str);
}

int	file_validator(char *map_path)
{
	char	*new_path;

	new_path = "./assets/maps/";
	ft_strjoin_elements(new_path, map_path);
	if (new_path == NULL)
		return (-1);
	return (open(new_path, O_RDONLY));
}
