//
//  hbxList.h
//  hbxList
//
//  Created by bobobobobo on 2017/12/11.
//  Copyright © 2017年 bobobobobo. All rights reserved.
//

#ifndef _HBX_LIST_H_
#define _HBX_LIST_H_

struct list_head {
	struct list_head *next;
};

//#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({          \
    const typeof( ((type *)0)->member ) *__mptr = (ptr); \
    (type *)( (char *)__mptr - offsetof(type,member) );})

#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)


#define list_for_each_entry_safe(pos, head, member)            \
for (pos = list_entry((head)->next, typeof(*pos), member);   \
                  head->next != NULL; \
                  pos = list_entry((head)->next, typeof(*pos), member))

//
void              list_del(struct list_head *item, struct list_head *head);
void              list_add_tail(struct list_head *item, struct list_head *head);
void              list_add(struct list_head *item, struct list_head *prev);

struct list_head* list_pop(struct list_head *list);
void              list_push(struct list_head *item, struct list_head *list);

void              list_init(struct list_head *item);

#endif /* _HBX_LIST_H_ */
