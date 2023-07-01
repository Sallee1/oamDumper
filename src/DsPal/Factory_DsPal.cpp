#include "Factory_DsPal.h"

std::shared_ptr<Interface_DsPal> Factory_DsPal::getInstance(dsPalFormat format)
{
  switch (format)
  {
  case dsPalFormat::NCLR:return std::make_shared<DsPal_NCLR>();
  }
}
