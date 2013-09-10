#ifndef FILE_MANAGING_H
#define FILE_MANAGING_H

#include <fstream>
#include <iostream>

using namespace std;

class Word {
    typedef size_t p_seek;

private:
    string word;
    p_seek begin,
           end;

public:
    Word();

    Word(string &w, p_seek _beg = 0, p_seek _end = 0);

    ~Word() {}

    void setWord(string &_word);

    void setBeginSeeker(p_seek _ini);

    void setEndSeeker(p_seek _end);

    void setSeekers(p_seek _ini, p_seek _end);

    string& getWord();

    string& getDefinition();

    friend ostream &operator<<(ostream &os, Word &_word) {
        os << _word.getWord() << ": ";
        os << _word.getDefinition() << endl;
        return os;
    }
};

template <template <typename> class Container>
class Dictionary {
private:
    Container<Word> words;

public:
    Dictionary()
    {}

    ~Dictionary()
    {}

    void index(string file);

    inline size_t size() {  return words.size();    }

    friend ostream &operator<<(ostream &os, Dictionary<Container> &Dict) {
        os << Dict.words;
        return os;
    }
};

template <template <typename> class Container>
void Dictionary<Container>::index(string file) {
    string a = "Word",
            b = "rodsa";
    Word z(a),
         y(b);
    words.push_back(z);
    words.push_back(y);
}

#endif // FILE_MANAGING_H
