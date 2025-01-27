/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 08:41:56 by aperrone          #+#    #+#             */
/*   Updated: 2023/03/05 08:22:56 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTFT_H
# define LISTFT_H
#include "cub.h"

t_node	*new_(char *content, int id);
void	add_h(t_node **h, t_node *node);
void	add_t(t_node **h, t_node *node);
void	del_h(t_node **h);
void	del_t(t_node **h);
void	del_node(t_node **stack, int n);
void	freelist(t_node **h);
void	freenode(t_node	*h);
void	printlist(t_node **h);
void	deinit(t_node *node);
void	relister(t_node **h);
int		len_list(t_node	**h);
char	**list_to_matrix(t_node **head);
t_node	*matrix_to_list(char **matrix);
int		src_in_list(t_node	**h, char *field);
void	list_point_to(t_node **list, int id);
char	*key_fetcher(char *content);
void	type_eraser(t_node *h);
void	freecontent(t_node	*h);

#endif
