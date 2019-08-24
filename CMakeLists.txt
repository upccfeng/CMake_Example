
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

PROJECT(HELLO)

# using for set VERSION info using in config.h.in
set (VER1 1)
set (VER2 2)


# generate config.h by config.h.in
CONFIGURE_FILE(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

# set a variable with 1 for test "IF"
SET(USER_COMMON 1)

# if condition is true do somethong
if (USER_COMMON)
	# add a external include folder
    INCLUDE_DIRECTORIES ("${PROJECT_SOURCE_DIR}/common")
	# include a sub directory for reading the CMakefiles.txt in this folder.
    ADD_SUBDIRECTORY (common)
    SET(EXTRA_LIBS ${EXTRA_LIBS} common)
endif (USER_COMMON)

# include all files in <PATHFOLDER>
AUX_SOURCE_DIRECTORY(. DIR_SRCS)

# build a exe file by some files.
ADD_EXECUTABLE(hello ${DIR_SRCS})

# link to a library
TARGET_LINK_LIBRARIES(hello ${EXTRA_LIBS})

# for "make install", install TARGETS to /usr/local/DESTINATION
install (TARGETS hello DESTINATION bin)
install (FILES ${PROJECT_BINARY_DIR}/config.h DESTINATION include)