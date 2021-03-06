/**************************************************************************
 *
 * complex.cpp - Example program for complex.
 *
 * $Id: //stdlib/dev/examples/stdlib/manual/complex.cpp#12 $
 *
 ***************************************************************************
 *
 * Copyright (c) 1994-2005 Quovadx,  Inc., acting through its  Rogue Wave
 * Software division. Licensed under the Apache License, Version 2.0 (the
 * "License");  you may  not use this file except  in compliance with the
 * License.    You    may   obtain   a   copy   of    the   License    at
 * http://www.apache.org/licenses/LICENSE-2.0.    Unless   required    by
 * applicable law  or agreed to  in writing,  software  distributed under
 * the License is distributed on an "AS IS" BASIS,  WITHOUT WARRANTIES OR
 * CONDITIONS OF  ANY KIND, either  express or implied.  See  the License
 * for the specific language governing permissions  and limitations under
 * the License.
 * 
 **************************************************************************/

#include <complex>    // for complex
#include <iostream>   // for cout, endl
#include <sstream>    // for sstream

#include <examples.h>
 
int main () 
{
    // Create two arbitrary complex numbers.
    std::complex<double> a (1.2, 3.4);
    std::complex<double> b (-9.8, -7.6);

    // Perform some arithmetic on the numbers.
    a += b;
    a /= std::sin (b) * std::cos (a);
    b *= std::log (a) + std::pow (b, a);

    // Output result in fixed notation.
    std::cout.setf (std::ios::fixed, std::ios::floatfield);
    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
}
