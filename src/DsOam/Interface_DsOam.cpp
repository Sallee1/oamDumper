#include "Interface_DsOam.h"

Interface_DsOam::OamFrame Interface_DsOam::operator[](const int& idx) {
  return oamFrameList[idx];
}

int Interface_DsOam::frameCount()
{
  return oamFrameList.size();
}

std::vector<Interface_DsOam::OamFrame>::iterator Interface_DsOam::begin()
{
  return oamFrameList.begin();
}

std::vector<Interface_DsOam::OamFrame>::iterator Interface_DsOam::end()
{
  return oamFrameList.end();
}
