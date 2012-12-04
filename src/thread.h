#ifndef thread_h
#define thread_h

typedef struct thread_s {
  void *thread;
  int (*func)(void *);
  void *data;
  char *name;
} thread_t;

thread_t *thread_create( int (*)(void *), void *, char * );
int       thread_cleanup( thread_t * );

#endif

