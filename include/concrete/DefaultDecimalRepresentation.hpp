#ifndef sdkmath_prealgebra_concrete_DefaultDecimalRepresentation
#define sdkmath_prealgebra_concrete_DefaultDecimalRepresentation

#include <Decimal.hpp>

#include <sstream>

#ifdef DEBUG
#include <iostream>
#endif

namespace sdkmath {

    namespace prealgebra {

        namespace concrete {

            class IDecimalStringParser {

            public:

                virtual void validateDecimal(std::string) = 0;

                virtual std::vector<std::pair<int, long>> fromString(std::string) = 0;

            };

            class DefaultDecimalRepresentation : public IDecimalRepresentation {

                std::map<int, long> encoded;

                std::unique_ptr<IDecimalStringParser> string_parser;

            public:

                DefaultDecimalRepresentation();

                void fromString(std::string s) {
#ifdef DEBUG
                    std::cout << "-> DefaultDecimalRepresentation::fromString(" << s << ")" << std::endl;
#endif
                    string_parser->validateDecimal(s);
                    auto v = string_parser->fromString(s);

#ifdef DEBUG
                    std::cout << "{" << std::endl;
#endif
                    for (auto pair : v) {
                        encoded[pair.first] = pair.second;
#ifdef DEBUG
                        std::cout << "\t{" << pair.first << ", " << pair.second << "}" << std::endl;
#endif
                    }
#ifdef DEBUG
                    std::cout << "}" << std::endl
                        << "<- DefaultDecimalRepresentation::fromString" << std::endl;
#endif
                }

                std::string toString(void) {
                    if (encoded.size() == 0) return "0";
                    
                    auto it = encoded.begin();
                    int min = (*it).first, max = min; ++it;
                    auto end = encoded.end();
                    for (; it != end; ++it) {
                        int curr = (*it).first;
                        if (curr < min) min = curr;
                        if (curr > max) max = curr;
                    }

                    min = -1 < min ? -1 : min;

                    bool negative = encoded[max] < 0;
                    std::stringstream ss;
                    if (negative) ss << "-";
                    if (max < 0) ss << "0.";
                    for (int i = max; i >= min; i--) {
                        ss << (encoded.count(i) == 1 ? encoded[i] : 0) * (negative ? -1 : 1);
                        if (i == 0) ss << '.';
                    }
                    return ss.str();
                }

                long operator[](int place) { return encoded[place]; }

                std::vector<std::pair<int, long>> toPlaceValueVector(void) {
                    std::vector<std::pair<int, long>> res;
                    for (auto pair : encoded) res.push_back(pair);
                    return res;
                }

                void fromPlaceValueVector(std::vector<std::pair<int, long>> v) {
                    std::map<int, long> tmp;
                    for (auto pair : v) {
                        int key = pair.first;
                        if (tmp.count(key) != 0) {
                            std::stringstream ss;
                            ss << "Invalid decimal vector passed with duplicate key "
                                << key;
                            throw std::invalid_argument(ss.str());
                        }

                        tmp[key] = pair.second;
                    }
                    encoded = tmp;
                }
                
            };

        };

    };

};

#endif