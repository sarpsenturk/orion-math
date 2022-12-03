include(EnableGoogleTest)

include(AddGTest)

AddGTest(NAME orion_math_abs FILENAME abs.cpp DEPS orion_math_lib)
