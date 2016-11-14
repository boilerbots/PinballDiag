#pragma once
#include <QtCore>
#include "hw.h"

class Test : public QThread
{
public:
  Test(unsigned base, QWidget *parent) : hw(base)
  { this->parent = parent; };

  void init() { hw.init(); };

  int testLamps(int loops);
  int testPort();
  void run();

private:
  HW hw;
  QWidget *parent;

  void anykey();

};
