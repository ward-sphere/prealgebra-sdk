#include <Fraction.hpp>

#include <vector>
#include <stdexcept>
#include <cmath>

using namespace sdkmath::prealgebra;

Fraction::Fraction() {
    setDenominator(0);
    setNumerator(0);
}

Fraction::Fraction(long numerator, long denominator) {
    setDenominator(denominator);
    setNumerator(numerator);
}

Fraction::Fraction(long value) {
    setDenominator(1);
    setNumerator(value);
}

void Fraction::setDenominator(long denominator) {
    if (denominator == 0) throw std::invalid_argument("Fraction must have nonzero denominator");
    this->denominator = denominator;
}

static std::vector<long> getPrimaryDecomposition(long value) {
    std::vector<long> res = {};
    
    const double sqrt = std::sqrt(value);
    for (long candidate = 2; candidate <= value; candidate++) {
        if (value % candidate != 0) continue;
        if (candidate >= sqrt) break;
        bool isPrime = true;
        for (long prime : res) {
            if (candidate % prime == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) res.push_back(candidate);
    }

    return res;
}

Fraction Fraction::getSimplified() const {
    // get primary decomposition of each component
    std::vector<long> numeratorPrimaryDecomposition = getPrimaryDecomposition(this->numerator);
    std::vector<long> denominatorPrimaryDecomposition = getPrimaryDecomposition(this->denominator);

    // two-pointers
    size_t numeratorPointer = 0, denominatorPointer = 0;
    long numerator = 1, denominator = 1;
    while (numeratorPointer < numeratorPrimaryDecomposition.size()
            && denominatorPointer < denominatorPrimaryDecomposition.size()) {
        if (numeratorPointer >= numeratorPrimaryDecomposition.size()) {
            denominator *= denominatorPrimaryDecomposition[denominatorPointer];
            denominatorPointer++;
        } else if (denominatorPointer >= denominatorPrimaryDecomposition.size()) {
            numerator *= numeratorPrimaryDecomposition[numeratorPointer];
            numeratorPointer++;
        } else if (denominatorPrimaryDecomposition[denominatorPointer]
                < numeratorPrimaryDecomposition[numeratorPointer]) {
            denominator *= denominatorPrimaryDecomposition[denominatorPointer];
            denominatorPointer++;
        } else if (numeratorPrimaryDecomposition[numeratorPointer]
                < denominatorPrimaryDecomposition[denominatorPointer]) {
            numerator *= numeratorPrimaryDecomposition[numeratorPointer];
            numeratorPointer++;
        } else {
            numeratorPointer++;
            denominatorPointer++;
        }
    }

    // reassign values
    return (numerator, denominator);
}

void Fraction::simplify() {
    Fraction simplified = getSimplified();
    setDenominator(simplified.getDenominator());
    setNumerator(simplified.getNumerator());
}