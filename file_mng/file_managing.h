#ifndef FILE_MANAGING_H
#define FILE_MANAGING_H

#include <fstream>
#include <iostream>

using namespace std;

class Word {
    typedef size_t p_seek;

private:
    string word;
    ifstream *file;
    p_seek begin,
           end;

public:
    Word();

    Word(string &w, ifstream *f, p_seek _beg = 0, p_seek _end = 0);

    ~Word() {}

    void setWord(string &_word);

    void setBeginSeeker(p_seek _ini);

    void setEndSeeker(p_seek _end);

    void setSeekers(p_seek _ini, p_seek _end);

    string& getWord();

    string& getDefinition();

    Word &operator =(Word _word)
    {
        word = _word.word;
        file = _word.file;
        begin = _word.begin;
        end = _word.end;
        return *this;
    }

    friend ostream &operator<<(ostream &os, Word &_word) {
        os << _word.getWord() << ": "
        << _word.getDefinition() << endl;
        return os;
    }
};

template <template <typename> class Container>
class Dictionary {
private:
    Container<Word> *words;
    ifstream *file;

public:
    Dictionary() :
        words(new Container<Word>),
        file(NULL)
    {}

    ~Dictionary() {
        if(file)
            delete file;
    }

    void index(string _file);

    inline size_t size() {  return words->size();    }

    friend ostream &operator<<(ostream &os, Dictionary<Container> &Dict) {
        Dict.words->reverse();
        os << Dict.words->front() << Dict.words->last();
//        os << (Dict.words);
        return os;
    }
};

template <template <typename> class Container>
void Dictionary<Container>::index(string _file) {
//    if(file) {
//        delete words;
//        words = new Container<Word>;
//        file->close();
//        //delete file;
//    }

    file = new ifstream(_file.c_str());
    char buffer[256];
    int ini,
        end;

    while(!file->eof()) {
        file->getline(buffer, 256, ':');
        if(buffer[0]) {
            string word(buffer);
            ini = file->tellg();
            file->ignore(256, '|');     //        file->getline(buffer, 256, '|');
            end = file->tellg();        //        cout << buffer << endl;
            Word tmp(word, file, ini, end);
            words->push_back(tmp);

        }
        file->getline(buffer, 256);
    }

//    words.push_back(z);
}

#endif // FILE_MANAGING_H
