#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace AoC2021
{
  class Day1
  {
    public:
      Day1();
      ~Day1() = default;
  
      void SolvePuzzles();
    private:
      static constexpr std::uint8_t WINDOW_SIZE = 3;
      
      bool PrepareInputData();
      std::uint16_t Puzzle1Solver();
      std::uint16_t Puzzle2Solver();
      std::uint16_t SumOfElementsInWindow(std::uint16_t indFrom, std::uint16_t indTo);
  
      std::ifstream _inputFile;
      bool _inputDataReady;
      std::vector<int> _inputData;
  };
}
