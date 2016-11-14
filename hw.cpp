
#include <iostream>

#include "hw.h"

int HW::init() {

  if (!sim) {
    int result = ioperm(BASE,3,1);
    if (result) {
      std::cout << "Failed to open parallel port\n";
      return(-1);
    }
    result = ioperm(BASE+0x402,1,1);
    if (result) {
      std::cout << "Failed to change the mode\n";
      return(-1);
    }
    std::cout << "Opened Parallel port: " << std::hex << BASE << std::dec << std::endl;

    uint8_t old = inb(BASE+0x402);
    old &= 0x1f;
    outb(old | 0x20,BASE+0x402); // set mode

    //unsigned char data;
    //data = inb(BASE);
    outb(0,BASE); //initialize data

    // change direction to output
    uint8_t oldctl = inb(CONTROL);
    ctl = (oldctl | DIRECTION); //Input mode
    ctl &= ~SELECT;
    ctl &= ~INIT;
    std::cout << "oldctl=" << std::hex << (unsigned)oldctl << std::dec << std::endl;
    outb(ctl, CONTROL);
  }

  return 0;
}

void HW::control(uint8_t reg) {

  portOut();
  
  if (!sim) {
    outb(reg,BASE);
    outb((ctl & ~INIT), CONTROL);
    outb((ctl | INIT), CONTROL);
  }
}

void HW::writeData(uint8_t data) {

  if (!sim) {
    outb(data,BASE);
    outb((ctl | STROBE), CONTROL); // stobe low   - hardware inverted
    outb((ctl & ~STROBE), CONTROL);
  }
}
