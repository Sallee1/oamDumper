#pragma once
#include <DsGraph/Interface_DsGraph.h>

//任天堂标准格式的实现
class DsGraph_Nitro :public Interface_DsGraph
{
public:
  void getDataFromFile(std::ifstream& graphFile) override;
protected:
  cv::Mat getSubData(uint32_t charaID, cv::Size2i charaSize, bool isBpp8);
};