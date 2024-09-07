#ifndef ASPECTS_H
#define ASPECTS_H

inline void CLEAR(int16_t top, int16_t middle = -1, int16_t bottom = -1) {
  GREEN(top);

  if (middle != -1) {
    RED(middle);
  }

  if (bottom != -1) {
    RED(bottom);
  }
}

inline void APPROACH(int16_t top, int16_t middle = -1, int16_t bottom = -1) {
  RED(top);

  if (middle != -1) {
    AMBER(middle);
  }

  if (bottom != -1) {
    RED(bottom);
  }
}

#endif