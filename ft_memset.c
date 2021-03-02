#include <stdio.h>
#include <unistd.h>



void	*ft_memset(void *b, int c, size_t len)
{
	char *a;

	a = (char *)b;
	while (len > 0)
	{
		*a = (char)c;
		a++;
		len--;
	}
	return (b);
}

int main (void) {
   int ch;

   for( ch = 75 ; ch <= 100; ch++ ) {
      printf("ASCII value = %d, Character = %c\n", ch , ch );
   }

   return(0);
}
