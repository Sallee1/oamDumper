#pragma once
#include <pch.h>
#include <DsPal/Interface_DsPal.h>
#include <DsPal/Impl/DsPal_NCLR.h>

class Factory_DsPal
{
public:
  enum dsPalFormat {
    NCLR
  };

  static std::shared_ptr<Interface_DsPal> getInstance(dsPalFormat format);
};