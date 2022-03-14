/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 12:48:06 by ibulak        #+#    #+#                 */
/*   Updated: 2022/03/09 12:49:13 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	sa(struct node *stack_a)
{
	if (ft_lstsize(stack_a) > 1)
	{
		swap(&(*stack_a).numberfield, &(*stack_a).next->numberfield);
		printf("sa\n");
	}
}

void	sb(struct node *stack_b)
{
	if (ft_lstsize(stack_b) > 1)
	{
		swap(&(*stack_b).numberfield, &(*stack_b).next->numberfield);
		printf("sb\n");
	}
	
}

void	ss(struct node *stack_a, struct node *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	printf("ss\n");
}