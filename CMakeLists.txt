project(pyseqan)
cmake_minimum_required(VERSION 2.8)

find_package(Boost COMPONENTS python REQUIRED)
# TODO: Automatically detect seqan. Is there a FindSeqan.cmake?
include_directories(${Boost_INCLUDE_DIRS} /home/tobi/scm/seqan-trunk/core/include /home/tobi/scm/seqan-trunk/build/debug/core/include)
link_directories(${Boost_LIBRARY_DIRS})

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
link_directories(${PYTHON_LIBRARIES})

add_library(pyseqan SHARED pyseqan.cpp )  
set_target_properties(pyseqan PROPERTIES PREFIX "")
target_link_libraries(pyseqan ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

