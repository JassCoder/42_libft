/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 23:58:36 by jsingh            #+#    #+#             */
/*   Updated: 2026/07/06 11:22:52 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

int	main(void)
{
	t_list	*list = NULL;
	t_list	*node1;
	t_list	*node2;

	// Create and add first node
	node1 = ft_lstnew("Hello");
	ft_lstadd_front(&list, node1);
	printf("Test 1: %s\n", (char *)list->content);

	// Create and add second node
	node2 = ft_lstnew("World");
	ft_lstadd_front(&list, node2);
	printf("Test 2: %s → %s\n", 
	       (char *)list->content,      // World
	       (char *)list->next->content); // Hello

	// Free all nodes (in reverse order of addition)
	free(node2);
	free(node1);

	return (0);
}*/