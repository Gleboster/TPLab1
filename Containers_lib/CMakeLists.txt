project(Containers_lib)

set(HEADER_FILES
        Container_of_containers/Queue.h
        Collections/Collection.h
        Collections/Deque.h
        Collections/List.h
        Collections/Stack.h

        Serialization/Serializator.h
        Serialization/Deserializator.h
)

set(SOURCE_FILES
        Collections/Collection.cpp
        Collections/Deque.cpp
        Collections/List.cpp
        Collections/Stack.cpp

        Serialization/Serializator.cpp
        Serialization/Deserializator.cpp
)

add_library(Containers_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})