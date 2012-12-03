#define MSG_XYZ 0

typedef struct net_msg_s {
  unsigned short sender_id;
  unsigned short receiver_id;
  unsigned char type;
  ssize_t length;
  char *data;
} net_msg_t;

net_msg_t*  net_recv_msg();
int         net_send_msg( net_msg_t* );

// private functions
// returns total size of network message
// for use with send()
ssize_t _net_msg_size( net_msg_t* );
