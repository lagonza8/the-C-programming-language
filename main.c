#include <stdio.h>

// The symbolic constants used in Section 2.2
#define BITS_PER_BYTE 8

// The following include file is needed for EXERCISE 2-1
#include <limits.h>
#include <float.h>
/* the ranges for limits vary from machine to machine  */

// The following include file is needed for Section 2.3
#include <string.h>

// The following include file is needed for Section 2.7
#include <ctype.h>
/* a family of functions that provide tests and conversions that are independent of character set  */

// The following include file is needed for Section 2.7
#include <math.h>

// The symbolic constants used in Section 2.3

/* certain characters and arbitrary byte-sized bit patterns can be specified using an ESCAPE SEQUENCE  */
#define UNSIGNED_LONG_INTEGER_CONSTANT_123456789UL 123456789UL

#define VTAB '\013'     /* ASCII vertical tab specified in octal, represents decimal 11  */
#define BELL '\007'     /* ASCII bell character specified in octal, represents decimal 7  */
#define VTAB_HEX '\xb'  /* ASCII vertical tab specified in hexadecimal, represents decimal 11  */
#define BELL_HEX '\x7'  /* ASCII bell character specified in hexadecimal, represents decimal 7  */

/* example of a 'constant expression'  */
#define MAX_LINE 1000

#define LEAP 1  /* in leap years  */


// The function prototype used in Section 2.3
int string_length_function(char s[]);

// The enumeration constants used in Section 2.3

enum boolean { NO, YES };    /* will also be used in EXERCISE 2-2  */

