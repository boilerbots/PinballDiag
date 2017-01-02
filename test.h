#pragma once
#include <QtCore>
#include "hw.h"

class Test
{
public:
  Test(unsigned base);

  void init() { hw.init(); };

  int testLamps(int loops);
  int testPort();
  void run();
  void setNextTest(int test) { nextTest = test; };
  void terminate() { keepRunning = 0; };

signals:
  void myMessage(const QString);

private:
  HW hw;
  QObject *parent;
  std::vector< std::pair< std::string, int> > testList;
  void anykey();
  int nextTest;
  int keepRunning;

};
