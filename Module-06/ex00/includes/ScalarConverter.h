#pragma once

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <cctype>
# include <limits>

#include "Colors.h"

#define IMPOSSIBLE RED "impossible" RESET
#define NON_DISPLAYABLE MAG "Non displayable" RESET

typedef enum e_type
{
	INVALID = -1,
	SPECIAL,
	DOUBLE,
	FLOAT,
	CHAR,
	INT,
}		t_type;

class ScalarConverter
{
  private:
	ScalarConverter(void);
	ScalarConverter(ScalarConverter const &src);
	ScalarConverter &operator=(ScalarConverter const &rhs);
	~ScalarConverter(void);	

  public:
	static void convert(const std::string &literal);
};

// Types checking functions
bool isInt(const std::string& literal);
bool isChar(const std::string& literal);
bool isFloat(const std::string& literal);
bool isDouble(const std::string& literal);
bool isPseudoLiteral(const std::string& literal);

// Conversion functions
void toInt(const std::string& literal);
void toChar(const std::string& literal);
void toFloat(const std::string& literal);
void toDouble(const std::string& literal);
void handlePseudoLiteral(const std::string& literal);

// Helper functions
bool checkOverflow(long double ld, t_type type);