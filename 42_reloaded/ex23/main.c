#include "ft_point.h"
#include <stdio.h>
void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int		main(void)
{
t_point		bite;

set_point(&bite);
printf("%d, %d", bite.x, bite.y);
return (0);
}
