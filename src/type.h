#pragma once
#include <pch.h>

namespace DsOamType {
  enum class OamSize {
    s_tiny, s_small, s_medium, s_big,
    h_tiny, h_small, h_medium, h_big,
    v_tiny, v_small, v_medium, v_big
  };

  //bool operator<(const OamSize& lhs, const OamSize& rhs);

  const std::map<OamSize, cv::Size2d> oamSizeMapper = {
    std::make_pair(OamSize::s_tiny, cv::Size2d(8, 8)),
    std::make_pair(OamSize::s_small, cv::Size2d(16, 16)),
    std::make_pair(OamSize::s_medium, cv::Size2d(32, 32)),
    std::make_pair(OamSize::s_big, cv::Size2d(64, 64)),
    std::make_pair(OamSize::h_tiny, cv::Size2d(16, 8)),
    std::make_pair(OamSize::h_small, cv::Size2d(32, 8)),
    std::make_pair(OamSize::h_medium, cv::Size2d(32, 16)),
    std::make_pair(OamSize::h_big, cv::Size2d(64, 32)),
    std::make_pair(OamSize::v_tiny, cv::Size2d(8, 16)),
    std::make_pair(OamSize::v_small, cv::Size2d(8, 32)),
    std::make_pair(OamSize::v_medium, cv::Size2d(16, 32)),
    std::make_pair(OamSize::v_big, cv::Size2d(32, 64)),
  };

  struct OamData {
    ushort charaId;
    bool isBpp8 = false;
    ushort palId = 0;
    cv::Rect oamRect;
    bool hFlip = false;
    bool vFlip = false;
  };

  typedef std::vector< DsOamType::OamData> OamFrame;
}

