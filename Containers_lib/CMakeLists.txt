project(Containers_lib)

set(HEADER_FILES
        "ContainerOfContainers/Queue.h"
        Collections/Collection.h
        Collections/Deque.h
        Collections/List.h
        Collections/Stack.h
)

set(SOURCE_FILES
        Collections/Collection.cpp
        Collections/Deque.cpp
        Collections/List.cpp
        Collections/Stack.cpp
)

add_library(DateConverter_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})