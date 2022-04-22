
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*a;

	if (lst == NULL && del == NULL)
		return ;
	while (*lst)
	{
		a = (*lst)->next;
		del((*lst));
		*lst = a;
	}
	*lst = NULL;
}
