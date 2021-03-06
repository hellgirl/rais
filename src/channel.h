#ifndef rais_channel_h
#define rais_channel_h

typedef struct chanstate_t_ {
  amqp_channel_t channel;
  int status; /* zero for OK, nonzero is an AMQP error code */
  /* TODO: most-recently-declared-queue */

  amqp_bytes_t next_exchange;
  amqp_bytes_t next_routing_key;
  uint64_t body_remaining;
  syncpipe_out_t content_pipe;
} chanstate_t;

extern chanstate_t *new_channel_state(amqp_channel_t channel);
extern void destroy_channel_state(chanstate_t *chan);

extern void handle_channel_normal(connstate_t *conn, amqp_frame_t *frame, chanstate_t *chan);
extern void handle_channel_props(connstate_t *conn, amqp_frame_t *frame, chanstate_t *chan);
extern void handle_channel_body(connstate_t *conn, amqp_frame_t *frame, chanstate_t *chan);

#endif
