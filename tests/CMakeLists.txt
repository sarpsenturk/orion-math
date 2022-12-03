include(EnableGoogleTest)

include(AddGTest)
AddGTest(NAME basic_test FILENAME test.cpp DEPS cpp_starter_lib)
