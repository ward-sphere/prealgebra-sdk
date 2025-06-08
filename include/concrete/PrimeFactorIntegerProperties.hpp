#ifndef sdkmath_prealgebra_concrete_PrimeFactorIntegerProperties
#define sdkmath_prealgebra_concrete_PrimeFactorIntegerProperties

#include <utility/IIntegerProperties.hpp>

#include <vector>

namespace sdkmath {

    namespace prealgebra {

        namespace concrete {

            class PrimeFactorIntegerProperties : public utility::IIntegerProperties {

            public:

                std::vector<long> primeFactorization(long x) {
                    if (x < 0) return primeFactorization(-x);

                    std::vector<long> res;

                    if (x <= 1) return res;

                    for (long candidate = 2; candidate <= x; candidate++) {
                        if (x % candidate != 0) continue;

                        bool isPrime = true;
                        for (long prime : res) {
                            if (candidate % prime == 0) {
                                isPrime = false;
                                break;
                            }
                        }
                        if (!isPrime) continue;

                        while (x % candidate == 0) {
                            x /= candidate;
                            res.push_back(candidate);
                        }
                    }

                    return res;
                }

                long lcm(long x, long y) {
                    // get prime factorization
                    std::vector<long> xFactorization = primeFactorization(x), yFactorization = primeFactorization(y);
                    
                    // use two pointers to navigate lists and build lcm
                    long res = 1;
                    std::vector<long>::iterator xIt = xFactorization.begin(), xItEnd = xFactorization.end(),
                        yIt = yFactorization.begin(), yItEnd = yFactorization.end();

                    while (xIt != xItEnd || yIt != yItEnd) {
                        if (xIt == xItEnd) {
                            res *= *yIt;
                            ++yIt;
                        } else if (yIt == yItEnd) {
                            res *= *xIt;
                            ++xIt;
                        } else if (*xIt < *yIt) {
                            res *= *xIt;
                            ++xIt;
                        } else if (*yIt < *xIt) {
                            res *= *yIt;
                            ++yIt;
                        } else {
                            res *= *xIt;
                            ++xIt;
                            ++yIt;
                        }
                    }

                    return res;
                }

                long gcd(long x, long y) {
                    // get prime factorization
                    std::vector<long> xFactorization = primeFactorization(x), yFactorization = primeFactorization(y);
                    
                    // use two pointers to navigate lists and build gcd
                    long res = 1;
                    std::vector<long>::iterator xIt = xFactorization.begin(), xItEnd = xFactorization.end(),
                        yIt = yFactorization.begin(), yItEnd = yFactorization.end();

                    while (xIt != xItEnd || yIt != yItEnd) {
                        if (xIt == xItEnd) {
                            ++yIt;
                        } else if (yIt == yItEnd) {
                            ++xIt;
                        } else if (*xIt < *yIt) {
                            ++xIt;
                        } else if (*yIt < *xIt) {
                            ++yIt;
                        } else {
                            res *= *xIt;
                            ++xIt;
                            ++yIt;
                        }
                    }

                    return res;
                }

            };

        };

    };

};

#endif