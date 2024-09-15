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

// --
SERVO_TURNOUT(103, 116, 400, 290, Medium, "Crossover-Main-Lead")
SERVO_TURNOUT(104, 117, 450, 250, Medium, "Crossover-Lead-Main")
SERVO_TURNOUT(105, 118, 150, 240, Medium, "Crossover-Main-Main2")
SERVO_TURNOUT(106, 133, 475, 300, Medium, "Crossover-Main2-Main")
SERVO_TURNOUT(107, 134, 200, 400, Medium, "Lead-Yard")

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

  DONE
