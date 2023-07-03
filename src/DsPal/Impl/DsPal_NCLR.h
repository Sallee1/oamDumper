#pragma once
#include <pch.h>
#include "DsPal/Interface_DsPal.h"

class DsPal_NCLR :public Interface_DsPal {
  void getDataFromFile(std::ifstream& palFile) override;
};