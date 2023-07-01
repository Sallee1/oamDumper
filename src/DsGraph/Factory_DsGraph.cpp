#include "Factory_DsGraph.h"

std::shared_ptr<Interface_DsGraph> Factory_DsGraph::getInstance(dsGraphFormat format)
{
  switch (format)
  {
  case dsGraphFormat::NCGR:return std::make_shared<DsGraph_NCGR>();
  case dsGraphFormat::NCBR:return std::make_shared<DsGraph_NCBR>();
  }
}
