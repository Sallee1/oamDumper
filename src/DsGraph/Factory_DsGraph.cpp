#include "pch.h"
#include "Factory_DsGraph.h"

std::shared_ptr<Interface_DsGraph> Factory_DsGraph::getInstance(dsOamFormat format)
{
  switch (format)
  {
  case dsOamFormat::NCGR:return std::make_shared<DsGraph_NCGR>();
  case dsOamFormat::NCBR:return std::make_shared<DsGraph_NCBR>();
  }
}
