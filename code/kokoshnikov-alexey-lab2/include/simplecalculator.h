// Copyright 2014 Alexey Kokoshnikov

#ifndef CODE_KOKOSHNIKOV_ALEXEY_LAB2_INCLUDE_SIMPLECALCULATOR_H_
#define CODE_KOKOSHNIKOV_ALEXEY_LAB2_INCLUDE_SIMPLECALCULATOR_H_

class SimpleCalculator {
 public:
    SimpleCalculator();
    ~SimpleCalculator();

    int BinToHex(char* bin, char* hex);
    int BinToOct(char* bin, char* oct);
    int OctToBin(char* oct, char* bin);
    int HexToBin(char* hex, char* bin);
    };

#endif  // CODE_KOKOSHNIKOV_ALEXEY_LAB2_INCLUDE_SIMPLECALCULATOR_H_
