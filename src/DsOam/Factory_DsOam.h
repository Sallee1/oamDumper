#pragma once
#include <pch.h>
#include <DsOam/Interface_DsOam.h>
#include <DsOam/impl/DsOam_NCER.h>

class Factory_DsOam
{
public:
  enum dsOamFormat {
    NCER
  };

  static std::shared_ptr<Interface_DsOam> getInstance(dsOamFormat format);
};