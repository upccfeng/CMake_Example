AUX_SOURCE_DIRECTORY(. DIR_LIB_SRC)

ADD_LIBRARY(common ${DIR_LIB_SRC})


install (TARGETS common DESTINATION bin)
install (FILES common.hpp DESTINATION include)