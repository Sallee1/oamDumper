#pragma once
#include "pch.h"
#include "type.h"

class Interface_DsOam {
  typedef std::vector< DsOamType::OamData> OamFrame;
protected:
  std::vector<OamFrame> oamFrameList;
public:
  virtual void getDataFromFile(std::ifstream& oamFile) = 0;
  OamFrame operator[](const int& idx);

  int frameCount();

public:
  std::vector<OamFrame>::iterator begin();

  std::vector<OamFrame>::iterator end();
};