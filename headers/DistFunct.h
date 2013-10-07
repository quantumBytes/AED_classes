#ifndef DISTFUNCT_H
#define DISTFUNCT_H

int fds(void *k, int tam) {
    char *p = (char *)((string &) k)->c_str();
    int s = 0;
    while(*p) {
        s += *p;
        p++;
    }
    return s%tam;
}

#endif // DISTFUNCT_H