enum escapes { BELLL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', VTABB = '\v', RETURN = '\r' };

enum months { JAN = 1, FEB , MAR , APR , MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
/* FEB is 2, MAR is 3, etc.  */
/* a convenient way to associate constant values with names, an alternative to #define with one advantage:
 * - you don't have to assign values but to first value
 * */

// The function prototype used in Section 2.4
int string_length_function_constant(const char s[]);
/* the const declaration can also be used with array arguments to indicate that the function does not change the array*/

// The function prototype used in Section 2.7
int atoi(char s[]);

// The function prototype used in Section 2.7
int convert_lower(int c);

// The function prototype used in Section 2.7, using isdigit() from the <ctype.h> standard header
int atoi_ctype(char s[]);

// The function prototype and other symbolic constants used in Section 2.7
unsigned long int next = 1;
#define MY_FAVORITE_NUMBER 8

/* srand:    set seed for rand()  */
void srand(unsigned int seed);

/* rand:    return pseudo random integer on 0... 32767  */
int rand(void);

// The function prototype and symbolic constants used in EXERCISE 2-3
/* htoi:    convert hexadecimal string hex to integer  */
int htoi(char hex[]);

#define YES 1
#define NO 0

// The function prototype used in Section 2.8
/* squeeze:     delete all c from s[]       */
void squeeze(char s[], int c);

// The function definition used for Section 2.8
/* strcat:  concatenate string t to the end of string s; string s must be big enough to  */
void strcat_ansi(char s[], char t[]);

// The function definition used in EXERCISE 2-4
/* squeeze_any:     delete each char in s1 which is in s2   */
void squeeze_any(char s1[], char s2[]);

// The function definition used in Exercise 2-5
/* any: returns the first location in the string s1 where any character from the string s2 occurs  */
int any(char s1[], char s2[]);

// The function used in Section 2.9 for binary printing and verification
/* a function that prints numbers in binary  */
void print_bin(unsigned int integer);

// The function used in Section 2.9
/* getbits: get n bits from position p  */
unsigned getbits(unsigned x, int p, int n);

// The function definition used in EXERCISE 2-6
/* setbits: set n bits of x at position p with bits of y  */
unsigned setbits(unsigned x, int p, int n, unsigned y);

// The function definition used in EXERCISE 2-7
/* invert: inverts the n bits of x that begin at position p  */
unsigned invert(unsigned x, int p, int n);

// The function definition used in EXERCISE 2-8
/* rightrot: rotate x to the right by n positions  */
unsigned rightrot(unsigned x, int n);

// The function definition used in EXERCISE 2-8
/* wordlength: computes word length of the machine  */
int wordlength(void);

// The functions definition used in section 2.10
/* bitcount: count 1 bits in x  */
int bitcount(unsigned x);

// The function definition used in Exercise 2-9
/* bitcountalt: count 1 bits in x - faster version  */
int bitcountalt(unsigned x);

// The function prototype used in Exercise 2-10
/* convert_lower_ternary: convert c to lower case (ASCII only)  */
int convert_lower_ternary(int c);

int main() {

    //CHAPTER 2: Types, Operators, and Expressions
    printf("\n\n");
    printf("CHAPTER 2: Types, Operators, and Expressions");
    printf("\n\n");



    //Section 2.1
    /* */
    printf("\n\n");
    printf("Section 2.1: Variable Names");
    printf("\n\n");

    printf("Don't begin variable names with underscore since library routines often use such names.\n");
    printf("Traditional practice is to use lower case for variable names and all upper case for symbolic constants.\n");
    printf("Use short names for local variables, especially loop indices, and longer names for external variables.\n");



    //Section 2.2
    /* */
    printf("\n\n");
    printf("Section 2.2: Data Types and Sizes");
    printf("\n\n");

    printf("There are only a few basic data types in C: char, int (including short/long), float, double \n");
    printf("The word int can be omitted from a declaration of a short or long int variable.\n");
    printf("Whether plain chars are unsigned or signed is machine dependent. How do we answer this question?\n");
    printf("However, printable characters are always positive.\n");
    printf("For comparison, size of char: %lu byte(s) \n", sizeof(char));
    printf("Size of int: %lu byte(s), on my machine, is equivalent to %lu bits\n", sizeof(int),
           sizeof(int) * BITS_PER_BYTE);

    printf("\nlong double allowed for a specification of an extended-precision floating point type.\n");
    printf("The sizes of floating point objects (float, double, and long double) are implementation defined.\n");
    /* determine the ranges of the various floating point types                                                       */


    //EXERCISE 2-1
    /*
     * The header file limits.h contains symbolic constants that represent the minimum/maximum values of any data type
     * %u is used to print unsigned integer values, %ld is used to print signed long integer types
     * %ld, %lu, %lld, %llu
     * Signed long integer, unsigned long integer, signed long long integer, unsigned long long integer
     *
     * */
    printf("\n\n");
    printf("EXERCISE 2-1\n");
    printf("Write a program to determine the ranges of char, short, int, and long variables\n");
    printf("Determine the ranges of their signed and unsigned versions.\n");
    printf("Print appropriate values from standard headers and by direct computation.\n");
    printf("Harder if you compute them: determine the ranges of the various floating-point types.\n");
    printf("output:\n");

    /* determine ranges of types                                                                                      */
    printf("We will demonstrate the ranges of 5 signed types and the max value of 5 unsigned types.\n\n");

    printf("Size of char: %lu byte(s) or %lu bits.\n", sizeof(char), BITS_PER_BYTE * sizeof(char));
    printf("Signed char minimum = %d\n", SCHAR_MIN);
    printf("Signed char maximum = %d\n", SCHAR_MAX);
    printf("Unsigned char maximum = %u\n", UCHAR_MAX);
    printf("We used SCHAR_MIN, SCHAR_MAX, and UCHAR_MAX from the standard header");
    printf("\n\n");

    printf("Size of short = %lu byte(s) or %lu bits.\n", sizeof(short), BITS_PER_BYTE * sizeof(short));
    printf("Signed short (int) minimum = %d\n", SHRT_MIN);
    printf("Signed short (int) maximum = %d\n", SHRT_MAX);
    printf("Unsigned short maximum = %u\n", USHRT_MAX);
    printf("We used SHRT_MIN, SHRT_MAX, and USHRT_MAX from the standard header");
    printf("\n\n");

    printf("Size of int: %lu byte(s) or %lu bits.\n", sizeof(int), BITS_PER_BYTE * sizeof(int));
    printf("Signed int minimum = %d\n", INT_MIN);
    printf("Signed int maximum = %d\n", INT_MAX);
    printf("Unsigned int maximum = %u\n", UINT_MAX);
    printf("We used INT_MIN, INT_MAX, and UINT_MAX from the standard header");
    printf("\n\n");

    printf("Size of long integer: %lu byte(s) or %lu bits.\n", sizeof(long), sizeof(long) * BITS_PER_BYTE);
    printf("Signed long minimum = %ld\n", LONG_MIN);
    printf("Signed long maximum = %ld\n", LONG_MAX);
    printf("Unsigned long maximum = %lu\n", ULONG_MAX);
    printf("We used LONG_MIN, LONG_MAX, and ULONG_MAX from the standard header");
    printf("\n\n");

    printf("Size of long long integer: %lu byte(s) or %lu bits.\n", sizeof(long long), sizeof(long long) * BITS_PER_BYTE);
    printf("Signed long long minimum = %lld\n", LLONG_MIN);
    printf("Signed long long maximum = %lld\n", LLONG_MAX);
    printf("Unsigned long long maximum = %llu\n", ULLONG_MAX);
    printf("We used LONG_LONG_MIN, LONG_LONG_MAX, and ULONG_LONG_MAX from the standard header");
    printf("\n\n\n");


    printf("Finding the ranges using direct computation produces:\n");
    printf("Signed char minimum = %d\n", -(char)((unsigned char) ~0 >> 1));
    /* not exactly correct but a close approximation of the minimum  */
    /* remember that -(0111 1111) is not equivalent to (1000 0000) in twos complement  */
    /* the first version is just the max value for a char type disguised as its negative counterpart  */
    /* the second is actually the proper way to represent the most negative value in a twos complement machine  */
    printf("Signed short (int) minimum = %d\n", -(short)((unsigned short ) ~0 >> 1));
    printf("\n\n");


    /* floating-point constants contain a decimal or an exponent or both
     * their type is 'double' unless suffixed
     * the suffixes 'f' or 'F' indicate a float constant
     * the suffixes 'l' or 'L' indicate a long double
     *
     * format modifiers %e, %f, %g are used for floating point types
     * %f will output the floating point value in its entirety without using an exponent,
     *                      default 6 digits after the decimal point when not specified.
     * %e will output the value using an exponent and a default 6 digits after the decimal point
     * %g will output the value using an exponent and a default 5 digits after the decimal point
     * */
    printf("Print the sizes of the floating point types.\n");
    printf("Size of float: %lu byte(s)\n", sizeof(float));
    printf("The maximum value of float = %.10e\n", FLT_MAX);
    printf("The minimum value of float = %.10e\n", FLT_MIN);

    //printf("The number of digits in the number = %.10e\n", FLT_MANT_DIG);

    printf("Size of double: %lu byte(s)\n", sizeof(double));
    printf("The maximum value of double = %.10e\n", DBL_MAX);
    printf("The minimum value of double = %.10e\n", DBL_MIN);

    printf("Size of long double: %lu byte(s)\n", sizeof(long double));
    printf("The maximum value of long double = %.10Le\n", LDBL_MAX);
    printf("The minimum value of long double = %.10Le\n", LDBL_MIN);



    //Section 2.3
    /* */
    printf("\n\n");
    printf("Section 2.3: Constants");
    printf("\n\n");

    printf("There are several types of constants in the C programming language:\n");
    printf("integer constants (including octal, hexadecimal and binary);\n");
    printf("floating-point constants (those with a decimal or exponents or both;\n");
    printf("character constants; string constants; enumeration constants; constant expressions;\n");
    printf("These are otherwise known as integer literals, string literals, float constants, etc.\n");
    printf("\n\n");

    printf("The value of an integer can be specified in binary, octal, or hexadecimal instead of decimal.\n");
    printf("Binary: leading 0b required as in 0b10011010010 for integer constant 1234.\n");
    printf("Octal: leading zero 0 required as in 02322 for integer constant 1234.\n");
    printf("Hexadecimal: leading 0x or 0X as in 0X4D2 or 0x4D2 for integer constant 1234.\n");
    printf("Binary, Octal & Hexadecimal integers can also be suffixed with unsigned (U or u) and long (L or l).\n");
    printf("For example, the hexadecimal constant, 0XFUL, is an unsigned long integer with value 15 decimal.");
    printf("\n\n");

    int binary_signed_integer_constant_1234 = 0b10011010010;
    long long octal_long_long_integer_constant_123456789LL = 0726746425LL; /* octal int value for 123456789 decimal */
    unsigned int hexadecimal_unsigned_integer_constant_1234U = 0x4D2U; /* hexadecimal int value for decimal 1234  */

    /* bad style examples  */
    long int long_integer_constant_octal_bad_style = 0726746425l;
    /* octal int value for decimal 123456789  */
    /* lower case terminal 'L' easy to confuse for the digit 1, and redundant int declaration as well  */

    printf("C programs are independent of the particular value of a character constant.\n");
    printf("Use the character constant instead of it's value in the machine's character set where ever possible.\n");
    printf("\n\n");


    printf("Certain characters and arbitrary byte-sized bit patterns can be specified using an ESCAPE SEQUENCE.\n");
    /* If the character following the \ is not one specified by the standard, the behavior is undefined
     * \a: alert (bell)
     * \b: backspace, \t: horizontal tab, \v: vertical tab
     * \f: form-feed, \n: newline, \r: carriage return
     * \\: backslash, \?: question mark, \': single quote, \": double quote
     * \ooo: octal number, \xhh: hexadecimal number
     * \0: null character
     * */


    printf("The character constant \'\\0\' represents the character with the value zero, the null character.\n");
    printf("Use the character constant \'\\0\' instead of zero to emphasize the character nature of an expression.\n");
    printf("\n\n");


    printf("A constant expression involves only constants & may be evaluated during compilation rather than run-time.\n");
    printf("A constant expression can be used in any place a constant can occur.\n");
    char line1[MAX_LINE];
    int days[31+28+LEAP+31+30+31+30+31+31+30+31+30+31];
    printf("\n\n");


    printf("A string constant or string literal is always surrounded by double quotes.\n");
    printf("It can be a sequence of zero or more characters.\n");
    printf("The empty string is a sequence of zero characters: \"\"\n");
    printf("The quotes are not part of the string, they only help to delimit the string constant/literal.\n");
    printf("Technically, a string constant is an array of characters terminated by the null character.\n");
    printf("The physical storage required is one more than the number of characters written between the quotes.\n");
    printf("This implementation means there is no limit to how long a string can be.\n");
    printf("String constants can be concatenated at compile time.\n");
    printf("This is useful for splitting long strings across several source lines.\n");
    printf("\n\n");

    printf("Remember that the character constant \'x\' is not equivalent to the string \"x\".\n");
    printf("The character constant \'x\' is an integer value, used to produce the value of the character in ");
    printf("the machine's character set.\n");
    printf("In addition, the string \"x\" is an array that contains the characters \'x\' and \'\\0\' \n");
    printf("\n\n");


    printf("Names in different enumerations must be distinct.\n");
    printf("example:\nenum months { JAN, JAN, FEB, ...}\nCould not exist.\n\n");
    printf("Values need not be distinct in the same enumeration;\nexample:\nenum months { JAN=1, FEB=1, ...} \n");
    printf("This is valid.\n");


    //Section 2.4
    /* */
    printf("\n\n");
    printf("Section 2.4: Declarations");
    printf("\n\n");

    printf("All variables must be declared before use, although certain declarations can be made implicitly by context.\n");
    printf("A variable may also be initialized in its declaration when followed by an equals sign and expression.\n");
    printf("The expression serves as the initializer.\n");
    printf("\n\n");

    int lower, upper, step;
    /* declarations specify a type and contains a list of one or more variables of that type  */
    char c, line2[1000];

    printf("When a variable is not automatic, initialization is done once and the initializer must be a ");
    printf("constant expression.\n");
    printf("\n\n");

    char esc = '\\';
    int i = 0;
    int limit = MAX_LINE + 1;
    float eps = 1.0e-5;

    printf("Explicitly initialized automatic variables can be initialized by any expression.\n");
    printf("Automatic variables for which there is no explicit initializer have undefined/garbage values.\n");
    printf("External and static variables are initialized to zero by default.\n");
    printf("\n\n");

    printf("The qualifier \'const\' can be applied to the declaration of any variable to specify that its value ");
    printf("will not be changed.\nFor an array, the const qualifier says that the elements will not be altered.\n");
    printf("The const declaration can also be used with array arguments of a function to indicate that the function ");
    printf("does not change the array.\n");

    const double e = 2.71828182845905;
    const char msg[] = "warning: ";

    printf("Calling the string length function that has a constant array argument.\n");
    printf("output: \n");
    printf("length of the uninitialized array line1 : %d\n", string_length_function(line1));
    printf("length of the uninitialized array line2 : %d\n", string_length_function(line2));
    printf("The first character of the line2 array is: %c \n", line2[0]);
    printf("The second character of the line2 array is: %c \n", line2[1]);
    printf("Not sure why a declaration like line2[1000] produces the asterisk as the first element, \n"
           "but the expression line1[MAX_LINE], where MAX_LINE also equals 1000, doesn't have the same effect.");



    //Section 2.5
    /* */
    printf("\n\n");
    printf("Section 2.5: Arithmetic Operators");
    printf("\n\n");

    printf("The binary arithmetic operators are +, -, *, /, and %% \n");
    printf("Integer division truncates any fractional part.\n");
    printf("\n\n");

    /* A year is a leap year if its is divisible by 4 but not by 100, except that years divisible by
     * 400 are leap years after all
     * */

    long long year;
    year = -2000LL;

    printf("An example of the modulus operator at work. Used to determine if a year is a leap year.\n");

    if (  ((year % 4 == 0) && (year % 100 != 0))  || (year % 400 == 0)  )
        printf("%lld is a leap year!\n", year);
    else
        printf("%lld is NOT a leap year.\n", year);
    printf("\n\n");


    printf("The modulo operator, %%, cannot be applied to float or double.\n");
    printf("The direction of truncation for / (integer division and the sign of the result for %% are ");
    printf("machine-dependent for negative operands, as is the action taken on overflow and underflow.\n");
    printf("Arithmetic operators associate from left to right.\n");
    printf("\n\n");

    //Section 2.6
    /* */
    printf("\n\n");
    printf("Section 2.6: Relational and Logical Operators");
    printf("\n\n");

    printf("The relational operators are:\n>\t>=\t<\t<=\n");
    printf("The equality operators are:\n ==\t!= \n");


    printf("The logical operators are:\n &&\t|| \n");
    printf("Expressions connected by logical operators stop being evaluated as soon as a truth or falsehood of ");
    printf("the result is known.\n");
    printf("\n\n");

    char line3[MAX_LINE];

    printf("Enter a text stream. The program will print the length of the line of input: \n");

    for(i = 0; i < limit - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
        line3[i] = c;
    printf("The length of the line is: %d \n", string_length_function(line3));
    printf("\n\n");

    /*
     * The for loop has the conditional in that order by design
     * We first check if the array has enough space to save the next character, then we must assign the next
     * character encountered before we compare it to EOF.
     *
     * Use the following string of length 84 for testing, plus the new-line when you hit enter
     * 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()-_=+`~<>?,./
     *
     * it also counts the new-line when you hit enter, there is also some strange question-mark diamond symbol appended
     * so the answer comes out to 86
     *
     * It seems like the act of copy/paste adds some extra question-mark diamond symbol character
     *
     * */

    printf("By definition, the numeric value of a relational or logical expression is 1 if the relation is true, ");
    printf(" and 0 if the relation is false.\n");

    printf("The unary negation operator ! converts a non-zero operand into 0, and a zero operand into 1.\n");
    printf("\n\n");



    //EXERCISE 2-2
    printf("\n\n");
    printf("EXERCISE 2-2\n");
    printf("Write a loop equivalent to the for-loop in getline() without using && or ||.\n");
    printf("\n\n");

    enum boolean okloop = YES;
    i = 0;

    printf("Enter a text stream. The program will print back to you the line of input: \n");

    while (okloop == YES) {
        if (i >= limit - 1)
            okloop = NO;
        else if ((c = getchar()) == '\n')
            okloop = NO;
        else if (c == EOF)
            okloop = NO;
        else {
            line1[i] = c;
            ++i;
        }
        /* a long if else statement is like a series of checkpoints you must satisfy to proceed and be counted.
         * The for loop has the conditional in that order by design:
         * We first check if the array has enough space to save the next character assignment, then we must assign the
         * next character encountered until we reach the new line, then we compare the assigned character to EOF.
         * */
    }

    printf("\nEquivalent of getline() function returns the input array named line1:\n%s\n", line1);
    printf("The length of input array named line1 is: %d \n", string_length_function(line1));
    printf("\n\n");



    //Section 2.7
    /* */
    printf("\n\n");
    printf("Section 2.7 Type Conversions\n");
    printf("\n\n");

    printf("In general, when it is obvious to convert types, like making a narrow operand wider, it is automatic.\n");
    printf("When making a wider operand narrower however, be careful, the machine you are using will allow what ");
    printf("its architecture and construction permit.\nThey are not illegal and you may see varying results.\n");

    char integer_constant_123456789UL[] = "123456789";

    printf("\n\n");
    printf("This program converts a string of digits, %s, into its numeric equivalent\n", integer_constant_123456789UL);
    printf("value result:\n%d\n", atoi(integer_constant_123456789UL));


    printf("\n\n");
    printf("Another example of a char to int conversion is this program that maps a single character to lower case.\n");

    int letter_a = 'a';
    int letter_Z = 'Z';

    printf("If the character is not an upper case letter, the function will return it unchanged.\n");
    printf("This is valid for the ASCII character set\n");

    printf("Passing a capital letter %c to the function results in:\n%c\n", letter_Z, convert_lower(letter_Z));
    printf("Passing a lower case letter %c to the function results in:\n%c\n", letter_a, convert_lower(letter_a));
    printf("This works in ASCII because the corresponding upper case and lower case letters are a fixed \n");
    printf("distance apart as numeric values and each set is contiguous.\n");

    printf("\n\n");
    printf("Using the standard header <ctype.h> and the portable replacements of the previous functions.\n");

    printf("\n\n");
    printf("Passing a capital letter %c to the function tolower():\n%c\n", letter_Z, tolower(letter_Z));
    printf("Passing a lower case letter %c to the function tolower():\n%c\n", letter_a, tolower(letter_a));

    printf("\n\n");
    printf("This program converts a string of digits, %s, into its numeric equivalent\n", integer_constant_123456789UL);
    printf("value result using isdigit():\n%d\n", atoi_ctype(integer_constant_123456789UL));

    printf("\n\n");
    printf("Character to integer conversion is not without its complications though.\n");
    printf("When a char is converted to an int, can it ever produce a negative integer\?\n");
    printf("Remember, the language does not specify whether variables of type char are signed or unsigned quantities\n");
    printf("On some machines, a char with a 1 in its leftmost bit may be interpreted/converted as a negative integer \n");
    printf("by sign extension.\n");
    printf("Some machines promote a char to an int by adding zeros at the left end, thus always positive.\n");
    printf("Be careful with arbitrary bit patterns stored in char variables for these reasons.\n");
    printf("For portability, specify signed or unsigned if non-character data is to be stored in char variables.\n");

    printf("\n\n");
    printf("In the test part of if, while, for, etc., \"true\" just means \"non-zero\".\n");
    printf("Remember, relational and logical expressions are defined to have a value of 1 if true.\n");


    printf("\n\n");
    printf("In general, if a binary operator takes two operands of different types, the \"lower\" type is ");
    printf("promoted to the \"higher\" type before the operation proceeds.\nThe result is of the higher type.\n");
    printf("The following is a flow of how types are promoted when there are no unsigned types\n");
    printf("long double < double < float < int (char & short)...\n");
    printf("... if either operand is a long, convert the other operand to a long.\n");
    printf("floats in an expression are not automatically converted to double. Main reason for using float is \n");
    printf("to save space in large arrays that use floating point values or to save time.\n");
    printf("Functions like those in <math.h> will generally use double precision");


    printf("\n\n");
    printf("Conversion rules are more complicated when unsigned operands are involved.\n");
    printf("Comparisons between signed and unsigned values are machine dependent, based on sizes of int types.\n");
    printf("Suppose int is 16 bit value and long is a 32 bit value\n");
    printf("-1L < 1U is true because 1U, which is an int, is promoted to a signed long.\n");
    printf("Remember if either operand is a long, convert the other operand to a long.\n");
    printf("However, the following is also true: -1L > 1UL\n");
    printf("This is because -1L is promoted to an unsigned long and thus appears to be a large positive number.\n");
    printf("Recall that binary twos complement value 1111 1111 1111 1111 1111 1111 1111 1111 is -1 in decimal\n");


    printf("\n\n");
    printf("Conversion also takes place across assignments; the value of the right side is converted to the type \n");
    printf("of the left, which is the type of the result. It may be accomplished with sign extension or not.\n");
    printf("Longer integers are converted to shorter ones or to chars by dropping the excess high-order bits.\n");
    printf("This is true whether or not sign extension is involved.\n");


    printf("\n\n");
    printf("float to int conversions cause truncation of any fractional part.\n");
    printf("When double is converted to float, whether the value is rounded or truncated is implementation-dependent\n");

    printf("\n\n");
    printf("Since an argument of a function call is an expression, type conversions also take place when arguments \n");
    printf("are passed to functions.\n");
    printf("In the absence of a function prototype, char and short become int, and float becomes double.\n");
    printf("Declare function arguments to be int and double even when the function is called with char and float.\n");

    printf("\n\n");
    printf("Explicit type conversions can be forced/coerced in any expression, with a unary operator called a cast.\n");
    printf("Expressions are converted using the same rules we have already discussed.\n");
    printf("The precise meaning of a cast is as if the expression were assigned to a variable of the specified \n");
    printf("type, which is then used in place of the whole construction.\n");
    printf("Here is an example of casting a long integer to a double and finding its square root\n");
    printf("The square root of 123456789 is: %.10e\n", sqrt((double)UNSIGNED_LONG_INTEGER_CONSTANT_123456789UL));
    printf("Note that the cast produces the value of the expression in the proper type.\n");
    printf("The expression/operand itself is not altered.\n");
    printf("UNSIGNED_LONG_INTEGER_CONSTANT_123456789UL = %lu\n", UNSIGNED_LONG_INTEGER_CONSTANT_123456789UL);
    printf("If arguments are declared by a function prototype, the ");
    printf("declaration causes automatic coercion of any arguments when the function is called.\n");


    printf("\n\n");
    printf("The standard library includes a portable implementation of a pseudo-random number generator, and a \n");
    printf("function for initializing the seed.\n");

    /* rand:    return pseudo random integer on 0... 32767  */
    /* srand:    set seed for rand()  */
    srand(MY_FAVORITE_NUMBER);
    printf("\nYour random integer is: %d \n", rand());


    //EXERCISE 2-3
    printf("\n\n");
    printf("EXERCISE 2-3\n");
    printf("write the function htoi(s), which converts a string of hexadecimal digits (including an optional 0X or ");
    printf("0x) into its equivalent integer value.\nThe allowable digits are 0 through 9, a through f, and A through F.");
    printf("\n\n");

    char vertical_tab_hex[] = "0xBEEF";

    printf("\n\n");
    printf("This program converts a string of hexadecimal digits, %s, into its numeric equivalent\n", vertical_tab_hex);
    printf("value result:\n%d\n", htoi(vertical_tab_hex));


    //Section 2.8
    /* */
    printf("\n\n");
    printf("Section 2.8 Increment and Decrement Operators\n");
    printf("\n\n");

    printf("The increment operator (++i) adds 1 to its operand.\n");
    printf("The decrement operator (--i) subtracts 1 from its operand.\n");
    printf("The increment/decrement operators can be used either as prefix operators (--i) before the operand, or ");
    printf("as postfix operators after (i++) the operand.\n");
    printf("They both result in the operand incremented/decremented, this is very important.\n");
    printf("The increment and decrement operators can only be applied to variables.\n");
    printf("Expressions like (i + j)++ are illegal\n");
    printf("The distinction is that the prefix operator results in the operand ");
    printf("being incremented/decremented before its value is used.\n");
    printf("The postfix operator results in incrementing/decrementing the operand after its value has been used.\n\n");

    int fivePreFix = 5;
    printf("The value of the variable fivePreFix is:\n%d\n", ++fivePreFix);

    int fivePostFix = 5;
    printf("The value of the variable fivePostFix is:\n%d\n", fivePostFix++);

    printf("\n");
    printf("In the context where just the incrementing/decrementing effect is needed, prefix and postfix are the same.\n");
    printf("\n\n");


    char beef[] = "BEEF";
    /* squeeze:     delete all c from s  */
    squeeze(beef, 'E');

    printf("\nThis is where the squeeze function ends.\n");
    printf("\n\n");


    char s[] = "BEEF";
    char t[] = "STU";
    /* strcat:  concatenate string t to the end of string s; string s must be big enough to  */
    strcat_ansi(s, t);

    printf("\nThis is where the string concatenation function ends.\n");
    printf("\n\n");



    // EXERCISE 2-4
    printf("\n\n");
    printf("EXERCISE 2-4\n");
    printf("Write an alternate version of squeeze(s1, s2) that deletes each character in s1 that matches any ");
    printf("character in the string s2.\n");
    printf("\n\n");

    char s1[] = "DICKSON";
    char s2[] = "SON";
    /* squeeze_any:     delete each char in s1 which is in s2, an alternate version of squeeze(s1, s2)   */
    squeeze_any(s1, s2);

    printf("\nThis is where the squeeze any function ends.\n");
    printf("\n\n");


    // EXERCISE 2-5
    printf("\n\n");
    printf("EXERCISE 2-5\n");
    printf("Write the function any(s1, s2), which returns the first location in the string s1 where any character ");
    printf("from the string s2 occurs,\nor -1 if s1 contains no characters from s2.\n");
    printf("\n\n");

    char s3[] = "DICKSON";
    char s4[] = "SON";
    /* any: returns the first location in the string s1 where any character from the string s2 occurs  */
    printf("The first location of any character in string \"%s\" occurring in string \"%s\" is at location:\n%d\n",
           s4, s3, any(s3, s4));

    printf("\nThis is where the first-occurrence-of-character function ends.\n");
    printf("\n\n");


    //Section 2.9
    /* */
    printf("\n\n");
    printf("Section 2.9 Bitwise Operators\n");
    printf("\n\n");

    printf("");
    printf("C provides six operators for bit manipulation; These may only be applied to integral operands.\n");
    printf("&           bitwise AND\n");
    printf("|           bitwise inclusive OR\n");
    printf("^           bitwise exclusive OR (XOR)\n");
    printf("<<          left shift\n");
    printf(">>          right shift\n");
    printf("~           one's complement (unary)\n");
    printf("\n\n");

    printf("The bitwise AND operator & is often used to mask off some set of bits; for example:\n\n");

    int binaryResult;
    int octalMask = 0177;   /* 177 octal is equivalent to   0000 0000 0000 0000 0000 0000 0111 1111 binary  */
    /* binary_signed_integer_constant_1234 is equivalent to 0000 0000 0000 0000 0000 0100 1101 0010 binary */
    binaryResult = binary_signed_integer_constant_1234 & octalMask;
    printf("The decimal result of the bitwise & operation, using integers 1234 & 127 decimal, is:\n%d\n", binaryResult);
    /* the result will set to zero all but the low-order 7 bits of 0100 1101 0010,
     * the result is 0000 0000 0101 0010, which is 82 decimal, 52 hexadecimal, 122 octal
     * the result is that it 'masks' off all bits except the ones you wish to keep unchanged.
     * */
    printf("These values are equivalent to:\n");
    printf("  0000 0100 1101 0010\n& 0000 0000 0111 1111      (mask bit-pattern)\n  0000 0000 0101 0010\n");
    printf("\n\n");

    printf("As you can see, any zero value in our mask bit-pattern turns the result's bit-pattern to zero at those positions.\n");
    printf("Any bit positions in the mask bit-pattern that is equal to 1 will have no effect on the operand.\n");
    printf("Think of any zeros in the mask bit-pattern as the mask that blocks values in the other operand.\n");


    /* to make it explicit  */
    int binaryResult2 = 0b10011010010 & 0177;
    printf("\nThe decimal result of the explicit bitwise & operation, using binary and octal integers, is:\n%d\n", binaryResult2);

    printf("\nVerification; The decimal value, %d, should be equivalent to, %d\n", binaryResult, 0b10011010010 & 0177);

    /* using our function that prints out the result in binary  */
    printf("\nUsing the function that prints out the result in binary:\n");
    print_bin(0b10011010010 & 0177);
    printf("\n\n");


    printf("\nUsing the function that prints out the result in binary, first verification:\n");
    print_bin(binaryResult);
    printf("\n\n");


    printf("\nUsing the function that prints out the result in binary, second verification:\n");
    print_bin(binaryResult2);
    printf("\n\n");


    printf("\n\n");
    printf("The bitwise OR operator | is used to turn bits on:\n");
    int SET_ON = 0b1111;
    int binaryOR;
    binaryOR = 0b10011010010 | SET_ON;
    printf("\n\n");

    /* the result should be 0100 1101 1111   */
    printf("The result of:\n  0100 1101 0010\n| 0000 0000 1111      (mask bit-pattern)\n  0100 1101 1111\n\n");

    /* similar results */
    printf("Any bit positions in the mask bit-pattern that are equal to 1 will result in activating any bit in the result.\n");
    printf("As you can see, any zero value in our mask bit-pattern has no effect.\n");

    /* using our function that prints out the result in binary to verify the OR operation */
    printf("\nUsing our function that prints out the result in binary to verify the OR operation:\n");
    print_bin(binaryOR);
    printf("\n\n");

    /* using our function that prints out the result in binary to verify the OR operation */
    printf("\nUsing our function that prints out the result in binary to confirm the OR operation explicitly:\n");
    print_bin(0b10011010010 | SET_ON);
    printf("\n\n");


    printf("\n\n");
    printf("The bitwise XOR operator ^ is used to set a 1 in each bit position where its operands have different\n");
    printf("bits, and zero where they are the same.\n");

    printf("\n\n");
    printf("The result of:\n  0100 1101 0010\n^ 0000 0000 1111      (mask bit-pattern)\n  0100 1101 1101\n");
    printf("\n\n");

    print_bin(0b10011010010 ^ 0b1111);
    /* the result should be 10011011101  */
    printf("\n\n");


    printf("One must distinguish the bitwise operators & and | from the logical operators && and ||\n");
    printf("The logical operators && and || imply left-to-right evaluation of a truth value.\n");

    int x = 1;          /* 0001 in binary  */
    int y = 2;          /* 0010 in binary  */

    printf("\n\n");
    printf("For example, if x = %d and y = %d, then x & y = 0\n", x, y);
    printf("Let us verify:\n");
    print_bin(x);
    printf(" & ");
    print_bin(y);
    printf(" = ");
    print_bin(x & y);
    printf("\n\n");

    printf("However, if x = %d and y = %d, then x && y = 1\n", x, y);
    printf("Let us verify:\n");
    printf("x && y = %d && %d = %d\n", x, y, x && y);
    printf("This is because any non-zero value is defined as 'TRUE' in a logical expression.\n");
    printf("\n\n");


    printf("The shift operators << and >> perform left and right shifts of their left operand by the number of bit \n");
    printf("positions given by the right operand, which must be positive.\n");
    printf("Thus, x << 2 shifts the value of x left by two positions, filling vacated bits with zero; ");
    printf("this is equivalent to multiplication by 4.\n");

    printf("\n\n");
    printf("Let's see an example:\n");
    printf("1111 (15 in decimal) left shifted by 2 bit positions = ");
    printf("1111 << 2 = 0011 1100 (60 in decimal)\n");
    printf("The process is to fill in vacated bits with zero.\n");
    printf("Let's verify:\n");
    printf("1111 << 2 =\n");
    print_bin(0b1111 << 2);
    printf("\n\n");

    printf("A right shift is the equivalent of integer division.\n");
    printf("Thus, x >> 2 shifts the value of x to the right by two bit positions; ");
    printf("this is equivalent to division by 4.\n");
    printf("Right shifting an unsigned quantity always fills vacated bits with zero.\n\n");

    printf("Let's see an example:\n");
    printf("100 / 4 = 25 (in decimal), let's verify using binary equivalents.\n");
    printf("100 / 4 = 00000000000000000000000001100100 >> 2 = 00000000000000000000000000011001 = 25\n");
    printf("Let's verify:\n");
    printf("100 / 4 = 00000000000000000000000001100100 >> 2 = ");
    print_bin(0b1100100 >> 2);
    printf(" = 25\n");
    printf("\n\n");


    printf("Right shifting a signed quantity will fill with sign bits (\"arithmetic shift\") on some machines\n");
    printf("and with 0-bits (\"logical shift\") on others.\n");
    printf("\n\n");

    printf("The unary operator ~ yields the one's complement of an integer, equivalent to a bit flip.\n");
    printf("For example, using x & ~077, will set the last 6 bits of x to zero, again using the & operator as a bit mask.\n");
    printf("Using example value 1234 in decimal with the unary bit value ~077, the result of the & operation is:\n");
    print_bin(1234 & ~077);
    printf("\n\n");
    /* The expression is         100 1101 0010 & ~(11 1111)
     * which is equivalent to    100 1101 0010 &   00 0000
     * which is equal to         100 1100 0000
     * */

    printf("Always use portable forms of binary, octal, and hexadecimal integers like 077, ~077, 0b111, ~0xF2B\n");
    printf("These portable forms are independent of word length and require no assumptions of how many bits a \n");
    printf("machine uses to represent integer values. Plus the portable form involves no extra cost, since \n");
    printf("a constant expression like ~077 can be evaluated at compile time.\n");
    printf("Avoid using expressions like x & ~0177700, which assumes that x is a 16-bit quantity.\n");
    printf("\n\n");


    printf("The following is a function that returns the right adjusted n-bit field of x that begins at position p.\n");
    printf("We assume that bit position 0 is at the right end and that n and p are sensible positive values.\n");
    printf("For example, getbits(x, 4, 3), returns the three bits in bit positions 4, 3, and 2, right adjusted.\n");
    printf("For this example, a sensible value of x would be a number with at least 5 bits, at least value 16 in decimal.\n");

    /* this value should return the three true bits you see below at those designated bit positions
     * because the bit positions are like an array, but backwards, because we are treating the positions as
     * right justified bit patterns with the most significant bit being the left most bit.
     * */
    printf("Let's use the value 28 in decimal, 11100 in binary, as an example.\n");
    print_bin(getbits(0b11100, 4, 3));
    printf("\n\n");


    // EXERCISE 2-6
    printf("\n\n");
    printf("EXERCISE 2-6\n");
    printf("Write a function setbits(x, p, n, y) that returns x with the n bits that begin at position p set to\n");
    printf("the rightmost n bits of y, leaving the other bits unchanged.\n");
    printf("\n\n");

    int q = 0b1000111;
    int r = 0b111;
    int setBitsResult = setbits(q, 5, 3, r);

    printf("Let's see an example:\nIf x = 1000111 and y = 111, using the setbits function will have the effect of ");
    printf("filling in the zero-bits in value x with 1-bits.\nThe result is 1111111.\n\nResult:\n");
    print_bin(setBitsResult);
    printf("\n\n");



    // EXERCISE 2-7
    printf("\n\n");
    printf("EXERCISE 2-7\n");
    printf("Write a function invert(x, p, n) that returns x with the n bits that begin at position p inverted \n");
    printf("(i.e., 1 changed into 0 and vice versa), leaving others unchanged.\n");
    printf("\n\n");

    int u = 0b1111000011110000;
    int invertResult = invert(u, 11, 4);

    printf("Let's see an example:\nIf x = 1111 0000 1111 0000, we can use the invert() function to bit flip either ");
    printf("the zero-bits or the one-bits.\n\nLet's flip the zero bits at bit positions 8 - 11 first.\n");
    printf("Result:\n");
    print_bin(invertResult);
    printf("\n\n");

    invertResult = invert(u, 7, 4);

    printf("Let's see another example:\n");
    printf("Let's flip the 1-bits at bit positions 4-7 to see the opposite inversion.\n");
    print_bin(invertResult);
    printf("\n\n");


    // EXERCISE 2-8
    printf("\n\n");
    printf("EXERCISE 2-8\n");
    printf("Write a function rightrot(x, n) that returns the value of the integer x rotated to the right \n");
    printf("by n bit positions.\n");
    printf("\n\n");

    printf("This function should create the effect of a moving chiron on a news channel repeating itself.\n");
    printf("If x = 1111 0000 1111 0000, we can use the function rightrot(x, n) to create this rotating effect.\n");
    printf("\n\n");

    print_bin(rightrot(u, 1));
    printf("\n\n");
    print_bin(rightrot(u, 2));
    printf("\n\n");
    print_bin(rightrot(u, 3));
    printf("\n\n");
    print_bin(rightrot(u, 4));
    printf("\n\n");
    print_bin(rightrot(u, 5));
    printf("\n\n");
    print_bin(rightrot(u, 6));
    printf("\n\n");
    print_bin(rightrot(u, 7));
    printf("\n\n");
    print_bin(rightrot(u, 8));
    printf("\n\n");


    //Section 2.10
    /* */
    printf("\n\n");
    printf("Section 2.10 Assignment Operators and Expressions\n");
    printf("\n\n");

    printf("\n\n");
    printf("Expression such as, i = i + 2, in which the variable on the left hand side is repeated immediately \n");
    printf("on the right, can be written in the compressed form, i += 2\n");
    printf("The operator += is called an assignment operator.\n");
    printf("\n\n");

    printf("Most binary operators (operators like + that have a left and right operand) have a corresponding\n");
    printf("assignment operator op=, where op is one of: + - * / %% << >> & ^ |\n");
    printf("Notice that expressions like, x *= y + 1, means, x = x * (y + 1), rather than x = x * y + 1\n");
    printf("\n\n");


    printf("As an example, the function bitcount counts the number of 1-bits in the argument.\n");
    printf("\n\n");
    printf("There are %d 1-bits in the binary value 1111 0000 1111 0000", bitcount(u));
    printf("\n\n");

    printf("Declaring the argument x to be unsigned ensures that when it is right-shifted, vacated bits will be \n");
    printf("filled with zeros (logical shift), not sign bits, regardless of the machine the program is run on.\n");
    printf("An assignment operator may even help a compiler to produce efficient code.\n");
    printf("\n\n");

    printf("We have already seen that the assignment statement has a value and can occur in expressions;\n");
    printf("The most common example is:\nwhile ((c = getchar()) != EOF)\n");
    printf("In the test part of if, while, for, etc., \"true\" just means \"non-zero\".\n");
    printf("\n\n");


    printf("In all such expressions, the type of an assignment expression is the type of its left operand, and \n");
    printf("the value is the value after the assignment.\n");
    printf("\n\n");


    // EXERCISE 2-9
    printf("\n\n");
    printf("EXERCISE 2-9\n");
    printf("In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x.\n");
    printf("Explain why. Use this observation to write a faster version of bit count.\n");
    printf("\n\n");

    u = 61680; // equivalent to 1111000011110000

    printf("As an example, the function bitcountalt counts the number of 1-bits in the argument.\n");
    printf("\n\n");
    printf("There are %d 1-bits in the binary value 1111 0000 1111 0000", bitcountalt(u));
    printf("\n\n");

    printf("The trick is to use the following for loop - for (b = 0; x != 0; x &= x - 1)\n");
    printf("The rightmost 1-bit of x has a corresponding 0-bit in x - 1\n");
    printf("This subtraction operation is quick for your machine to process.\n");
    printf("Any bit to the left of the rightmost 1-bit in x remains unchanged in the result.\n");
    printf("Any 0-bit in x to the right of the rightmost 1-bit in x becomes a 1-bit in x - 1, which is why "
           "it's an effective mask");
    printf("\n\n");


    printf("Take the binary values x = 1111 0000 1111 0000, then (x - 1) = 1111 0000 1110 1111 and operator [&]\n");
    printf("x =     1111 0000 1111 0000\n");
    printf("x - 1 = 1111 0000 1110 1111 &\n");
    printf("        ----------------------\n");
    printf("result  1111 0000 1110 0000\n");
    printf("\n\n");

    printf("The result is virtually identical to x, only the rightmost 1-bit in x changed to a 0-bit.\n");
    printf("Every time you removed a rightmost 1-bit from x, you kept a counter, now return that value .\n");
    printf("\n\n");


    //Section 2.11
    /* */
    printf("\n\n");
    printf("Section 2.11 Conditional Expressions\n");
    printf("\n\n");

    /*
     * How to exit the Vim editor when falling in while committing code
     * This happens when entering VIM editor after typing: git commit -a
     *
     * To exit Vim press Esc to exit edit mode, then type :q!
     * reference: https://gist.github.com/Aaronshades/b2afaa35239c6e422e9441eef0c7c68b
     *
     * Type i to switch into insert mode so that you can start adding your commit message and editing the file.
     * Enter your commit message or modify the text with your file.
     * Once you're done, press the escape key Esc to get out of insert mode and back to command mode.
     * Type :wq to save and exit your file.
     *
     * */

    int a = 10;
    int b = 5;
    int z;

    /* compute in z the maximum of a and b, a standard if-else statement  */
    if (a > b)
        z = a;
    else
        z = b;

    printf("Take:\nif (a > b)\n\tz = a;\nelse\n\tz = b;\n\n");
    printf("This would compute in z the maximum of a and b. But we could write it in a different way.\n\n");

    printf("The CONDITIONAL EXPRESSION, written with the TERNARY OPERATOR \"?:\", provides an alternate way to \n");
    printf("write an if-else block or similar constructions.\n\n");

    printf("The format is:\n\nexpression(1) ? expression(2) : expression(3)\n\nThe expression, expression(1), is ");
    printf("evaluated first. If it is non-zero (true), then the expression, expression(2), is evaluated, and \n");
    printf("that is the value of the conditional expression. Otherwise expression(3) is evaluated, and that is the \n");
    printf("value. Only one of expression(2) and expression(3) is evaluated.\n\n");
    printf("Thus to set z to the maximum of a and b, where a = 10 and b = 5\n\nz = (a > b) ? a : b;\n\n");

    z = (a > b) ? a : b;
    printf("z = %d\n\n", z);

    printf("The conditional expression is indeed an expression, and it can be used wherever any other expression can be.\n");
    printf("The ternary operator is evaluated before the assignment like we would usually expect.\n\n");

    printf("If expression(2) and expression(3) are of different types, the type of the result is determined by the ");
    printf("conversion rules discussed earlier in this chapter.\n\n");
    printf("For example, if f is a float and n is an int, then the expression\n\n(n > 0) ? f : n\n\n");
    printf("is of type float regardless of whether n is positive.\n\n");

    printf("Parentheses are not necessary around the first expression when using the ternary operator, they just \n");
    printf("just make the condition part of the expression easier to see and are thus advisable anyway.\n\n");
    printf("The conditional expression often leads to succinct code:\n\n");
    printf("Take for example:\n\n"
           "for (i = 0; i < n; i++)\n\t"
           "printf(\"%%c%%c\", msg[i], (i%%10 == 9 || i == n - 1) ? \'\\n\' : \' \');\n\n");

    printf("Remember that the array msg[] contains the string \"warning: \"\n\n");

    int n = sizeof(msg);
    //printf("%d\n", n);

    printf("The result would be:\n\n");

    for (i = 0; i < n; i++)
        printf("%c%c", msg[i], (i%10 == 9 || i == n - 1) ? '\n' : ' ');

    printf("\n\n");

    printf("This loop prints n elements of an array, 10 per line, with each column separated by a blank space, \n");
    printf("and with each line (including the last) terminated by a new line.\n");
    printf("Or put another way, a new line is printed after every tenth element, and after the n-th. "
           "All other elements are followed by one blank.\n\n");

    printf("Another good example is:\n\n");
    printf("printf(\"You have %%d item%%s.\\n\\n\", n, n == 1 ? \"\" : \"s\");\n\n");

    printf("When n = 10, the output is:\n\n");

    printf("You have %d item%s.\n\n", n, n == 1 ? "" : "s");

    printf("Now make n = 1 to see the difference. The result is now:\n\n");
    n = 1;
    printf("You have %d item%s.\n\n", n, n == 1 ? "" : "s");

    printf("This is better than printing \"You have X item(s)\", it is more personalized and careful.\n\n");

    // EXERCISE 2-10
    printf("\n\n");
    printf("EXERCISE 2-10\n");
    printf("Rewrite the function \'lower()\', which converts upper case letters to lower case, \n");
    printf("with a conditional expression instead of if-else.\n");
    printf("\n\n");

    char L = 'L';
    char G = 'G';

    printf("The character, %c, with ASCII value %d, is converted to:\n\n", L, L);
    printf("%c, which is ASCII value %d.\n\n", convert_lower_ternary(L), convert_lower_ternary(L));

    printf("\n");

    printf("The character, %c, with ASCII value %d, is converted to:\n\n", G, G);
    printf("%c, which is ASCII value %d.\n\n", convert_lower_ternary(G), convert_lower_ternary(G));

    printf("\n\n");


    //Section 2.12
    /* */
    printf("\n\n");
    printf("Section 2.12 Precedence and Order of Evaluation\n");
    printf("\n\n");

    printf("Note that the precedence of the bitwise operators &, ^, and | falls below == and !=\n");
    printf("This implies that bit-testing expressions like\n\nif ((x & MASK) == 0)...\n\n");
    printf("... must be fully parenthesized to give proper results.\n\n");


    printf("C does not specify the order in which the operands of an operator are evaluated. (The exceptions are"
           "&&, ||, ?:, and \',\'.)\n\nFor example, in a statement like\n\nx = f() + g()\n\n");

    printf("f may be evaluated before g or vice versa; thus if either f or g alters a variable on which the other\n");
    printf("depends, x can depend on the order of evaluation. Intermediate results should be stored in temporary\n");
    printf("variables to ensure a particular sequence.\n\n");

    printf("Similarly, the order in which functions arguments are evaluated is not specified.\n\n");
    printf("Statements like\n\nprintf(\"%%d %%d\\n\", ++n, power(2, n));\n\n");
    printf("can produce different results with different compilers, depending on whether n is incremented before power is called.\n\n");
    printf("The solution is to write\n\n++n;\nprintf(\"%%d %%d\\n\", n, power(2, n));\n\n");

    printf("Function calls, nested assignment statements, and increment and decrement operators cause \"side effects\"--\n");
    printf("some variable is changed as a by-product of the evaluation of an expression.\n");
    printf("There can be subtle dependencies on the order in which variables taking part in the expression are updated.\n\n");
    printf("Take for example\n\na[i] = i++;\n\nIs the subscript the old value of i or the new?.\n\n");

    printf("When side effects (assignment to variables) take place within an expression is left to the discretion of \n");
    printf("the compiler, since the best order depends strongly on the machine architecture.\n");
    printf("(The standard does specify that all side effects on arguments take effect before a function is called).\n\n");
    printf("Writing code that depends on order of evaluation is a bad programming practice in any language.\n");

    printf("");
    printf("");
    printf("");
    printf("");

    printf("");
    printf("");
    printf("");
    printf("");

    return 0;
}

// The function definition used in Section 2.3
/* string_length_function: return length of s  */
int string_length_function(char s[])
{
    int i;

    i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}

// The function definition used in Section 2.7
/* atoi: convert s to integer  */
int atoi(char s[])
{
    int i, n;
    n = 0;
    for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = n * 10 + (s[i] - '0');
    return n;
    /* the values of '0', '1', '2', etc., form a contiguous increasing sequence in ASCII character sets  */
}


// The function definition used in Section 2.7
/* lower: convert c to lower case; ASCII only  */
int convert_lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    else
        return c;
    /* You have to know that 'a' has a larger numeric value than 'A' in the ASCII character set
     *
     * '0' = 48
     * 'A' = 65
     * 'Z' = 90
     * 'a' = 97
     * 'z' = 122
     *
     * */
}


// The function definition used in Section 2.7, using isdigit() from the <ctype.h> standard header
/* atoi: convert s to integer  */
int atoi_ctype(char s[])
{
    int i, n;
    n = 0;
    for(i = 0; isdigit(s[i]); ++i)
        n = n * 10 + (s[i] - '0');
    return n;
    /* the values of '0', '1', '2', etc., form a contiguous increasing sequence in ASCII character sets
     *
     * the function isdigit() may return any non-zero value for true
     *
     * */
}


// The function definition used in Section 2.7
/* rand:    return pseudo random integer on 0... 32767  */
int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
}


/* srand:    set seed for rand()  */
void srand(unsigned int seed)
{
    next = seed;
}

// The function prototype and symbolic constants used in EXERCISE 2-3
/* htoi:    convert hexadecimal string hex to integer  */
int htoi(char hex[])
{

    int i, n, valid_hex, hex_digit;

    /* standard formatting for hexadecimal constants in the C language      */
    i = 0;
    if (hex[i] == '0') {
        ++i;
        if (hex[i] == 'X' || hex[i] == 'x') {
            ++i;
        }
    }

    n = 0;
    /* assume a valid hexadecimal string is provided to function at this point  */
    valid_hex = YES;

    for ( ; valid_hex == YES; ++i) {
        /* we don't want to reset i to zero, be careful */
        if (hex[i] >= '0' && hex[i] <= '9') {
            hex_digit =  hex[i] - '0';
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            hex_digit = hex[i] - 'a' + 10;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            hex_digit = hex[i] - 'A' + 10;
        } else
            valid_hex = NO;

        if (valid_hex == YES) {
            n = 16 * n + hex_digit;
        }
    }

    return n;
}


// The function definition used in Section 2.8
/* squeeze:     remove all occurrences of the character c from the string s[]
 *
 * Each time a non-c occurs, it is copied into the current j position, and only then is j incremented to be
 * ready for the next character.
 * */
void squeeze(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if(s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';

    printf("The result of the squeeze function, using (BEEF, 'E'), is:\n%s\n", s);

    /* Equivalent to the following
     *
    for (i = j = 0; s[i] != '0'; i++)
        if(s[i] != c)
            s[j] = s[i];
            j++;
    s[j] = '\0';

     */
}


// The function definition used for Section 2.8
/* strcat:  concatenate string t to the end of string s; string s must be big enough to  */
void strcat_ansi(char s[], char t[])
{
    int i, j;

    i = j = 0;

    /* find the end of string s     */
    while (s[i] != '\0')
        i++;

    /* copy string t    */
    while ((s[i++] = t[j++]) != '\0')
        ;
    /* As each character is copied from t to s, the postfix ++ is applied to both i and j to make sure that they are
     * used first, then incremented to be in position for the next pass through the loop   */

    printf("The result of the string concatenation function, using (BEEF, STU), is:\n%s\n", s);
}


// The function definition used in EXERCISE 2-4
/* squeeze_any:     delete each char in s1 which is in s2   */
void squeeze_any(char s1[], char s2[])
{
    int i, j, k;

    for (i = k = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
            ;
        if (s2[j] == '\0')
            s1[k++] = s1[i];
        /* if the character in s2 matches a character in s1, move on to next char in s1.
         * This has the effect of not saving the character in s1 that matched the character in s2 and
         * the character in s1 gets squeezed out and is never saved. */
    }

    /* one we iterate through all the characters in s1, we append s1 with the null terminator and return the result  */
    s1[k] = '\0';

    printf("The result of the squeeze_any function, using (\"DICKSON\", \"SON\"), is:\n%s\n", s1);
}


// The function definition used in Exercise 2-5
/* any: returns the first location in the string s1 where any character from the string s2 occurs  */
int any(char s1[], char s2[]) {

    int i, j;

    for (i = 0; s1[i] != '\0'; i++)
        for (j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])                 /* match found?  */
                return i;                       /* return location of first match  */

    return -1;                                  /* otherwise no match */
}

// The function used in Section 2.9 for binary printing and verification, retrieved on Stack Overflow
/* a function that prints numbers in binary  */
void print_bin(unsigned int integer)
{
    int i = CHAR_BIT * sizeof integer; /* however many bits are in an integer */
    while(i--) {
        putchar('0' + ((integer >> i) & 1));
    }
}



// The function used in Section 2.9
/* getbits: get n bits from position p  */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}



