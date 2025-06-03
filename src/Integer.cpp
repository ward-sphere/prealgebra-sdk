#include <Integer.hpp>
#include <BasicIntegerArithmetic.hpp>

using namespace sdkmath::prealgebra;

/// @brief only actually implemented function; this allows for 
/// integers to use BasicIntegerArithmetic without actually knowing 
/// about it, allowing for the implemtation details to be obscured 
/// from the using classes entirely 
IIntegerArithmetic& Integer::arithmetic() {
    static BasicIntegerArithmetic instance;
    return instance;
}