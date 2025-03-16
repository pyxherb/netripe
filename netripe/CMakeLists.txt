find_package(peff REQUIRED)

file(GLOB HEADERS *.h *.hh)
file(GLOB SRC *.c *.cc)

set(NETRIPE_BUILD_SHARED TRUE CACHE BOOL "Build shared library")

add_library(netripe STATIC)
target_compile_definitions(netripe PRIVATE NETRIPE_IS_BUILDING=1)
set_property(TARGET netripe PROPERTY CXX_STANDARD 17)
target_include_directories(netripe PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/> $<INSTALL_INTERFACE:include/>)
target_link_libraries(netripe PUBLIC peff_containers_static)
set_target_properties(netripe PROPERTIES
    VERSION ${PROJECT_VERSION}
)

add_library(netriped SHARED)
target_compile_definitions(netriped PRIVATE NETRIPE_IS_BUILDING=1)
target_compile_definitions(netriped PUBLIC NETRIPE_BUILD_SHARED=1)
set_property(TARGET netriped PROPERTY CXX_STANDARD 17)
set_property(TARGET netriped PROPERTY PUBLIC_HEADER "")
target_include_directories(netriped PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/> $<INSTALL_INTERFACE:include/>)
target_link_libraries(netripe PUBLIC peff_containers)
set_target_properties(netriped PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    ARCHIVE FALSE
)

target_sources(netripe PRIVATE ${HEADERS} ${SRC})

if(NETRIPE_BUILD_SHARED)
    target_sources(netriped PRIVATE ${HEADERS} ${SRC})
endif()

install(TARGETS netripe netriped
    EXPORT netripeTargets
    LIBRARY DESTINATION lib/
    ARCHIVE DESTINATION lib/
    RUNTIME DESTINATION bin
)
install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/netripe)
