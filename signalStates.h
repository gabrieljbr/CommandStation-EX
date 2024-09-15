// ONE HEAD
#define CLEAR_ONE_HEAD(head) GREEN(head)
#define APPROACH_ONE_HEAD(head) AMBER(head)
#define STOP_ONE_HEAD(head) RED(head)

// TWO HEADS
#define CLEAR_TWO_HEADS(top, bottom) GREEN(top) RED(bottom)
#define APPROACH_TWO_HEADS(top, bottom) RED(top) AMBER(bottom)