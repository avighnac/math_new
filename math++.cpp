#include <chrono>
#include <iostream>

#include "code/source/algorithms/Addition Algorithm/add.hpp"
#include "code/source/algorithms/Division Algorithm/divide.hpp"
#include "code/source/algorithms/Multiplication Algorithm/multiply.hpp"
#include "code/source/algorithms/Simple Interest/simple_interest.hpp"
#include "code/source/algorithms/Subtraction Algorithm/subtract.hpp"
#include "code/source/algorithms/integer_square_root.hpp"
#include "code/source/algorithms/simplify_fractions.hpp"

#include "code/source/algorithms/Factorization/ax2bxc.hpp"
#include "code/source/algorithms/Factorization/algebric_number_class.hpp"

// External Image Library
// #include "libraries/CImg.h"

#define RED "\033[31m"   /* Red */
#define GREEN "\033[32m" /* Green */
#define RESET "\033[0m"
#define BOLD_WHITE "\033[1;37m"

#define TODO                                                                   \
  (std::cout << "You've discovered a feature that's not yet coded in! This "   \
                "will not be the case in some time. \n")

bool is_windows() {
#if defined(_WIN32)
  return true;
#endif
  return false;
}

namespace basic_math_operations {
std::string add(const std::string &num1, const std::string &num2) {
  return ::add(num1, num2);
}
std::string subtract(const std::string &num1, const std::string &num2) {
  return ::subtract(num1, num2);
}
std::string multiply(const std::string &num1, const std::string &num2) {
  return ::multiply(num1, num2);
}
std::string divide(const std::string &num1, const std::string &num2) {
  return ::divide(num1,
                  num2); /*Still in beta.
                            Only supports whole quotient division for now.*/
}
} // namespace basic_math_operations

std::string to_lower(std::string str) {
  for (auto &i : str)
    i = tolower(i);
  return str;
}

