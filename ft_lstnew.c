/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsingh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 23:05:48 by jsingh            #+#    #+#             */
/*   Updated: 2026/07/05 23:56:20 by jsingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*#include <stdio.h>
int main(void)
{
    // Test 1: Create node with string
    t_list *node1 = ft_lstnew("Hello");
    printf("Test 1 - String: %s\n", (char *)node1->content);
    
    // Test 2: Create node with integer
    int x = 100;
    t_list *node2 = ft_lstnew(&x);
    printf("Test 2 - Integer: %d\n", *(int *)node2->content);
    
    // Test 3: Create node with NULL
    t_list *node3 = ft_lstnew(NULL);
    printf("Test 3 - NULL: %p\n", node3->content);
    
    // Test 4: Link nodes
    node1->next = node2;
    node2->next = node3;
    printf("Test 4 - Linked: %s -> %d -> NULL\n", 
           (char *)node1->content, 
           *(int *)node1->next->content);

    // Free memory
    free(node1);
    free(node2);
    free(node3);

    return (0);
}*/