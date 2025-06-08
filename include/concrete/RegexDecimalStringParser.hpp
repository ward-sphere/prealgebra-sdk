#ifndef sdkmath_prealgebra_concrete_RegexDecimalStringParser
#define sdkmath_prealgebra_concrete_RegexDecimalStringParser

#include <concrete/DefaultDecimalRepresentation.hpp>

#include <iterator>
#include <regex>

#ifdef DEBUG
#include <iostream>
#endif

namespace sdkmath {

    namespace prealgebra {

        namespace concrete {

            class RegexDecimalStringParser : public IDecimalStringParser {

                std::string full_match = "^[+-]?((\\d*\\.\\d*)|(\\d+))$";
                
                std::string match_preprefix = "^-.*$", 
                    match_prefix = ".*((\\d+\\.)|(\\d+)).*", 
                    match_suffix = ".*\\.\\d+.*";

            public:

                void validateFullMatch(std::string s) {
#ifdef DEBUG
                    std::cout << "-> RegexDecimalStringParser::validateFullMatch(" << s << ")" << std::endl;
#endif
                    if (std::regex_match(s, std::regex(full_match))) return;

                    std::stringstream ss;
                    ss << "Decimal string " << s
                        << " did not match regular expression "
                        << full_match;
                    throw std::invalid_argument(ss.str());
#ifdef DEBUG
                    std::cout << "<- RegexDecimalStringParser::validateFullMatch" << std::endl;
#endif
                }

                void validatePartialMatch(std::string s) {
#ifdef DEBUG
                    std::cout << "-> RegexDecimalStringParser::validatePartialMatch(" << s << ")" << std::endl;
#endif
                    if (std::regex_match(s, std::regex(match_prefix))
                        || std::regex_match(s, std::regex(match_suffix))) return;

                    std::stringstream ss;
                    ss << "Decimal string " << s
                        << " did not match either regular expression "
                        << match_prefix << " or " << match_suffix;
                    throw std::invalid_argument(ss.str());
#ifdef DEBUG
                    std::cout << "<- RegexDecimalStringParser::validatePartialMatch" << std::endl;
#endif
                }

                void validateDecimal(std::string s) {
#ifdef DEBUG
                    std::cout << "-> RegexDecimalStringParser::validateDecimal(" << s << ")" << std::endl;
#endif
                    validateFullMatch(s);
                    validatePartialMatch(s);
#ifdef DEBUG
                    std::cout << "<- RegexDecimalStringParser::validateDecimal" << std::endl;
#endif
                }

                bool isNegative(std::string s) {
#ifdef DEBUG
                    std::cout << "-> RegexDecimalStringParser::isNegative(" << s << ")" << std::endl;
#endif
                    std::smatch negative;
                    bool res = std::regex_match(s, negative, std::regex(match_preprefix));
#ifdef DEBUG
                    std::cout << "<- RegexDecimalStringParser::isNegative: " << res << std::endl;
#endif
                    return res;
                }

                std::string matchPrefix(std::string s) {
#ifdef DEBUG
                    std::cout << "-> RegexDecimalStringParser::matchPrefix(" << s << ")" << std::endl;
#endif
                    std::regex rgx(match_prefix);
                    auto begin = std::sregex_iterator(s.begin(), s.end(), rgx);
                    auto end = std::sregex_iterator();

                    long tmp = 0;
                    for (std::sregex_iterator iterator = begin; iterator != end; ++iterator) {
                        sscanf(s.c_str(), "%ld", &tmp);
                        sscanf(s.c_str(), "%*[+-]%ld", &tmp);
                    }

                    std::string res =  std::to_string(tmp);
#ifdef DEBUG
                    std::cout << "<- RegexDecimalStringParser::matchPrefix: " << res << std::endl;
#endif
                    return res;
                }

                std::string matchSuffix(std::string s) {
#ifdef DEBUG
                    std::cout << "-> RegexDecimalStringParser::matchSuffix(" << s << ")" << std::endl;
#endif
                    std::regex rgx(match_prefix);
                    auto begin = std::sregex_iterator(s.begin(), s.end(), rgx);
                    auto end = std::sregex_iterator();

                    long tmp = 0;
                    for (std::sregex_iterator iterator = begin; iterator != end; ++iterator) {
                        sscanf(s.c_str(), ".%ld", &tmp);
                        sscanf(s.c_str(), "%*d.%ld", &tmp);
                        sscanf(s.c_str(), "-.%ld", &tmp);
                        sscanf(s.c_str(), "-%*d.%ld", &tmp);
                    }

                    std::string res = std::to_string(tmp);
#ifdef DEBUG
                    std::cout << "<- RegexDecimalStringParser::matchSuffix: " << res << std::endl;
#endif
                    return res;
                }

                void processPrefix(std::string prefix, std::vector<std::pair<int, long>>& table, bool negative) {
#ifdef DEBUG
                    std::cout << "-> RegexDecimalStringParser::processPrefix(" << prefix 
                        << ", std::vector<std::pair<int, long>>&, " << negative << ")" << std::endl;
#endif
                    int l = prefix.size();
                    for (int i = 0; i < l; i++) {
                        long value = prefix[i] - '0';
                        if (value == 0) continue;

                        int k = l - i - 1;
                        long v = value * (negative ? -1 : 1);
                        table.push_back({k, v});
#ifdef DEBUG
                        std::cout << "table[" << k << "] = " << v << std::endl;
#endif
                    }
#ifdef DEBUG
                    std::cout << "<- RegexDecimalStringParser::processPrefix" << std::endl;
#endif
                }

                void processSuffix(std::string suffix, std::vector<std::pair<int, long>>& table, bool negative) {
#ifdef DEBUG
                    std::cout << "-> RegexDecimalStringParser::processSuffix(" << suffix 
                        << ", std::vexctor<std::pair<int, long>>&, " << negative << ")" << std::endl;
#endif
                    int l = suffix.size();
                    for (int i = 0; i < l; i++) {
                        long value = suffix[i] - '0';
                        if (value == 0) continue;

                        int k = -(i + 1);
                        long v = value * (negative ? -1 : 1);
                        table.push_back({k, v});
#ifdef DEBUG
                        std::cout << "table[" << k << "] = " << v << std::endl;
#endif
                    }
#ifdef DEBUG
                    std::cout << "<- RegexDecimalStringParser::processSuffix" << std::endl;
#endif
                }

                std::vector<std::pair<int, long>> fromString(std::string s) {
#ifdef DEBUG
                    std::cout << "-> RegexDecimalStringParser::fromString(" << s << ")" << std::endl;
#endif
                    std::vector<std::pair<int, long>> res;

                    bool negative = isNegative(s);
                    processPrefix(matchPrefix(s), res, negative);
                    processSuffix(matchSuffix(s), res, negative);

#ifdef DEBUG
                    std::cout << "<- RegexDecimalStringParser::fromString: {" << std::endl;
                    for (auto pair : res) std::cout << "\t{" << pair.first << ", " << pair.second << "}" << std::endl;
                    std::cout << "}" << std::endl;
#endif

                    return res;
                }

            };

        };

    };

};

#endif