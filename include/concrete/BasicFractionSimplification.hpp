#ifndef sdkmath_prealgebra_concrete_BasicFractionSimplification
#define sdkmath_prealgebra_concrete_BasicFractionSimplification

#include <Fraction.hpp>

#include <vector>
#include <iterator>

namespace sdkmath {

    namespace prealgebra {

        namespace concrete {

            class BasicFractionSimplification : public IFractionSimplification {

            public:

                // given a long n, returns a vector of its (positive) primary decomposition
                std::vector<long> primeFactorization(long n) {
                    if (n < 0) return primeFactorization(-n);

                    std::vector<long> res;

                    if (n <= 1) return res;

                    for (long candidate = 2; candidate <= n; candidate++) {
                        // check if n is divisible by candidate
                        if (n % candidate != 0) continue;

                        // check if n is prime
                        bool isPrime = true;
                        for (long prime : res) {
                            if (candidate % prime == 0) {
                                isPrime = false;
                                break;
                            }
                        }
                        if (!isPrime) continue;

                        // add candidate as prime factor while divisible
                        while (n % candidate == 0) {
                            n /= candidate;
                            res.push_back(candidate);
                        }
                    }

                    return res;
                }

                // given two longs x and y, returns their gcd
                long find_gcd(long x, long y) {
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

                Fraction simplify(const Fraction& fraction) {
                    long gcd = find_gcd(fraction.getNumerator(), fraction.getDenominator());
                    return Fraction(
                        fraction.getNumerator() / gcd,
                        fraction.getDenominator() / gcd
                    );
                }

                long find_lcm(long x, long y) {
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

                void lcd(Fraction& lhs, Fraction& rhs) {
                    long lcm = find_lcm(lhs.getDenominator(), rhs.getDenominator());

                    lhs = Fraction(
                        lhs.getNumerator() * lcm / lhs.getDenominator(),
                        lcm
                    );
                    rhs = Fraction(
                        rhs.getNumerator() * lcm / rhs.getDenominator(),
                        lcm
                    );
                }

            };

        };

    };

};

#endif