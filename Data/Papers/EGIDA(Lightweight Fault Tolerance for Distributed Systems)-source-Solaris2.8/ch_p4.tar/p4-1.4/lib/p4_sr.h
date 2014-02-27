#ifndef _P4_SR_H
#define _P4_SR_H

#ifdef  __cplusplus
extern "C" {
#endif

struct p4_queued_msg;  /* for c++ folks; defined below */
struct p4_msg_queue {
    p4_monitor_t m;
    p4_lock_t ack_lock;
    struct p4_queued_msg *first_msg, *last_msg;
};

#include "p4_sr_external.h"

#ifdef  __cplusplus
};
#endif
#endif
