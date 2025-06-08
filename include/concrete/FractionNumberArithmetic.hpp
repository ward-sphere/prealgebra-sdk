#ifndef sdkmath_prealgebra_FractionNumberArithmetic
#define sdkmath_prealgebra_FractionNumberArithmetic

#include <Fraction.hpp>
#include <Number.hpp>

#include <concrete/PrimeFactorIntegerProperties.hpp>
#include <utility/IIntegerProperties.hpp>

namespace sdkmath {

    namespace prealgebra {

        namespace concrete {

            class FractionNumberArithmetic : public INumberArithmetic {

                std::unique_ptr<utility::IIntegerProperties> properties;

            public:

                FractionNumberArithmetic() {
                    this->properties = std::make_unique<PrimeFactorIntegerProperties>();
                }

                std::pair<std::pair<long, long>, std::pair<long, long>> common(const Number& lhs, const Number& rhs) {
                    std::pair<long, long> left_fraction = lhs.toFractionalValues();
                    std::pair<long, long> right_fraction = rhs.toFractionalValues();

                    return {left_fraction, right_fraction};
                }

                void change_base(std::pair<long, long>& u, std::pair<long, long>& v) {
                    long lcd = properties->lcm(u.second, v.second);
                    {
                        // change u to have denominator lcd
                        long multiplier = lcd / u.second;
                        u.first *= multiplier;
                        u.second *= multiplier;
                    }
                    {
                        // change v to hvae denominator lcd
                        long multiplier = lcd / v.second;
                        v.first *= multiplier;
                        v.second *= multiplier;
                    }
                }

                void simplify(std::pair<long, long>& f) {
                    long gcd = properties->gcd(f.first, f.second);
                    f.first /= gcd;
                    f.second /= gcd;
                }

                long compare(const Number& lhs, const Number& rhs) {
                    auto f = common(lhs, rhs);
                    change_base(f.first, f.second);

                    return f.first.first - f.second.first;
                }

                std::unique_ptr<Number> add(const Number& lhs, const Number& rhs) {
                    auto f = common(lhs, rhs);
                    change_base(f.first, f.second);
                    
                    std::pair<long, long> tmp = {
                        f.first.first + f.second.first,
                        f.first.second
                    };
                    simplify(tmp);

                    std::unique_ptr<Number> res = std::make_unique<Fraction>(tmp.first, tmp.second);
                    return res;
                }

                std::unique_ptr<Number> subtract(const Number& lhs, const Number& rhs) {
                    auto f = common(lhs, rhs);
                    change_base(f.first, f.second);
                    
                    std::pair<long, long> tmp = {
                        f.first.first - f.second.first,
                        f.first.second
                    };
                    simplify(tmp);

                    std::unique_ptr<Number> res = std::make_unique<Fraction>(tmp.first, tmp.second);
                    return res;
                }

                std::unique_ptr<Number> multiply(const Number& lhs, const Number& rhs) {
                    auto f = common(lhs, rhs);
                    
                    std::pair<long, long> tmp = {
                        f.first.first * f.second.first,
                        f.first.second * f.second.second
                    };
                    simplify(tmp);

                    std::unique_ptr<Number> res = std::make_unique<Fraction>(tmp.first, tmp.second);
                    return res;
                }

                std::unique_ptr<Number> divide(const Number& lhs, const Number& rhs) {
                    auto f = common(lhs, rhs);

                    if (f.second.first == 0) throw std::invalid_argument("Cannot divide by number " + rhs.toString());
                    
                    std::pair<long, long> tmp = {
                        f.first.first * f.second.second,
                        f.first.second * f.second.first
                    };
                    simplify(tmp);

                    std::unique_ptr<Number> res = std::make_unique<Fraction>(tmp.first, tmp.second);
                    return res;
                }

            };

        };

    };

};

#endif