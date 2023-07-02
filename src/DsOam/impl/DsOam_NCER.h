#pragma once
#include "DsOam/Interface_DsOam.h"

class DsOam_NCER :public Interface_DsOam {
public:
  void getDataFromFile(std::ifstream& oamFile) override;
private:
  DsOamType::OamData getOamDataFromBuf(std::shared_ptr<uchar[]> buf);
};