#pragma once
#include <pch.h>
#include <DsGraph/Interface_DsGraph.h>
#include <DsGraph/impl/DsGraph_NCGR.h>
#include <DsGraph/impl/DsGraph_NCBR.h>

class Factory_DsGraph
{
public:
  enum dsOamFormat {
    NCGR, NCBR
  };

  static std::shared_ptr<Interface_DsGraph> getInstance(dsOamFormat format);
};