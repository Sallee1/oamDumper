﻿#include <opencv2/opencv.hpp>
#include <DsGraph/Factory_DsGraph.h>
#include <DsPal/Factory_DsPal.h>
#include <utils.h>
#include <pch.h>

int main(int argc, char* argv[])
{
  std::string ncgrPath = R"(E:\Users\Sallee\Documents\code\C++\oamDumper\testNCGR\rpg_down_info.NCGR)";
  std::string nclrPath = R"(E:\Users\Sallee\Documents\code\C++\oamDumper\testNCGR\rpg_down_info.NCLR)";
  std::string ncerPath = R"(E:\Users\Sallee\Documents\code\C++\oamDumper\testNCGR\rpg_down_info.NCER)";

  std::ifstream ncgrFile(ncgrPath, std::fstream::in | std::fstream::binary);
  std::ifstream nclrFile(nclrPath, std::fstream::in | std::fstream::binary);
  std::ifstream ncerFile(ncerPath, std::fstream::in | std::fstream::binary);

  auto dsGraph = Factory_DsGraph::getInstance(Factory_DsGraph::NCGR);
  dsGraph->getDataFromFile(ncgrFile);
  cv::Mat graph = dsGraph->getOam(204, OamSize::h_medium);

  auto dsPal = Factory_DsPal::getInstance(Factory_DsPal::NCLR);
  dsPal->getDataFromFile(nclrFile);
  cv::Mat pal = dsPal->getPal();

  auto res = Utils::setPalette(graph, pal);
}