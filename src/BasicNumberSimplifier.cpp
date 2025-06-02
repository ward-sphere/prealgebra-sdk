#include <BasicNumberSimplifier.hpp>

using namespace sdkmath::prealgebra;

static bool getPrimeFactorizationCandidates_continueGate(long& candidate, long& prev) {
    return candidate % prev != 0;
}

static bool getPrimeFactorizationCandidates_breakGate(long& candidate, long& prev) {
    return false;
}

static std::vector<long> getPrimeFactorizationCandidates(long& i) {
    std::vector<long> res = {};

    // check every number between 2 and i
    for (long candidate = 2; candidate <= i; candidate++) {
        bool valid = true;
        for (long prev : res) {
            // check if we can continue, or break altogether
            if (getPrimeFactorizationCandidates_continueGate(candidate, prev)) continue;
            if (getPrimeFactorizationCandidates_breakGate(candidate, prev)) break;

            valid = false;
            break;
        }

        if (!valid) continue;

        res.push_back(candidate);
    }

    return res;
}

std::vector<Integer> BasicNumberSimplifier::getPrimeFactors(Integer i) {
    std::vector<Integer> res = {};

    // get prime factorization candidates
    long value = i.getValue();
    std::vector<long> candidates = getPrimeFactorizationCandidates(value);

    // determine prime factorization from candidates
    for (long candidate : candidates) {
        while (value % candidate == 0) {
            value /= candidate;
            res.push_back(Integer(candidate));
        }
    }

    return res;
}

Fraction BasicNumberSimplifier::simplifyFraction(Fraction f) {
    // get prime factors of both numerator and denominator
    std::vector<Integer> numeratorFactorization = getPrimeFactors(f.getNumerator()),
        denominatorFactorization = getPrimeFactors(f.getDenominator());
    
    // utilize two pointers approach to create new numerators/denomators
    std::size_t resNumeratorValue = 1, resDenominatorValue = 1;
    std::size_t numPtr = 0, denomPtr = 0;

    while (numPtr < numeratorFactorization.size() || denomPtr < denominatorFactorization.size()) {
        if (numPtr >= numeratorFactorization.size()) {  // no more numerator values
            resDenominatorValue *= denominatorFactorization[denomPtr].getValue();
            denomPtr++;
        } else if (denomPtr >= denominatorFactorization.size()) {  // no more denominator values
            resNumeratorValue *= numeratorFactorization[numPtr].getValue();
            numPtr++;
        } else if (numeratorFactorization[numPtr].getValue() < denominatorFactorization[denomPtr].getValue()) {  // numerator factor smaller
            resNumeratorValue *= numeratorFactorization[numPtr].getValue();
            numPtr++;
        } else if (denominatorFactorization[denomPtr].getValue() < numeratorFactorization[numPtr].getValue()) {  // denominator factor smaller
            resDenominatorValue *= denominatorFactorization[denomPtr].getValue();
            denomPtr++;
        } else {  // factors equal; skip
            numPtr++;
            denomPtr++;
        }
    }

    return Fraction(Integer(resNumeratorValue), Integer(resDenominatorValue));
}
