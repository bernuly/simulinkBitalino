cmake_minimum_required(VERSION 2.6)
PROJECT(testBitalino)

IF(WIN32)
 set(LIBS ${LIBS} ws2_32.lib)
ELSE(WIN32)
# set(IpSystemTypePath ip/posix)
ENDIF(WIN32)


#include_directories(
#  oscpack_1_1_0
#)

#link_directories(
#  oscpack_1_1_0/build/Release
#  ../oscpack_1_1_0/build/Release # if we build in the build subdir...
#)


ADD_EXECUTABLE(testBitalino testBitalino.cpp bitalino.cpp)
TARGET_LINK_LIBRARIES(testBitalino ${LIBS})


