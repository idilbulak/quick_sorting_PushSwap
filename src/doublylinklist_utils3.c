/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   doublylinklist_utils3.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 15:06:17 by ibulak        #+#    #+#                 */
/*   Updated: 2022/03/15 17:10:28 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_index(struct node *stack_a, int numberfield)
{
	struct node	*temp;
	int			count;

	temp = stack_a;
	count = 1;
	while (temp)
	{
		if (temp->numberfield == numberfield)
			return (count);
		count++;
		temp = temp->next;
	}
	return (count);
}
