project(helloworld LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(fmt CONFIG REQUIRED)

aux_source_directory(src src_dir)

add_executable(${PROJECT_NAME} ${src_dir})
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

# 解决 MSVC 中文乱码问题
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE "/utf-8")
endif()

