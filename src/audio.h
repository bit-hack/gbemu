#pragma once
#include <array>

#include "definitions.h"
#include "address.h"

class Audio {
public:
  void write(const Address &address, u8 data);

  u8 read(const Address& address);

  std::array<u8, 16> pattern;

};
