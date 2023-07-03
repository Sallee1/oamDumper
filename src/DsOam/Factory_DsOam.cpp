#include "pch.h"
#include <DsOam/Factory_DsOam.h>

std::shared_ptr<Interface_DsOam> Factory_DsOam::getInstance(dsOamFormat format)
{
  switch (format) {
  case NCER: return std::make_shared<DsOam_NCER>();
  }
}
