add_executable(TestList
  TestList.cpp
)

# Build tests
add_executable(tests
  glew.c
  vec2.cpp
  tests.cpp
  mat2.cpp
  circle.cpp
  rectangle.cpp
  window.cpp
  color.cpp
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

