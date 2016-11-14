#pragma once
#include <sys/io.h>
#include <unistd.h>
#include <stdint.h>

class HW {
 public:
  HW(unsigned base) : sim(true), BASE(base), STATUS(base+1), CONTROL(base+2) { };

  int init();

  inline void portIn() {
    ctl |= DIRECTION;
    if (!sim) {
      outb(ctl, CONTROL);
    }
  };

  inline void portOut() {
    ctl &= ~DIRECTION;
    if (!sim) {
      outb(ctl, CONTROL);
    }
  };

  void control(uint8_t reg);  // write to a control register
  void writeData(uint8_t data); // latch data

 private:
  bool sim;
  uint8_t ctl;

  const unsigned BASE;
  const unsigned STATUS;
  const unsigned CONTROL;

  // CONTROL register
  static const unsigned STROBE = 0x1;  //Inverted
  static const unsigned INIT = 0x4;
  static const unsigned SELECT = 0x8;  //Inverted
  static const unsigned DIRECTION = 0x20;


};
