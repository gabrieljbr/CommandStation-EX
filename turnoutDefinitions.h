#include "signalStates.h"

#define R_MAIN_M1 111
#define R_MAIN_LEAD 115
#define M1_R_MAIN 105
#define LEAD_R_MAIN 107

#define ONCHANGE_TURNOUT_101() \
  IFCLOSED(101) \
    CLEAR_TWO_HEADS(R_MAIN_M1, R_MAIN_LEAD) \
    CLEAR_ONE_HEAD(M1_R_MAIN) \
    STOP_ONE_HEAD(LEAD_R_MAIN) \
  ELSE \
    APPROACH_TWO_HEADS(R_MAIN_M1, R_MAIN_LEAD) \
    STOP_ONE_HEAD(M1_R_MAIN) \
    APPROACH_ONE_HEAD(LEAD_R_MAIN) \
  ENDIF

