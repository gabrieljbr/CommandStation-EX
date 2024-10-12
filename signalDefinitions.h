#include "signalStates.h"

// CP 101
#define CP_101 101
#define L_MAIN_M1 111
#define L_MAIN_LEAD 115
#define M1_L_MAIN 105
#define LEAD_L_MAIN 107

// CP 102
#define CP_102 102
#define R_MAIN_M1 154
#define R_MAIN_M2 158
#define M1_R_MAIN 161
#define M2_R_MAIN 163

// CROSSOVER
// 103/104 - 105/106
#define CP_103 103
#define CP_104 104
#define CP_105 105
#define CP_106 106
// M1M1
#define M1_M1_M2 138
// M1M1M2
#define M1_M1 122
#define M1_M2 125
#define M1_YARD 127
// M2M1LEAD
#define M2_M1 142
#define M2_LEAD 144
// LEADM2
#define LEAD_M2 129
#define LEAD_YARD 130

// YARD
#define YARD_EXIT 107
#define YARD 147

#define SET_LMAINM1_LMAINLEAD() \
  IFCLOSED(CP_101) \
    CLEAR_TWO_HEADS(L_MAIN_M1, L_MAIN_LEAD) \
  ELSE \
    DIVERGING_APPROACH_TWO_HEADS(L_MAIN_M1, L_MAIN_LEAD) \
  ENDIF

#define SET_M1LMAIN() \
  IFCLOSED(CP_101) \
    CLEAR_ONE_HEAD(M1_L_MAIN) \
  ELSE \
    STOP_ONE_HEAD(M1_L_MAIN) \
  ENDIF

#define SET_LEADLMAIN() \
  IFCLOSED(CP_101) \
    STOP_ONE_HEAD(LEAD_L_MAIN) \
  ELSE \
    APPROACH_ONE_HEAD(LEAD_L_MAIN) \
  ENDIF

#define SET_RMAINM1_RMAINM2() \
  IFCLOSED(CP_102) \
    IFGREEN(M1_M1_M2) \
      CLEAR_TWO_HEADS(R_MAIN_M1, R_MAIN_M2) \
    ELSE \
      IFAMBER(M1_M1_M2) \
        APPROACH_MEDIUM_TWO_HEADS(R_MAIN_M1, R_MAIN_M2) \
      ELSE \
        APPROACH_MEDIUM_TWO_HEADS(R_MAIN_M1, R_MAIN_M2) \
      ENDIF \
    ENDIF \
  ELSE \
    DIVERGING_APPROACH_TWO_HEADS(R_MAIN_M1, R_MAIN_M2) \
  ENDIF

#define SET_M1RMAIN() \
  IFCLOSED(CP_102) \
    CLEAR_ONE_HEAD(M1_R_MAIN) \
  ELSE \
    STOP_ONE_HEAD(M1_R_MAIN) \
  ENDIF

#define SET_M2RMAIN() \
  IFCLOSED(CP_102) \
    STOP_ONE_HEAD(M2_R_MAIN) \
  ELSE \
    APPROACH_ONE_HEAD(M2_R_MAIN) \
  ENDIF

#define SET_M1M1() \
  IFCLOSED(CP_105) \
    IFCLOSED(CP_103) \
      IFGREEN(M1_L_MAIN) \
        CLEAR_ONE_HEAD(M1_M1_M2) \
      ENDIF \
      IFRED(M1_L_MAIN) \
        APPROACH_ONE_HEAD(M1_M1_M2) \
      ENDIF \
    ELSE \
      STOP_ONE_HEAD(M1_M1_M2) \
    ENDIF \
  ELSE \
    STOP_ONE_HEAD(M1_M1_M2) \
  ENDIF

#define SET_M2M1LEAD() \
  IFCLOSED(CP_106) \
    IFCLOSED(CP_107) \
      IFCLOSED(CP_104) \
        IFAMBER(LEAD_L_MAIN) \
          APPROACH_MEDIUM_TWO_HEADS(xxx, xxx) \
        ENDIF \
        IFRED(LEAD_L_MAIN) \
          APPROACH_TWO_HEADS(xxx, xxx) \
        ENDIF \
      ELSE \
        DIVERGING_APPROACH_MEDIUM_TWO_HEADS(xxx, xxx) \
      ENDIF \
    ELSE \
      STOP_TWO_HEADS(xxx, xxx) \
    ENDIF \
  ELSE \
    IFCLOSED(CP_104) \
      DIVERGING_APPROACH_MEDIUM_TWO_HEADS(xxx, xxx) \
    ELSE \
      STOP_TWO_HEADS(xxx, xxx) \
    ENDIF \
  ENDIF

#define SET_M1M1M2() \
  IFCLOSED(CP_103) \
    IFCLOSED(CP_105) \
      CLEAR_THREE_HEADS(xxx, xxx, xxx) \
    ELSE \
      DIVERGING_APPROACH_THREE_HEADS(xxx, xxx, xxx) \
    ENDIF \
  ELSE \
    IFCLOSED(CP_107) \
      IFCLOSED(CP_105) \
        DIVERGING_APPROACH_THREE_HEADS(xxx, xxx, xxx) \
      ELSE \
        STOP_THREE_HEADS(xxx, xxx, xxx) \
      ENDIF \
    ELSE \
      DIVERGING_RESTRICTED_DIVERGING_THREE_HEADS(xxx, xxx, xxx) \
    ENDIF \
  ENDIF

#define SET_LEADM2() \
  IFCLOSED(CP_104) \
    IFCLOSED(CP_107) \
      IFCLOSED(CP_106) \
        CLEAR_TWO_HEADS(xxx, xxx) \
      ELSE \
        STOP_TWO_HEADS(xxx, xxx) \
      ENDIF \
    ELSE \
      DIVERGING_RESTRICTED_TWO_HEADS(xxx, xxx) \
    ENDIF \
  ELSE \
    STOP_TWO_HEADS(xxx, xxx) \
  ENDIF

#define SET_YARD() \
  IFCLOSED(CP_107) \
    STOP_ONE_HEAD(xxx) \
  ELSE \
    APPROACH_ONE_HEAD(xxx) \
  ENDIF
