#include "signalStates.h"
#include "turnoutDefinitions.h"
// REFERENCE
// SERVO_TURNOUT(id, pin, active_angle, inactive_angle, profile [, "description"])

// ----LMain-M1-Lead----

SIGNAL(111, 110, 109) // [S 111] LMain->M1
SIGNAL(115, 114, 113) // [S 115] LMain->Lead
SIGNAL(105, 0, 104) // [S 105] M1->LMain
SIGNAL(107, 106, 0) // [S 115] Lead->LMain

// [T 101 Left-Main-Lead]
SERVO_TURNOUT(CP_101, 101, 255, 210, Medium, "Left-Main-Lead")

// ---------------------

// ----RMain-M1-M2----

SIGNAL(154, 153, 152) // [S 154] RMain->M1
SIGNAL(158, 157, 156) // [S 158] RMain->M2
SIGNAL(161, 0, 160) // [S 161] M1->RMain
SIGNAL(163, 162, 0) // [S 163] M2->RMain

// [T 102 Right-Main-Main2]
SERVO_TURNOUT(CP_102, 148, 200, 370, Medium, "Right-Main-Main2")

// ---------------------

// ----Crossover----
// --M1M1
SIGNAL(M1_M1_M2, 137, 136) // [S 138] M1-M1

// --M1M1M2
SIGNAL(M1_M1, 121, 120) // [S 122] M1-M1
SIGNAL(M1_M2, 124, 0) // [S 125] M1-M2
SIGNAL(M1_YARD, 0, 0) // [S 127] M1-YARD

// --M2M1LEAD
SIGNAL(M2_M1, 141, 140) // [S 142] M2-M1
SIGNAL(M2_LEAD, 143, 0) // [S 144] M2-LEAD

// --LEADM2
SIGNAL(LEAD_M2, 128, 0) // [S 129] LEAD-M2
SIGNAL(LEAD_YARD, 0, 0) // [S 130] LEAD-YARD

SERVO_TURNOUT(CP_103, 116, 400, 290, Medium, "Crossover-Main-Lead")
SERVO_TURNOUT(CP_104, 117, 450, 250, Medium, "Crossover-Lead-Main")
SERVO_TURNOUT(CP_105, 118, 150, 240, Medium, "Crossover-Main-Main2")
SERVO_TURNOUT(CP_106, 133, 475, 300, Medium, "Crossover-Main2-Main")

// ----Yard----
SERVO_TURNOUT(YARD_EXIT, 134, 200, 400, Medium, "Lead-Yard")
SIGNAL(YARD, 146, 0) // [S 147] YARD

AUTOSTART

ONCHANGE_TURNOUT_101()
ONCHANGE_TURNOUT_102()

DONE

ONCLOSE(CP_101)

  ONCHANGE_TURNOUT_101()

  DONE

ONTHROW(CP_101)

  ONCHANGE_TURNOUT_101()

  DONE

ONCLOSE(CP_102)

  ONCHANGE_TURNOUT_102()

  DONE

ONTHROW(CP_102)

  ONCHANGE_TURNOUT_102()
  ONCHANGE_CROSSOVER()
  
  DONE

ONCLOSE(CP_103)

  IFTHROWN(CP_104)
    CLOSE(CP_104)
  ELSE
    ONCHANGE_CROSSOVER()
  ENDIF

  DONE

ONTHROW(CP_103)

  IFCLOSED(CP_104)
    THROW(CP_104)
  ELSE
    ONCHANGE_CROSSOVER()
  ENDIF

  DONE
  
ONCLOSE(CP_104)

  IFTHROWN(CP_103)
    CLOSE(CP_103)
  ELSE
    ONCHANGE_CROSSOVER()
  ENDIF

  DONE

ONTHROW(CP_104)

  IFCLOSED(CP_103)
    THROW(CP_103)
  ELSE
    ONCHANGE_CROSSOVER()
  ENDIF

  DONE
  
ONCLOSE(CP_105)

  IFTHROWN(CP_106)
    CLOSE(CP_106)
  ELSE
    ONCHANGE_CROSSOVER()
  ENDIF

  DONE

ONTHROW(CP_105)

  IFCLOSED(CP_106)
    THROW(CP_106)
  ELSE
    ONCHANGE_CROSSOVER()
  ENDIF

  DONE
  
ONCLOSE(CP_106)

  IFTHROWN(CP_105)
    CLOSE(CP_105)
  ELSE
    ONCHANGE_CROSSOVER()
  ENDIF

  DONE

ONTHROW(CP_106)

  IFCLOSED(CP_105)
    THROW(CP_105)
  ELSE
    ONCHANGE_CROSSOVER()
  ENDIF

  DONE

ONCLOSE(YARD_EXIT)

  ONCHANGE_TURNOUT_YARD_EXIT()

  DONE

ONTHROW(YARD_EXIT)

  ONCHANGE_TURNOUT_YARD_EXIT()

  DONE
