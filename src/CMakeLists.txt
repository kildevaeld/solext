
SET(SOURCES
    solext.cpp
)

add_library(solext ${SOURCES})
target_link_libraries(solext lua csystem++)
target_include_directories(solext PUBLIC ${PROJECT_ROOT}/vendor/sol2/single)