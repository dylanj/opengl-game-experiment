#include <stdio.h>
#include <stdarg.h>

int _log( char*, char*, char*, va_list* );
int log_error( char*, ... );
int log_debug( char*, ... );
