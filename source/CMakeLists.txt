add_executable(TestList
  TestList.cpp
)

add_executable(aufgabe_11
  aufgabe_11.cpp
)

add_executable(aufgabe_9
  aufgabe_9.cpp
)

add_executable(aufgabe_2_und_3
  aufgabe_2_und_3.cpp
)

add_executable(aufgabe_6
  glew.c
  aufgabe_6.cpp
  circle.cpp
  color.cpp
  mat2.cpp
  vec2.cpp
  window.cpp
  glew.c
)
target_link_libraries(aufgabe_6
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

add_executable(aufgabe_4
  aufgabe_4.cpp
  circle.cpp
  color.cpp
  mat2.cpp
  vec2.cpp
  window.cpp
  glew.c
)
target_link_libraries(aufgabe_4
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

# Build example
add_executable(example
  example.cpp
  circle.cpp
  window.cpp
  glew.c
  mat2.cpp
  rectangle.cpp
  vec2.cpp
  color.cpp
  )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})

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

# Build clock
add_executable(clock
  circle.cpp
  clock.cpp
  window.cpp
  glew.c
  mat2.cpp
  rectangle.cpp
  vec2.cpp
  color.cpp
  )
target_link_libraries(clock
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(clock glfw nanovg ${COPY_BINARY})

