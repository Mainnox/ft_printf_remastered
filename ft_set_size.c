#include "ft_printf.h"

void        ft_set_size(t_printf *handle)
{
    while (42)
    {
        if (handle->str[handle->index] == 'h')
        {
            handle->index++;
            if (handle->str[handle->index] == 'h')
            {
				if (handle->extra->size < 1)
             	   handle->extra->size = 1;
                handle->index++;
                break;
            }
				if (handle->extra->size < 2)
            handle->extra->size = 2;
            break;
        }
        if (handle->str[handle->index] == 'l')
        {
            handle->index++;
            if (handle->str[handle->index] == 'l')
            {
				if (handle->extra->size < 4)
                handle->extra->size = 4;
                handle->index++;
                break;
            }
				if (handle->extra->size < 3)
            handle->extra->size = 3;
            break;
        }
		if (handle->str[handle->index] == 'j')
				if (handle->extra->size < 5)
			handle->extra->size = 5;
		if (handle->str[handle->index] == 'z')
				if (handle->extra->size < 7)
			handle->extra->size = 7;
		handle->index++;
		break ;
    }
}
