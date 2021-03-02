#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{

	t_list	*lst;

	char str[]= "abcd";
	ft_putnbr_fd(-1234, 1);
	lst = ft_lstnew(str);
	printf("\n content= %s", lst -> content);
	return (0);
}
