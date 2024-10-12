// ONE HEAD
#define CLEAR_ONE_HEAD(head) GREEN(head)
#define APPROACH_ONE_HEAD(head) AMBER(head)
#define STOP_ONE_HEAD(head) RED(head)

// TWO HEADS
#define CLEAR_TWO_HEADS(top, bottom) GREEN(top) RED(bottom)
#define APPROACH_TWO_HEADS(top, bottom) AMBER(top) RED(bottom)
#define APPROACH_MEDIUM_TWO_HEADS(top, bottom) AMBER(top) RED(bottom) // flashing
#define DIVERGING_APPROACH_TWO_HEADS(top, bottom) RED(top) AMBER(bottom)
#define DIVERGING_APPROACH_MEDIUM_TWO_HEADS(top, bottom) RED(top) AMBER(bottom) // flashing
#define STOP_TWO_HEADS(top, bottom) RED(top) RED(bottom)
#define DIVERGING_RESTRICTED_TWO_HEADS(top, bottom) RED(top) RED(bottom) // flashing

// THREE HEADS
#define CLEAR_THREE_HEADS(top, middle, bottom) GREEN(top) RED(middle) RED(bottom)
#define APPROACH_THREE_HEADS(top, middle, bottom) AMBER(top) RED(middle) RED(bottom)
#define STOP_THREE_HEADS(top, middle, bottom) RED(top) RED(middle) RED(bottom)
#define DIVERGING_APPROACH_THREE_HEADS(top, middle, bottom) RED(top) AMBER(middle) RED(bottom)
#define DIVERGING_RESTRICTED_DIVERGING_THREE_HEADS(top, middle, bottom) RED(top) RED(middle) RED(bottom) // flashing