// The function definition used in EXERCISE 2-6
/* setbits: set n bits of x at position p with bits of y  */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return x & ~(~(~0 << n) << (p + 1 -n)) | (y & ~(~0 << n)) << (p + 1 -n);
}



// The function definition used in EXERCISE 2-7
/* invert: inverts the n bits of x that begin at position p  */
unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p + 1 -n));
}


// The function definition used in EXERCISE 2-8
/* rightrot: rotate x to the right by n positions  */
unsigned rightrot(unsigned x, int n)
{

    int wordlength(void);
    int rbit;                   /* rightmost bit  */

    while (n--  > 0) {
        rbit = (x & 1) << (wordlength() - 1);
        x = x >> 1;             /* shift x 1 position right  */
        x = x | rbit;           /* complete one rotation  */
    }

    return x;
}


// The function definition used in EXERCISE 2-8
/* wordlength: computes word length of the machine  */
int wordlength(void)
{
    int i;

    unsigned v = (unsigned) ~0;

    for (i = 1; (v = v >> 1) > 0; i++)
        ;

    return i;
}

// The functions definition used in section 2.10
/* bitcount: count 1 bits in x  */
int bitcount(unsigned x)
{
    int b;  /* this will store the value of the number of 1-bits*/

    /* right shift the value x until  you iterate over every bit  */
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)     /* bit mask for everything but the rightmost bit, evaluates to whatever the rightmost bit is in x  */
            b++;        /* if the rightmost bit is a 1-bit, increment variable b, count it as 1-bit  */
    return b;
}

// The function definition used in Exercise 2-9
/* bitcountalt: count 1 bits in x - faster version  */
int bitcountalt(unsigned x)
{
    int b;
    //and then assign value in the for loop explicitly

    for (b = 0; x != 0; x &= x - 1) {

        //every time the assignment happens in the expression x &= x - 1, there is a new value assigned when evaluated.
        //

        // this method clears the last bit of the value x and increments the counter b by 1 every time
        // it evaluates to a nonzero answer
        ++b;
    }

    return b;
}

// The function definition used in Exercise 2-10
/* convert_lower_ternary: convert c to lower case (ASCII only)  */
int convert_lower_ternary(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
