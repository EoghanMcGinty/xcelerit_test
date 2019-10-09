add_executable(CorrectnessTest "correctness_test.cpp")
target_include_directories (CorrectnessTest PRIVATE ../src)
target_link_libraries (CorrectnessTest gtest_main)

add_executable(PerformanceKeyTest "performance_key.cpp")
target_include_directories (PerformanceKeyTest PRIVATE ../src)

add_executable(PerformanceIndexTest "performance_index.cpp")
target_include_directories (PerformanceIndexTest PRIVATE ../src)

install (TARGETS CorrectnessTest DESTINATION ${PROJECT_SOURCE_DIR}/bin)
install (TARGETS PerformanceKeyTest DESTINATION ${PROJECT_SOURCE_DIR}/bin)
install (TARGETS PerformanceIndexTest DESTINATION ${PROJECT_SOURCE_DIR}/bin)