cmake_minimum_required(VERSION 3.8)
project(pkgname)
set(COMP_NAME "Example")
string(TOLOWER ${COMP_NAME} COMP_NAME_LOWER)


if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package (ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_auto_add_library(${PROJECT_NAME}-${COMP_NAME_LOWER}_component SHARED
    src/${COMP_NAME_LOWER}_component.cpp
)
target_compile_definitions(${PROJECT_NAME}-${COMP_NAME_LOWER}_component
  PRIVATE ${PROJECT_NAME}_BUILDING_DLL)
rclcpp_components_register_nodes(${PROJECT_NAME}-${COMP_NAME_LOWER}_component
 "${PROJECT_NAME}::${COMP_NAME}Component")


ament_auto_add_executable(${PROJECT_NAME}-${COMP_NAME_LOWER}_node
    src/${COMP_NAME_LOWER}_node.cpp
)
target_link_libraries(${PROJECT_NAME}-${COMP_NAME_LOWER}_node
 ${PROJECT_NAME}-${COMP_NAME_LOWER}_component)

ament_auto_package()
