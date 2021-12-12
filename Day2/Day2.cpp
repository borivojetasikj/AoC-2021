#include "Day2.hpp"

namespace AoC2021
{
  Day2::Day2():
    _inputFile{ "input.txt", std::ios_base::in },
    _inputDataReady{ false }
  {  
    if (PrepareInputData())
    {
      _inputDataReady = true;
    }
  }
  
  void Day2::SolvePuzzles()
  {
    std::cout << "[Day 2] Puzzle 1 solution: "
      << FollowPlannedCourse() << " | Puzzle 2 solution: "
      << PilotSubmarineWithAiming() << std::endl;
  }
  
  bool Day2::PrepareInputData()
  {
    bool inputParsed = false;
    
    if (_inputFile)
    {
      std::string line = "";
      const char* delim = " ";

      while (_inputFile)
      {
        getline(_inputFile, line, '\n');
  
        if (!line.empty())
        {
          size_t ind = line.find(delim);
          std::string cmd = line.substr(0, ind);

          int val = stoi(line.substr(ind, line.size()));
          _plannedCourse.push_back(make_pair(cmd, val));
        }
      }
      _inputFile.close();
      inputParsed = true;
    }
    return inputParsed;
  }
  
  std::uint32_t Day2::FollowPlannedCourse()
  {
    if (_inputDataReady)
    {
      int hPos = 0;
      int depth = 0;

      std::vector<std::pair<std::string, int>>::iterator itr;

      for (itr = _plannedCourse.begin(); itr != _plannedCourse.end(); ++itr)
      {
        int courseVal = static_cast<int>(itr->second);

        !std::strcmp("forward", itr->first.c_str()) ?
          hPos += courseVal :
          !std::strcmp("up", itr->first.c_str()) ?
          depth -= courseVal : depth += courseVal;
      }
      return hPos * depth;
    }    
    return 0;     
  }
  
  std::uint32_t Day2::PilotSubmarineWithAiming()
  {
    if (_inputDataReady)
    {
      int hPos = 0;
      int depth = 0;
      int aim = 0;

      std::vector<std::pair<std::string, int>>::iterator itr;

      for (itr = _plannedCourse.begin(); itr != _plannedCourse.end(); ++itr)
      {
        int courseVal = static_cast<int>(itr->second);

        !std::strcmp("forward", itr->first.c_str()) ?
          hPos += courseVal,
          depth += aim * courseVal :
          !std::strcmp("up", itr->first.c_str()) ?
          aim -= courseVal : aim += courseVal;
      }
      return  hPos * depth;
    }
    return 0;
  }
}
