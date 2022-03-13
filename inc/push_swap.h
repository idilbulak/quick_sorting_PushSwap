#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct node
{
	struct node	*prev;
	int			numberfield;
	struct node	*next;
}	t_node;

void		swap(int *x, int *y);
void		sa(struct node *stack_a);
void		sb(struct node *stack_b);
void		ss(struct node *stack_a, struct node *stack_b);

struct node	*rotate(struct node **head, int N);
void		ra(struct node **stack_a);
void		rb(struct node **stack_b);
void		rr(struct node **stack_a, struct node **stack_b);
void		rra(struct node **stack_a);
void		rrb(struct node **stack_b);
void		rrr(struct node **stack_a, struct node **stack_b);

void		pb(struct node **stack_a, struct node **stack_b);
void		pa(struct node **stack_a, struct node **stack_b);

void		printlist(struct node *head);
struct node	*addto_emptylist(struct node *head, int n);
struct node	*addto_beg(struct node *head, int n);
struct node	*addto_end(struct node *head, int n);
int			ft_lstsize(struct node *lst);
struct node	*delete_first(struct node *head);
struct node	*delete_last(struct node *head);
int			find_min(struct node *stack);
int			find_max(struct node *stack);

struct node	*sort_3(struct node *stack_a);
struct node	*sort_5(struct node *stack_a, struct node *stack_b);



# endif