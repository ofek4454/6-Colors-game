#pragma once

#include "Consts.h"
#include "Pad.h"
#include "array"
/*
template<typename T,int ROWS,int COLS>
class Mosaic {
private:
    std::array<std::array<T,COLS>,ROWS> data;

public:
    Mosaic(){}

    class MosaicMosaicIterator {
    private:
//        T *ptr;

    public:
        MosaicMosaicIterator() {}

        MosaicMosaicIterator &operator++() {
            data;
            return *this;
        }

        T &operator*() const {
            return *ptr;
        }

        bool operator==(const MosaicMosaicIterator &other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const MosaicMosaicIterator &other) const {
            return !(*this == other);
        }
    };


    // Define a method to get the MosaicIterator to the beginning of the array
    MosaicMosaicIterator begin() {
        return MosaicMosaicIterator(&data[0][0]);
    }

    // Define a method to get the MosaicIterator to the end of the array
    MosaicMosaicIterator end() {
        return MosaicMosaicIterator(&data[ROWS-1][COLS-1]);
    }

    // Define a method to access the elements of the array
    T &operator()(size_t row, size_t col) {
        return data[row][col];
    }
};
*/

template<typename T, size_t Rows, size_t Cols>
class Mosaic {
public:
    // Public nested MosaicIterator class
    class MosaicIterator {
    public:
        MosaicIterator(typename std::array<std::array<T, Cols>, Rows>::iterator it_row,
                 typename std::array<T, Cols>::iterator it_col)
                : it_row_(it_row), it_col_(it_col) {}

        // Prefix increment operator
        MosaicIterator& operator++() {
            ++it_col_;
            if (it_col_ == it_row_->end()) {
                ++it_row_;
                it_col_ = it_row_->begin();
            }
            return *this;
        }

        // Postfix increment operator
        MosaicIterator operator++(int) {
            MosaicIterator temp(*this);
            ++(*this);
            return temp;
        }

        // Dereference operator
        T& operator*() {
            return *it_col_;
        }

        // Equality operator
        bool operator==(const MosaicIterator& other) const {
            return (it_row_ == other.it_row_) && (it_col_ == other.it_col_);
        }

        // Inequality operator
        bool operator!=(const MosaicIterator& other) const {
            return !(*this == other);
        }

    private:
        typename std::array<std::array<T, Cols>, Rows>::iterator it_row_;
        typename std::array<T, Cols>::iterator it_col_;
    };

    // Public member functions
    Mosaic() : m_data{} {}

    MosaicIterator begin() {
        return MosaicIterator(m_data.begin(), m_data[0].begin());
    }

    MosaicIterator end() {
        return MosaicIterator(m_data.end(), m_data[Cols - 1].end());
    }

private:
    std::array<std::array<T, Cols>, Rows> m_data;
};
