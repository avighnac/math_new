#include <iostream>
#include <map>
#include <chrono>

#define Black "\u001b[30m"
#define Red "\u001b[31m"
#define Green "\u001b[32m"
#define Yellow "\u001b[33m"
#define Blue "\u001b[34m"
#define Magenta "\u001b[35m"
#define Cyan "\u001b[36m"
#define White "\u001b[37m"
#define Reset "\u001b[0m"

std::string color(std::string text, std::string color) {
    #if defined(_WIN32)
        return text;
    #endif
    
    if (color == "Black")
        return Black + text + Reset;
    else if (color == "Red")
        return Red + text + Reset;
    else if (color == "Green")
        return Green + text + Reset;
    else if (color == "Yellow")
        return Yellow + text + Reset;
    else if (color == "Blue")
        return Blue + text + Reset;
    else if (color == "Magenta")
        return Magenta + text + Reset;
    else if (color == "Cyan")
        return Cyan + text + Reset;
    else if (color == "White")
        return White + text + Reset;

    return "no not a color";
}

#include "../code/source/algorithms/Addition Algorithm/add.hpp"
#include "../code/source/algorithms/integer_square_root.hpp"

void choiceHandler(std::string choice) {
    if (choice == "add") {
        std::cout << "\033[A\33[2K\rTesting add.hpp.\n";
        std::cout << color("basic_test_set (check if function works)\n", "Cyan");

        std::map<std::pair<std::string, std::string>, std::string> testSet1;
        #include "tests/add/test_set_1"

        std::string tab = "  ";
        int count = 0;
        bool functionDoesNotWork = false;
        bool failedHugeNumbers = false;
        auto start = std::chrono::high_resolution_clock::now();
        for (auto &i : testSet1) {
            if (add(i.first.first, i.first.second) == i.second) {
                std::cout << "\33[2K\r" << tab << color("Test " + std::to_string(count + 1) + " Passed. [" + std::to_string(count + 1) + "/6]", "Green");
            } else {
                std::cout << "\33[2K\r" << tab << color("Test " + std::to_string(count + 1) + " Failed. [" + std::to_string(count + 1) + "/6]", "Red");
                functionDoesNotWork = true;
                break;
            }

            count++;
        }

        count = 0;
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "\n  Time taken: " << color(std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()), "Magenta") << color("ms.", "Magenta");
        if (!functionDoesNotWork) {
            std::cout << '\n';
            std::cout << color("bigger_numbers (50 digits per number)", "Cyan");
            std::cout << '\n';

            std::map<std::pair<std::string, std::string>, std::string> testSet2;
            #include "tests/add/test_set_2"
            
            bool failedTestSet2 = false;
            start = std::chrono::high_resolution_clock::now();
            for (auto &i : testSet2) {
              std::string answer = add(i.first.first, i.first.second);
              if (answer == i.second) {
                std::cout << "\33[2K\r" << tab
                          << color("Test " + std::to_string(count + 1) +
                                       " Passed. [" + std::to_string(count + 1) + "/50]",
                                   "Green");
              } else {
                std::cout << "\33[2K\r" << tab
                          << color("Test " + std::to_string(count + 1) +
                                       " Failed. [" + std::to_string(count + 1) + "/50]",
                                   "Red");
                failedTestSet2 = true;
                break;
              }
              count++;
            }

            count = 0;
            end = std::chrono::high_resolution_clock::now();
            std::cout << "\n  Time taken: " << color(std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()), "Magenta") << color("ms.", "Magenta");

            if (!failedTestSet2) {
              std::cout << '\n';
              std::cout << color(
                  "very_huge_numbers (1000 digits per number)", "Cyan");
              std::cout << '\n';

              std::map<std::pair<std::string, std::string>, std::string>
                  testSet3;
              #include "tests/add/test_set_3"

              start = std::chrono::high_resolution_clock::now();
              for (auto &i : testSet3) {
                std::string answer = add(i.first.first, i.first.second);
                if (answer == i.second) {
                  std::cout
                      << "\33[2K\r" << tab
                      << color("Test " + std::to_string(count + 1) + " Passed. [" + std::to_string(count + 1) + "/5]",
                               "Green");
                } else {
                  std::cout << "\33[2K\r" << tab
                            << color("Test " + std::to_string(count + 1) +
                                         " Failed. [" + std::to_string(count + 1) + "/5]",
                                     "Red");
                  failedHugeNumbers = true;
                  break;
                }
                count++;
              }

              count = 0;
              end = std::chrono::high_resolution_clock::now();
              std::cout << "\n  Time taken: " << color(std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()), "Magenta") << color("ms.", "Magenta");
            }
        }

        if (!failedHugeNumbers) {
          // passed all
          std::cout << '\n';
        }
    }
    if (choice == "sqrt") {
      std::map<std::string, std::string> test_set_1;
      std::cout << "Testing integer_square_root.h." << '\n';
      std::cout << color("integer_square_root", "Yellow") << "(n = (\"" << color("0", "Magenta") << "\" → \"" << color("199", "Magenta") << "\"), " << color("25", "Magenta") << ")\n";
      #include "tests/sqrt/test_set_1"
      auto start = std::chrono::high_resolution_clock::now();
      for (auto i = 0; i < 200; i++) {
          if (integer_square_root(std::to_string(i), 25) == test_set_1.find(std::to_string(i))->second)
              std::cout << "\33[2K\r" << color("  Test " + std::to_string(i + 1) + " passed. [" + std::to_string(i + 1) + "/" + "200]", "Green") << std::flush;
          else {
              std::cout << "\33[2K\r" << color("  Test " + std::to_string(i + 1) + " failed. [" + std::to_string(i + 1) + "/" + "200]", "Red");
              std::cout << " a.k.a " << color("integer_square_root(\"" + std::to_string(i) + "\", " + "25)", "Red") << "\n"; 
              std::cout << "    →  Expected: " << color(test_set_1.find(std::to_string(i))->second, "Green");
              std::cout << "\n    →  Actual: " << color(integer_square_root(std::to_string(i), 25), "Red") << '\n';
              break;
          }
      }
      auto end = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
      std::cout << "\n  Time taken: " << duration.count() << "ms.\n";
    }
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    #if defined(_WIN32)
        std::cout << "Since you're on windows, colored text won't be displayed. \n\n";
    #endif

    std::cout << color("--------", "Blue") << color(" Math++ ", "Yellow") << 
                 color("Official ", "Magenta") << color("Testing Software ", "Cyan") << 
                 color("--------", "Blue") << "\n\n";
    std::cout << "Would you like to run a " << color("full test ", "Green") << "or only test a " <<
                  color("particular function", "Yellow") << "?\n";
    std::cout << "If you only want to test a " << color("particular function", "Yellow") << ", type in the " << color("function's name", "Cyan") << ".\n";
    std::cout << "If you want to run a " << color("full", "Green") <<" test, type " << color("\"full\"", "Green") << ".\n\n";

    std::string choice;
    std::cin >> choice;

    if (choice == "full") {
      choiceHandler("add");
      std::cout << "\n\n";
      choiceHandler("sqrt");
    }

    choiceHandler(choice);
  }
  else if (argc >= 2) {
    choiceHandler(std::string(argv[1]));
  }
}