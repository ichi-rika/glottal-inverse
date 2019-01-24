#ifndef PERSIST_C_H
#define PERSIST_C_H


#include <iostream>

#if __cplusplus < 201703L
    #include <experimental/filesystem>
    namespace fs = std::experimental::filesystem;
#else
    #include <filesystem>
    namespace fs = std::filesystem;
#endif

#include "linalg.h"
#include "amgif.h"
#include "constants.h"


#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define PERSIST_DIR "persistedOperatorC/J-" STR(J)

#define PERSIST_PATHLEN 64


vector<mat_operator> smartGetC();

bool persistC(vector<mat_operator>& C);

bool restoreC(vector<mat_operator>& C);


#endif // PERSIST_C_H