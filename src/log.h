#include <stdio.h>
#include <stdarg.h>

void _log( char*, char*, char*, va_list );
void log_error( char*, ... );
void log_debug( char*, ... );
