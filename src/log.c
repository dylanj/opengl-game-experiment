#include "log.h"

#define ERROR_PREFIX   "ERROR:"
#define WARNING_PREFIX "WARNING:"
#define DEBUG_PREFIX   "DEBUG:"

// TODO: dry this up and print prefixes

int log_error( char *format, ... ) {
  va_list args;
  va_start( args, format );
  vprintf( format, args );
  va_end( args );
}

int log_debug( char *format, ... ) {
  va_list args;
  _log("debug: ", "\n", format, &args );
}

int _log( char *prefix, char *suffix, char *format, va_list *args ) {
  if ( prefix != NULL )
    fprintf( stdout, prefix );

  va_start( *args, format );
  vprintf( format, *args );
  va_end( *args );

  if ( suffix != NULL )
    fprintf( stdout, suffix );
}
