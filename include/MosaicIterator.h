#pragma once
#include "Mosaic.h"
#include <array>

template<class T,int ROWS,int COLS>
class MosaicIterator {
public:
    MosaicIterator(Mosaic<T,ROWS,COLS>& mosaic,typename std::array<T,COLS>::iterator &it) : m_mosaic(mosaic),m_it(it){}
    T& operator *(){return *m_it;}
    MosaicIterator operator ++(){return ++m_it;};
    bool operator ==( const MosaicIterator& other ) {return other.m_it == m_it;};
    bool operator !=( const MosaicIterator& other ) {return other.m_it != m_it;};

private:
    Mosaic<T,ROWS,COLS>& m_mosaic;
    typename std::array<T,COLS>::iterator m_it;
};