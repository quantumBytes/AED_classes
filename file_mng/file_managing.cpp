#include "file_managing.h"

Word::Word() :
    begin(0),
    end(0)
{}

Word::Word(string &w, ifstream *f, p_seek _beg, p_seek _end) :
    word(w),
    file(f),
    begin(_beg),
    end(_end)
{}

void Word::setWord(string &_word) {
    word = _word;
}

void Word::setBeginSeeker(p_seek _ini) {
    begin = _ini;
}

void Word::setEndSeeker(p_seek _end) {
    end = _end;
}

void Word::setSeekers(p_seek _ini, p_seek _end) {
    begin = _ini;
    end = _end;
}

string& Word::getWord() {
    return word;
}

string &Word::getDefinition() { //NECESITA MEJORAR
    return word;
}
