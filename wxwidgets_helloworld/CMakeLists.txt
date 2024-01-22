project(wxwidgets_helloworld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)
aux_source_directory(src src_dir)

# 添加可执行文件，指定为 WIN32，否则会编译出错，因为我们的 wxWidgets 要生成的是桌面程序
add_executable(${PROJECT_NAME} WIN32 ${src_dir})

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

find_package(wxWidgets CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE wx::core wx::base)

# 解决 MSVC 中文乱码问题
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE "/utf-8")
endif()