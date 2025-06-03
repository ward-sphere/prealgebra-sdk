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

std::vector<long> Fraction::getPrimaryDecomposition(long value) {
    std::vector<long> res = {};
    
    for (long candidate = 2; candidate <= value; candidate++) {
        if (value < candidate && value % candidate != 0) continue;
        bool isPrime = true;
        for (long prime : res) {
            if (candidate % prime == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            while (value % candidate == 0) {
                value /= candidate;
                res.push_back(candidate);
            }
        }
    }

    if (value < 0) res.insert(res.begin(), -1);

    return res;
}

Fraction Fraction::getSimplified() const {
    // get primary decomposition of each component
    std::vector<long> numeratorPrimaryDecomposition = getPrimaryDecomposition(this->numerator);
    std::vector<long> denominatorPrimaryDecomposition = getPrimaryDecomposition(this->denominator);

    // two-pointers
    size_t numeratorPointer = 0, denominatorPointer = 0;
    Fraction res(1, 1);
    while (numeratorPointer < numeratorPrimaryDecomposition.size()
            || denominatorPointer < denominatorPrimaryDecomposition.size()) {
        if (numeratorPointer >= numeratorPrimaryDecomposition.size()) {
            res.setDenominator(res.getDenominator() * denominatorPrimaryDecomposition[denominatorPointer]);
            denominatorPointer++;
        } else if (denominatorPointer >= denominatorPrimaryDecomposition.size()) {
            res.setNumerator(res.getNumerator() * numeratorPrimaryDecomposition[numeratorPointer]);
            numeratorPointer++;
        } else if (denominatorPrimaryDecomposition[denominatorPointer]
                < numeratorPrimaryDecomposition[numeratorPointer]) {
            res.setDenominator(res.getDenominator() * denominatorPrimaryDecomposition[denominatorPointer]);
            denominatorPointer++;
        } else if (numeratorPrimaryDecomposition[numeratorPointer]
                < denominatorPrimaryDecomposition[denominatorPointer]) {
            res.setNumerator(res.getNumerator() * numeratorPrimaryDecomposition[numeratorPointer]);
            numeratorPointer++;
        } else {
            numeratorPointer++;
            denominatorPointer++;
        }
    }

    if (denominator < 0) {
        res.setNumerator(-res.getNumerator());
        res.setDenominator(-res.getDenominator());
    }

    // reassign values
    return res;
}

void Fraction::simplify() {
    Fraction simplified = getSimplified();
    setDenominator(simplified.getDenominator());
    setNumerator(simplified.getNumerator());
}

long Fraction::lcd(long lhs, long rhs) {
    std::vector<long> lhsDecomposition = getPrimaryDecomposition(lhs),
                      rhsDecomposition = getPrimaryDecomposition(rhs);
    
    long res = 1;
    
    size_t lPtr = 0, rPtr = 0;
    while (lPtr < lhsDecomposition.size() || rPtr < rhsDecomposition.size()) {
        if (lPtr >= lhsDecomposition.size()) {
            res *= rhsDecomposition[rPtr];
            rPtr++;
        } else if (rPtr >= rhsDecomposition.size()) {
            res *= lhsDecomposition[lPtr];
            lPtr++;
        } else if (lhsDecomposition[lPtr] < rhsDecomposition[rPtr]) {
            res *= lhsDecomposition[lPtr];
            lPtr++;
        } else if (rhsDecomposition[rPtr] < lhsDecomposition[lPtr]) {
            res *= rhsDecomposition[rPtr];
            rPtr++;
        } else {
            res *= lhsDecomposition[lPtr];
            lPtr++;
            rPtr++;
        }
    }

    return res;
}
