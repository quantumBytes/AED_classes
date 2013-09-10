#ifndef CONTAINER_H
#define CONTAINER_H

template <typename T>
class iterator {
    virtual iterator() = 0;
};

template <typename T>
class Container {
    virtual Container() = 0;
};

#endif // CONTAINER_H
