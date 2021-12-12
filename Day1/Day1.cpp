#include "Day1.hpp"

namespace AoC2021
{
  Day1::Day1():
    _inputFile{ "input.txt", std::ios_base::in },
    _inputDataReady{ false }
  {  
    if (PrepareInputData())
    {
      _inputDataReady = true;
    }
  }
  
  void Day1::SolvePuzzles()
  {
    std::cout << "[Day 1] Puzzle 1 solution: "
      << Puzzle1Solver() << " | Puzzle 2 solution: "
      << Puzzle2Solver() << std::endl;
  }
  
  bool Day1::PrepareInputData()
  {
    bool inputParsed = false;
  
    if (_inputFile)
    {
      std::string line = "";

      while (_inputFile)
      {
        getline(_inputFile, line, '\n');
  
        if (!line.empty())
        {
          _inputData.push_back(std::stoi(line));
        }
      }
      _inputFile.close();
      inputParsed = true;
    }
    return inputParsed;
  }
  
  std::uint16_t Day1::Puzzle1Solver()
  {
    if (_inputDataReady)
    {
      std::uint16_t _measurementsIncreases = 0;
    
      for (auto ind = 0; ind < _inputData.size() - 1; ind++)
      {       
        if (_inputData.at(ind) < _inputData.at(ind+1))
        {
          _measurementsIncreases++;
        }
      }
      return _measurementsIncreases;
    }    
    return 0;     
  }
  
  std::uint16_t Day1::Puzzle2Solver()
  {
    if (_inputDataReady)
    {
      std::uint16_t _measurementsIncreases = 0;
  
      for (auto ind = 0; ind < _inputData.size() - WINDOW_SIZE; ind++)
      {     
        if (SumOfElementsInWindow(ind, ind + 2) <
            SumOfElementsInWindow(ind+1, ind + 3))
        {
          _measurementsIncreases++;
        }
      }
      return _measurementsIncreases;
    }
    return 0;
  }
  
  std::uint16_t Day1::SumOfElementsInWindow(std::uint16_t indFrom, std::uint16_t indTo)
  {
    std::uint32_t windowElementsSum = 0;
    for (auto ind = indFrom; ind <= indTo; ind++)
    {
      windowElementsSum += _inputData.at(ind);
    }
    return windowElementsSum;
  }
}
