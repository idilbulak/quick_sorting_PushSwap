/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 20:08:13 by ibulak        #+#    #+#                 */
/*   Updated: 2022/03/09 20:52:13 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

struct node	*rotate(struct node **head, int N)
{
	struct node	*current;
	struct node	*nthnode;	
	int			count;

	current = *head;
	nthnode = current;
	count = 1;
	while (count < N && current != NULL)
	{
		current = current->next;
		count++;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = *head;
	(*head)->prev = current;
	*head = nthnode->next;
	(*head)->prev = NULL;
	nthnode->next = NULL;
	return (*head);
}

void	ra(struct node **stack_a)
{
	rotate(stack_a, 1);
	printf("ra\n");
}

void	rb(struct node **stack_b)
{
	rotate(stack_b, 1);
	printf("rb\n");
}

void	rr(struct node **stack_a, struct node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	printf("rr\n");
}
