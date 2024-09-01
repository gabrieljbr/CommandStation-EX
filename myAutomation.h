// REFERENCE
// SERVO_TURNOUT(id, pin, active_angle, inactive_angle, profile [, "description"])


// LMain-M1-Lead
// [S 111] Main->M1
// [S 115] Main->Lead
// [T 101 Left-Main-Lead]
SIGNAL(111, 110, 109)
SIGNAL(115, 114, 113)

SERVO_TURNOUT(101, 101, 255, 210, Medium, "Left-Main-Lead")

// RMain-M1-M2
// [S 154] Main->M1
// [S 158] Main->M2
// [T 102 Right-Main-Main2]
SIGNAL(154, 153, 152)
SIGNAL(158, 157, 156)

SERVO_TURNOUT(102, 148, 200, 370, Medium, "Right-Main-Main2")

// --
SERVO_TURNOUT(103, 116, 400, 290, Medium, "Crossover-Main-Lead")
SERVO_TURNOUT(104, 117, 450, 250, Medium, "Crossover-Lead-Main")
SERVO_TURNOUT(105, 118, 150, 240, Medium, "Crossover-Main-Main2")
SERVO_TURNOUT(106, 133, 475, 300, Medium, "Crossover-Main2-Main")
SERVO_TURNOUT(107, 134, 200, 400, Medium, "Lead-Yard")

AUTOSTART
// TODO: predefine start values/positions
AMBER(111)
AMBER(115)

AMBER(154)
AMBER(158)
PRINT("Autostart")
DONE

ONTHROW(101)
  // left main -> lead
  RED(111)
  AMBER(115)
  PRINT("Throw")
  DONE

ONCLOSE(101)
  // left main -> main
  GREEN(111)
  RED(115)
  
  // main -> left main
  GREEN(0)
  PRINT("Close")

  DONE
