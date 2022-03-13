/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   doublylinklist_utils.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 12:50:06 by ibulak        #+#    #+#                 */
/*   Updated: 2022/03/09 12:50:18 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	printlist(struct node *head)
{
	struct node	*current;

	current = head;
	if (!head)
		return ;
	while (current != NULL )
	{
		printf("%d", current -> numberfield);
		current = current->next;
	}
	printf("\n");
	free(current);
}

struct node	*addto_emptylist(struct node *head, int n)
{
	struct node	*temp;

	temp = malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->numberfield = n;
	temp->next = NULL;
	head = temp;
	return (head);
}

struct node	*addto_beg(struct node *head, int n)
{
	struct node	*temp;

	temp = malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->numberfield = n;
	temp->next = NULL;
	temp->next = head;
	head->prev = temp;
	head = temp;
	return (head);
}

struct node	*addto_end(struct node *head, int n)
{
	struct node	*temp_prev;
	struct node	*temp_next;

	temp_next = malloc(sizeof(struct node));
	temp_next->prev = NULL;
	temp_next->numberfield = n;
	temp_next->next = NULL;
	temp_prev = head;
	while (temp_prev->next != NULL)
		temp_prev = temp_prev->next;
	temp_prev->next = temp_next;
	temp_next->prev = temp_prev;
	return (head);
}

int	ft_lstsize(struct node *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
