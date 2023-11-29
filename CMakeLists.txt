cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/modules)

include(Policies NO_POLICY_SCOPE)

project(JACTO VERSION 0.0.1.0 LANGUAGES CXX)

add_subdirectory(src/recebe)
add_subdirectory(src/envia)
