/*
 * fifo.c - syslogd implementation for windows, simple and fast queue
 *
 * Created by Alexander Yaworsky
 *
 * This replacement eliminates strange page faults which were
 * with glib's 2.6.3 queues.
 *
 * THIS SOFTWARE IS NOT COPYRIGHTED
 *
 * This source code is offered for use in the public domain. You may
 * use, modify or distribute it freely.
 *
 * This code is distributed in the hope that it will be useful but
 * WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 * DISCLAIMED. This includes but is not limited to warranties of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#include <stdio.h>
#include <windows.h>
#include <glib.h>
#include <syslog.h>
#include <syslogd.h>

/******************************************************************************
 * fifo_create
 *
 * Allocate and initialize fifo structure. Add an empty item to the fifo.
 */
struct fifo* fifo_create()
{
    struct fifo *ret = g_malloc( sizeof(struct fifo) );
    struct fifo_item *guard_item= g_malloc( sizeof(struct fifo_item) );
    ret->first = guard_item;
    ret->last = guard_item;
    guard_item->next = NULL;
    guard_item->payload = NULL;
    return ret;
}

/******************************************************************************
 * fifo_destroy
 *
 * Delete all items and free fifo structure.
 */
void fifo_destroy( struct fifo* queue )
{
    struct fifo_item *item;

    while( (item = queue->first) != NULL )
    {
        queue->first = item->next;
        g_free( item );
    }
    g_free( queue );
}

/******************************************************************************
 * fifo_push
 *
 * Add item to queue.
 */
void fifo_push( struct fifo* queue, void* data )
{
    struct fifo_item *item = g_malloc( sizeof(struct fifo_item) );
    item->next = NULL;
    item->payload = data;
    queue->last->next = item;
    queue->last = item;
}

/******************************************************************************
 * fifo_pop
 *
 * Extract item from queue.
 * Consider four possible conditions:
 * 1) next == NULL, payload == NULL: there is the only one empty item
 *    in the queue; leave it and return NULL
 * 2) next == NULL, payload != NULL: leave item and return its payload;
 *    set item's payload NULL
 * 3) next != NULL, payload == NULL: queue was empty when a new item was
 *    added; free this item and go to the next one
 * 4) next != NULL, payload != NULL: free item and return its payload
 */
void* fifo_pop( struct fifo* queue )
{
    for(;;)
    {
        struct fifo_item *item = queue->first;
        struct fifo_item *next = InterlockedExchangePointer( &item->next, NULL );
        void *data = item->payload;
        item->payload = NULL;
        if( next )
        {
            queue->first = next;
            g_free( item );
        }
        if( data )
            return data;
        if( !next )
            return NULL;
    }
}
