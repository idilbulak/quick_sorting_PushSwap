#include "../inc/push_swap.h"

struct node	*delete_first(struct node *head)
{
	struct node	*temp;

	temp = head;
	head = head->next;
	free(temp);
	temp = NULL;
	head->prev = NULL;
	return (head);
}

struct node	*delete_last(struct node *head)
{
	struct node	*temp;
	struct node	*temp2;

	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp2 = temp->prev;
	temp2->next = NULL;
	free(temp);
	return (head);
}

int	find_min(struct node *stack)
{
	struct node	*temp;
	int			result;

	if (stack != NULL)
	{
		temp = stack;
		result = temp->numberfield;
		while (temp != NULL)
		{
			if ((temp->numberfield < result))
			{
				result = temp->numberfield;
			}
			temp = temp->next;
		}
	}
	return (result);
}

int	find_max(struct node *stack)
{
	struct node	*temp;
	int			result;

	if (stack != NULL)
	{
		temp = stack;
		result = temp->numberfield;
		while (temp != NULL)
		{
			if ((temp->numberfield > result))
			{
				result = temp->numberfield;
			}
			temp = temp->next;
		}
	}
	return (result);
}

int	find_next_min(struct node *stack, int min)
{
	struct node	*temp;
	int			result;

	temp = stack;
	while (temp->numberfield == min || temp->numberfield < min)
		temp = temp->next;
	result = temp->numberfield;
	while (temp)
	{
		if (temp->numberfield < result && temp->numberfield > min)
		{
			result = temp->numberfield;
		}
		temp = temp->next;
	}
	return (result);
}
