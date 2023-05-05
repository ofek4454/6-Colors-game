#pragma once
#include "Consts.h"
#include <array>
template<class T,int ROWS,int COLS>
class MosaicIterator;

template<class T,int ROWS,int COLS>
class Mosaic {
public:
    friend MosaicIterator<T,ROWS,COLS>;
    std::array<T,NUM_OF_COLS> operator[](int index) const{return m_array[index];}
    std::array<T,NUM_OF_ROWS>& operator[](int index){return m_array[index];}
    int rowSize() {return ROWS;}
    int colSize() {return COLS;}
    MosaicIterator<T,ROWS,COLS> begin(){
        return MosaicIterator( *this, this->m_array.begin() );
    }

    MosaicIterator<T,ROWS,COLS> end(){
        return MosaicIterator( *this, this->m_array.end() );
    }


private:
    std::array<std::array<T,COLS>,ROWS> m_array;
};
