#include <iostream>
// std:c++20
using namespace std;

#include <stdio.h> /* printf */
#include <math.h>  /* sqrt, pow */

// Given a Pythagorean Theorem
// https://en.wikipedia.org/wiki/Pythagorean_theorem
// For a triangle with a right angle and two equal non-
// diagonal sides (called a "cathetus") this computes,
// this utility computes bi-directional triangle sides:
//
// Given a the diagonal the binary computes the cathetus; OR
// Given a cathetus it computes the diagonal (when the -r flag is used)
//
// The equation: given a right triangle with the hypotenuse of d
// and two equal catheti a, the equation is:
//
//                  a^2 + a^2 = d^2, or
//                  2 * (a^2) = d^2
//
// From which we can deduce that:
//        1. given the diagonal d: a = sqrt((d^2)/2)
//        2. given the catheti  a: d = sqrt((a^2)*2)
//        2. given the catheti  a and b: d = sqrt((a^2) + (b^2))
//

const char *triangle = \
"                                     \n"
"                |\\                  \n"
"   cathetus1 ➜  | \\ ⬅︎ hypotenuse   \n"
"                |  \\                \n"
"                |___\\               \n"
"               cathetus2             \n"
"\n"
;

void help(void)
{
    printf("%s", "USAGE:\n");
    printf("%s", "\tpythagoras: -h | --help\n ");
    printf("%s", "\tpythagoras: -d | --diagonal FLOAT\n ");
    printf("%s", "\tpythagoras: -c | --catheti FLOAT [ FLOAT ]\n\n");
    printf("%s\n", triangle);
    exit(0);
}

int main(int argc, char *argv[])
{
    double diagonal;
    double cathetus1;
    double cathetus2;

    if (argc < 2 || argv[1] == NULL || std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")
    {
        help();
    }
    else if (argv[1] != NULL && ((std::string(argv[1]) == "-d" || std::string(argv[1]) == "--diagonal")) && argv[2] != NULL)
    {
        diagonal = stod(argv[2]);
        cathetus1 = cathetus2 = sqrt(pow(diagonal, 2.0) / 2.0);
        printf("Right Triangle:\n c1-[%.2f]-•-hyp-[%.2f]-•-c2-[%.2f]\n", cathetus1, diagonal, cathetus2);
    }
    else if (argv[1] != NULL && (std::string(argv[1]) == "-c" || std::string(argv[1]) == "--catheti") && argv[2] != NULL)
    {
        cathetus1 = stod(argv[2]);
        cathetus2 = (argc < 3 || argv[3] == NULL) ? cathetus1 : stod(argv[3]);
        diagonal = sqrt(cathetus1 * cathetus1 + cathetus2 * cathetus2);
        printf("Right Triangle:\n c1-[%.2f]-•-hyp-[%.2f]-•-c2-[%.2f]\n", cathetus1, diagonal, cathetus2);
    }
    else
    {
        printf("%s\n", "Invalid usage.");
        help();
        exit(1);
    }

    exit(0);
}