int main(int argCount, char *argument[]) {
  if (argCount == 1) {
    std::cout
        << "Syntax: math++ [function]. For more information run math++ help.\n";
  }

  if (argCount >= 2) {
    std::string function = argument[1];
    function = to_lower(function);

    if (function == "add") {
      if (argCount == 2) {
        std::cout << "\nTip: Use math++ add [num1] "
                     "[num2] ... [numN] to skip this interface.\n\n";
        std::cout << "Amount of numbers to be added: ";

        size_t arr_size;
        std::cin >> arr_size;
        while (arr_size < 2) {
          std::cout << RED << "Error: Number too small. " << RESET
                    << "\nAmount of numbers to be added: ";
          std::cin >> arr_size;
        }

        std::vector<std::string> to_add(arr_size);
        std::cout << GREEN << "Numbers: (Separated with a space): " << RESET;
        for (int i = 0; i < arr_size; i++) {
          std::cin >> to_add[i];
        }
        std::string addition = "0";
        for (int i = 0; i < arr_size / 2; i++) {
          addition = basic_math_operations::add(
              addition, basic_math_operations::add(to_add[i], to_add[i + 1]));
        }
        if (arr_size % 2 != 0)
          addition = basic_math_operations::add(addition, to_add[arr_size - 1]);

        std::cout << GREEN << addition << "\n" << RESET;
      }

      else if (argCount == 3) {
        std::string thirdArg = argument[2];
        if (thirdArg == "help")
          TODO;
        else
          std::cout
              << "[math++.function.add] Error: Insufficient Arguments! \n";
      }

      else if (argCount >= 4) {
        std::string answer = "0";

        for (auto i = 2; i < argCount; i++)
          answer = basic_math_operations::add(answer, argument[i]);

        std::cout << answer << "\n";
      }
    }

    if (function == "help") {
      std::vector<std::string> functions = {"Add",
                                            "Subtract",
                                            "Square Root",
                                            "Fraction Simplifier",
                                            "Simple Interest",
                                            "Factorial",
                                            "Factorize",
                                            "Evaluate",
                                            };
      std::vector<std::string> function_definitions = {
          "Uses an addition algorithm "
          "implemented to add numbers.. infinitely huge.",
          ""
          "Same as addition, but for subtraction!",
          "The "
          "square root of a number is a number which when multiplied, gives "
          "you the original number back.",
          "Simplifies a fraction to it's lowest terms.",
          "Solves simple interest sums automatically (with working). Google "
          "\"Simple Interest\" for more information.",
          "The number of ways to arrange n distinct objects into an ordered "
          "sequence of n places. For example, the number of ways to distribute "
          "6 books among 3 people is 6! = 6 x 5 x 4 x 3 x 2 x 1 = 720.",
          "In mathematics, factorization consists of writing a number or "
          "another mathematical object as a product of several factors, "
          "usually smaller or simpler objects of the same kind. Opposite of "
          "simplification (complication).",
          "Evaluate a mathematical expression."};
      std::cout << "\nMath++ is a free and open-source tool created by "
                   "avighnac to solve math! For a full list of credits run "
                   "math++ credits.\nFUNCTIONS:\n";

      for (auto i = 0; i < functions.size(); i++) {
        if (is_windows()) {
          std::cout << "     -";
        } else
          std::cout << "     •";
        std::cout << functions[i] << "- " << function_definitions[i]
                  << "\n";
      }

      std::cout
          << "\nNote: For help "
             "with any individual function run math++ [function] help.\n\n";
    }

    if (function == "credits") {
      TODO;
    }

    if (function == "simple_interest" || function == "si") {
      if (argCount == 3) {
        std::string argument3 = argument[2];
        if (argument3 == "help")
          std::cout << "The function has a built-in help function. Why don't "
                       "you try using that? :) \n";
      } else {
        simpleInterest simpleInterest;
        simpleInterest.solve();
      }
    }

    if (function == "factorial") {
      if (argCount >= 3) {
        std::string argument3 = argument[2];
        if (argument3 == "help")
          std::cout << "Syntax: math++ factorial [number] \n";
        else {
          std::string factorial = "1";
          long long number = std::stoll(argument3);
          for (long long i = 1; i < number + 1; i++)
            factorial =
                basic_math_operations::multiply(factorial, std::to_string(i));
          std::cout << factorial << "\n";
        }
      }
    }

    if (function == "fraction_simplifier" || function == "sf") {
      if (argCount == 2) {
        std::cout << "Fraction Simplifier (to help with your homework!) \n";
        std::cout << "Tip: Use math++ fraction_simplifier [numerator] "
                     "[denominator] to skip this interface. \n";
        long long numerator;
        long long denominator;
        std::cout << GREEN << "Numerator: " << RESET;
        std::cin >> numerator;
        std::cout << GREEN << "Denominator: " << RESET;
        std::cin >> denominator;

        std::pair<long long, long long> answer =
            fraction_simplifier({numerator, denominator});

        if (numerator == answer.first)
          std::cout << "Those two numbers are co-prime. \n";
        else
          std::cout << RED << numerator << "/" << denominator << RESET << " = "
                    << GREEN << answer.first << "/" << answer.second << "\n"
                    << RESET;
      }
      if (argCount == 3) {
        std::string argument3 = argument[2];
        if (argument3 == "help")
          std::cout << "Syntax: math++ fraction_simplifier [numerator] "
                       "[denominator] \n";
        else
          std::cout << "[math++.function.fraction_simplifier] Error: "
                       "Insufficient Arguments. \n";
      } else if (argCount >= 4) {
        long long numerator = std::stoll(argument[2]);
        long long denominator = std::stoll(argument[3]);

        std::pair<long long, long long> answer =
            fraction_simplifier({numerator, denominator});

        std::cout << answer.first << "/" << answer.second << "\n";
      }
    }

    if (function == "sqrt") {
      if (argCount >= 3) {
        std::string argument3 = argument[2];
        if (argument3 != "help") {
          int accuracy = 8;
          bool show_time = false;
          if (argCount >= 4) {
            accuracy = std::stoi(argument[3]);
          }
          if (argCount >= 5) {
            std::string arg5 = argument[4];
            if (arg5 == "-t") {
              show_time = true;
            }
          }

          if (decimal_point_exists(argument[2])) {
            std::chrono::time_point<std::chrono::high_resolution_clock> start;
            std::chrono::time_point<std::chrono::high_resolution_clock> stop;
            if (show_time)
              start = std::chrono::high_resolution_clock::now();
            std::string number = argument[2];
            size_t DPL = decimal_point_location(number);
            size_t x = number.substr(DPL + 1, number.length()).length();
            if (x % 2 != 0) {
              x++;
              number += "0";
            }

            std::string number_temp;
            for (auto &i : number)
              if (i != '.')
                number_temp.push_back(i);
            number = number_temp;

            std::string sqrt = integer_square_root(number, accuracy - (x / 2));
            if (!decimal_point_exists(sqrt))
              sqrt += ".0";
            size_t dec_loc = decimal_point_location(sqrt);
            while (sqrt.substr(0, dec_loc).length() < (x / 2) + 1) {
              sqrt = "0" + sqrt;
              dec_loc++;
            }
            std::string sqrt_temp;
            for (auto &i : sqrt)
              if (i != '.')
                sqrt_temp.push_back(i);
            sqrt = sqrt_temp;
            sqrt = sqrt.substr(0, dec_loc - (x / 2)) + "." +
                   sqrt.substr(dec_loc - (x / 2), sqrt.length());

            std::reverse(sqrt.begin(), sqrt.end());
            sqrt.erase(0,
                       std::min(sqrt.find_first_not_of('0'), sqrt.size() - 1));
            std::reverse(sqrt.begin(), sqrt.end());
            if (show_time)
              stop = std::chrono::high_resolution_clock::now();
            std::cout << GREEN << "±" << RESET << sqrt << "\n";
            if (show_time) {
              auto time = std::chrono::duration_cast<std::chrono::microseconds>(
                              stop - start)
                              .count() /
                          100000.0;
              std::cout << "\nTime taken: " << time << " seconds. \n";
            }
          } else {
            std::chrono::time_point<std::chrono::high_resolution_clock> start;
            std::chrono::time_point<std::chrono::high_resolution_clock> stop;
            if (show_time)
              start = std::chrono::high_resolution_clock::now();
            std::string square_root =
                integer_square_root(argument[2], accuracy);
            square_root.erase(0, std::min(square_root.find_first_not_of('0'),
                                          square_root.size() - 1));
            if (show_time)
              stop = std::chrono::high_resolution_clock::now();
            std::cout << GREEN << "±" << RESET << square_root << "\n";

            if (show_time) {
              auto time = std::chrono::duration_cast<std::chrono::microseconds>(
                              stop - start)
                              .count() /
                          1000000.0;
              std::cout << "\nTime taken: " << time << " seconds. \n";
            }
          }
        } else {
          std::cout << "Syntax: math++ sqrt [number] [accuracy] [-t for "
                       "displaying time "
                       "taken] \n";
        }
      }
    }

    if (function == "subtract") {
      if (argCount == 2) {
        std::string num1, num2;

        std::cout << "\nTip: Use math++ subtract [num1] "
                     "[num2] ... [numN] to skip this interface.\n\n";
        std::cout << GREEN << "Number 1: " << RESET;
        std::cin >> num1;
        std::cout << GREEN << "Number 2: " << RESET;
        std::cin >> num2;

        std::cout << GREEN << subtract(num1, num2) << "\n" << RESET;
      }

      else if (argCount == 3) {
        std::string thirdArg = argument[2];
        if (thirdArg == "help")
          TODO;
        else
          std::cout
              << "[math++.function.subtract] Error: Insufficient Arguments! \n";
      } else if (argCount >= 4) {
        std::string answer = "0";

        for (auto i = 2; i < argCount; i++)
          answer = basic_math_operations::subtract(answer, argument[i]);

        std::cout << answer << "\n";
      }
    }

    if (function == "divide") {
      TODO;
    }

     /* if (function == "draw") {
      if (argCount < 3) {
        std::string argument3 = argument[2];
        if (argument3 == "help")
          std::cout << "Syntax: math++ draw [shape] [side1] ... [sideN] \n";
        else
          std::cout
              << "[math++.function.draw] Error: Insufficient Arguments! \n";
      }

      if (argCount >= 3) {
        std::string shape = argument[2];

        if (shape == "right_angled_triangle" ||
                shape == "right_angle_triangle" || shape == "90tri") {
          if (argCount >= 5) {
            std::vector<int> lengthSides;
            if (argCount >= 6) {
              lengthSides = {
                  std::stoi(argument[3]),
                  std::stoi(argument[4]),
                  std::stoi(argument[5]),
              };
            } else {
              lengthSides = {
                  std::stoi(argument[3]),
                  std::stoi(argument[4]),
                  (int)(std::sqrt(std::pow(std::stoi(argument[3]), 2) +
                                      std::pow(std::stoi(argument[4]), 2))),
              };
            }
            std::sort(lengthSides.begin(), lengthSides.end());

            int width = lengthSides[lengthSides.size() - 1];
            int height = lengthSides[lengthSides.size() - 2];

            cimg_library::CImg<unsigned int> image (width, height, 1, 3);
            image.fill(0xffffff);

            unsigned char black[3];
            black[0] = 255;
            black[1] = 255;
            black[2] = 255;

            for (auto i = 0; i < lengthSides[0]; i++)
              image.draw_point(0, height - i - 1, black);
            for (auto i = 0; i < lengthSides[1]; i++)
              image.draw_point(i, (height - 1), black);

            float ratio = (float)lengthSides[1] / (float) lengthSides[0];

            std::pair<float, int> start = {0, height - lengthSides[0]};
            std::pair<int, int> end = {lengthSides[1] - 1, lengthSides[1] - 1};

            std::pair<int, int> condition_pair;
            bool condition = true;
            while (condition_pair != end && condition_pair.second < end.second) {

              for (auto i = (int)start.first; i < ratio + (int)start.first; i++)
                image.draw_point(i, start.second, black);

              condition_pair = {(int)start.first, start.second};

              condition ? start.first =
                              start.first + ratio
                        : start.second++; 
              condition = !condition;
            }

            image.normalize(0, 255);
            image.save("image.bmp");

          } else if (argCount == 3) {
            std::string fourthArgument = argument[3];
            if (fourthArgument == "help")
              std::cout << "Syntax: math++ draw right_angled_triangle [height] "
                           "[base] [optional: hypotenuse] \n";
            else std::cout << "[math.function.draw.right_angled_triangle] "
                                "Error: Insufficient "
                                "Sides! \n";
          }
        }
      }
    } */

    if (function == "multiply") {
      if (argCount == 3) {
        std::string argument3 = argument[2];
        if (argument3 == "help")
          std::cout << "Syntax: math++ multiply [num1] [num2] ... [numN] \n";
        else
          std::cout
              << "[math++.function.multiply] Error: Insufficient Arguments! \n";
      }
      if (argCount >= 4) {
        std::string answer = "1";

        for (auto i = 2; i < argCount; i++)
          answer = basic_math_operations::multiply(answer, argument[i]);

        std::cout << answer << "\n";
      }
    }

    if (function == "evaluate") {

      bool debugPrint = false;

      if (argCount == 2)
        std::cout << "Syntax: math++ evaluate [mathematical_expression]\n";
      if (argCount == 3) {
        std::string sum = argument[2];

        sum.erase(std::remove(sum.begin(), sum.end(), ' '),
                  sum.end()); // Remove spaces
        auto terms = get_terms_factorization(sum);

        std::map<char, int> numbers;
        for (auto i = '0'; i <= '9'; i++)
          numbers.insert({i, i - 48});

        std::vector<algebric_num::algebric_number> nums;
        int counter = 0;
        for (auto &i : terms) {
          counter++;
          if (numbers.find(i[1]) ==
              numbers.end()) // If the second character ([0] will be the sign)
                             // of the first term is not a number
            i = i.substr(0, 1) + "1" +
                i.substr(1,
                         i.length() -
                             1); // This converts something like -x^2 to -1x^2
          if (i[0] == '+')
            i = i.substr(1, i.length() - 1);

          algebric_num::algebric_number toPB(i);
          if (debugPrint) {
            std::cout << counter << ".";
            for (auto i = 0; i < 5 - std::to_string(counter).length(); i++)
              std::cout << " ";
            std::cout << toPB.get_formatted_number() << '\n';
          }
          nums.push_back(toPB);
        }

        if (debugPrint)
          std::cout << '\n';

        for (auto i = 0; i < nums.size(); i++) { // Addition of like terms only
          for (auto j = i + 1; j < nums.size(); j++) {
            if (nums[i].variablePart == nums[j].variablePart) {
              algebric_num::algebric_number toPB("0");
              toPB.constantPart =
                  add(nums[i].constantPart, nums[j].constantPart);
              toPB.variablePart = nums[i].variablePart;
              algebric_num::erase_algebric_number(nums, i);
              j--;
              algebric_num::erase_algebric_number(nums, j);
              nums.push_back(toPB);
              j = i + 1;
            }
          }
        }

        std::cout << algebric_num::convert_to_readable(nums); // Printing out readable version.
      }
    }

    if (function == "factorize") {
      if (argCount == 2)
        std::cout << "Syntax: math++ factorize [mathematical_expression]\n";
      if (argCount >= 3) {
        std::string sum = argument[2];
        std::string answer = ax2bxc(sum);

        if (answer == "false")
          std::cout << "Cannot factorize further.";
        else
          std::cout << answer;
      }
    }
  }
}