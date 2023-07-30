/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:42:36 by acepni            #+#    #+#             */
/*   Updated: 2023/07/24 14:53:14 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_node_vals(t_list *a, t_list *b)
{
	int	temp;

	temp = a->value;
	a->value = b->value;
	b->value = temp;
}

void	selection_sort_ll(t_list *head)
{
	t_list	*temp;
	t_list	*current;
	t_list	*min_node;

	current = head;
	min_node = NULL;
	temp = NULL;
	while (current != NULL)
	{
		min_node = current;
		temp = current->next;
		while (temp != NULL)
		{
			if (temp->value < min_node->value)
				min_node = temp;
			temp = temp->next;
		}
		swap_node_vals(current, min_node);
		current = current->next;
	}
}

void	assign_index(t_list **stack, int value, int index)
{
	t_list	*head;

	head = *stack;
	while (head)
	{
		if (head->value == value)
		{
			head->index = index;
			break ;
		}
		head = head->next;
	}
}

t_list	*ft_copy_list(t_list *stack)
{
	t_list	*head;
	t_list	*new;
	t_list	*copy;

	head = stack;
	copy = NULL;
	while (head)
	{
		new = ft_lstnew(head->value);
		ft_lstadd_back(&copy, new);
		head = head->next;
	}
	return (copy);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	t_list	*temp;
	int		index;

	if (!stack)
		return ;
	head = ft_copy_list(*stack);
	if (!head)
		return ;
	selection_sort_ll(head);
	index = 0;
	temp = head;
	while (head)
	{
		assign_index(stack, head->value, index);
		index++;
		head = head->next;
	}
	free_stack(&temp);
}
