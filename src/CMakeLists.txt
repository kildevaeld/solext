
SET(SOURCES
    solext.cpp
)

add_library(solext ${SOURCES})
target_link_libraries(solext lua csystem++)