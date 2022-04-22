
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a;
	t_list	*b;

	if (lst == NULL || f == NULL)
		return (NULL);
	a = ft_lstnew(f(lst->content));
	if (!a)
	{
		return (NULL);
	}
	b = a;
	lst = lst->next;
	while (lst)
	{
		a = ft_lstnew(f(lst->content));
		if (!a)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&b, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&b, a);
	}
	return (b);
}
