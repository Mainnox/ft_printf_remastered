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
                handle->extra->size = 1;
                handle->index++;
                break;
            }
            handle->extra->size = 2;
            break;
        }
        if (handle->str[handle->index] == 'l')
        {
            handle->index++;
            if (handle->str[handle->index] == 'l')
            {
                handle->extra->size = 4;
                handle->index++;
                break;
            }
            handle->extra->size = 3;
            break;
        }
    }
}