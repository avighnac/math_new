nasm -f elf64 "../../basic_math_operations/Addition Algorithm/add.asm" -o add.o
nasm -f elf64 "../../basic_math_operations/Subtraction Algorithm/subtract.asm" -o subtract.o
nasm -f elf64 "../../basic_math_operations/Multiplication Algorithm/multiply.asm" -o multiply.o
nasm -f elf64 "../../basic_math_operations/Division Algorithm/divide.asm" -o divide.o
nasm -f elf64 "../../basic_math_operations/_assembly_strlen.asm" -o _assembly_strlen.o
nasm -f elf64 "../../basic_math_operations/_remove_leading_zeroes.asm" -o _remove_leading_zeroes.o
g++ testing_software.cpp ../../basic_math_operations/basic_math_operations.cpp add.o subtract.o multiply.o divide.o _assembly_strlen.o _remove_leading_zeroes.o -O3 -o "testing_software"
./testing_software

