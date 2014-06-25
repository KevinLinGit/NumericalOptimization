INCLUDE_DIRECTORIES (
  "${NO_SRC}"
  "${CMAKE_CURRENT_SOURCE_DIR}"
)

ADD_EXECUTABLE(t_LRResolver
    t_LUResolver.cpp
)

TARGET_LINK_LIBRARIES(t_LRResolver no_mf)
ADD_TEST(mf t_LRResolver)
