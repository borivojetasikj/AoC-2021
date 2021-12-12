#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace AoC2021
{
  /* --- Day 2: Dive! --- */
  class Day2
  {
    public:
      Day2();
      ~Day2() = default;
  
      void SolvePuzzles();
    private:
      
      bool PrepareInputData();
      std::uint32_t FollowPlannedCourse();
      std::uint32_t PilotSubmarineWithAiming();
  
      std::ifstream _inputFile;
      bool _inputDataReady;
      std::vector<std::pair<std::string, int>> _plannedCourse;
  };
}
