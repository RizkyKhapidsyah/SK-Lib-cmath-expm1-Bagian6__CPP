#pragma warning(disable:4996)
#pragma fenv_access (on)

#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
#include <conio.h>

/*  Source by CPPReference
    Modified For Learn by Rizky Khapidsyah
    I.D.E : VS2019 */

int main() {
    std::cout << "expm1(1) = " << std::expm1(1) << '\n'
        << "Interest earned in 2 days on on $100, compounded daily at 1%\n"
        << " on a 30/360 calendar = "
        << 100 * std::expm1(2 * std::log1p(0.01 / 360)) << '\n'
        << "exp(1e-16)-1 = " << std::exp(1e-16) - 1
        << ", but expm1(1e-16) = " << std::expm1(1e-16) << '\n';
    // special values
    std::cout << "expm1(-0) = " << std::expm1(-0.0) << '\n'
        << "expm1(-Inf) = " << std::expm1(-INFINITY) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "expm1(710) = " << std::expm1(710) << '\n';

    if (errno == ERANGE) {
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    }
        
    if (std::fetestexcept(FE_OVERFLOW)) {
        std::cout << "    FE_OVERFLOW raised\n";
    }
        
    _getch();
    return 0;
}