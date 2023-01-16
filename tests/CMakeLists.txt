include(AddGTest)

AddGTest(NAME orion_math_abs FILENAME abs.cpp DEPS orion_math_lib)
AddGTest(NAME orion_math_sqrt FILENAME sqrt.cpp DEPS orion_math_lib)
AddGTest(NAME orion_math_vector FILENAME vector.cpp DEPS orion_math_lib)
