#ifndef MATRIX_CLASS_JCHANNEL2_H
#define MATRIX_CLASS_JCHANNEL2_H

#include <cstdio>
#include <iostream>
#include <memory>

template<typename T>
class JChannel2 {
private:
    //basic information
    size_t row;
    size_t column;
    size_t channel;
    T * data;
public:
    //constructor
    JChannel2<T>(size_t row = 0, size_t column = 0, T *data = nullptr, size_t channel = 0) {
        this->row = row;
        this->column = column;
        this->channel = channel;
        this->data = new T[row*column*sizeof (T)];
        memcpy(this->data,data,row*column*sizeof (T));
        this->data = data;
    }
    //destructor
    ~JChannel2<T>(){
    }
    //printFunc
    friend std::ostream &operator<<(std::ostream &os, const JChannel2 &t){
        std::string result = "";
        result += "A ";
        result += t.row + 48;
        result += "*";
        result += t.column + 48;
        result += " ";
        result += typeid(t.get(1, 1)).name();
        result += " matrix with ";
        result += t.channel + 48;
        result += " channels";
        os<<result;
        return os;
    }

    //getFunc
    size_t getRow() const {
        return this->row;
    }

    size_t getColumn() const {
        return this->column;
    }

    size_t getChannel() const {
        return this->channel;
    }

    T get(const size_t row, const size_t column) const{
        return this->data[(row - 1) * this->column + (column - 1)];
    }

    bool set(const size_t row, const size_t column, T value){
        this->data[(row - 1) * this->column + (column - 1)] = value;
        return true;
    }

    JChannel2<T> operator+(const JChannel2<T> &mat){
        if (typeid(this->get(1, 1)).name() != typeid(mat.get(1, 1)).name()) {
            std::cerr << "Type Error: Matrix + Matrix" << std::endl;
            std::cerr << "            ^" << typeid(this->get(1, 1)).name() << "       ^" << typeid(mat.get(1, 1)).name()
                      << std::endl;
            return {};
        }
        if (this->row!=mat.getRow()){
            std::cerr << "Type Error: Matrix + Matrix" << std::endl;
            std::cerr << "r           ^" <<this->row<< "       ^" <<mat.row<< std::endl;
            return {};
        }
        if (this->column!=mat.getColumn()){
            std::cerr << "Type Error: Matrix + Matrix" << std::endl;
            std::cerr << "c           ^c=" <<this->column<< "       ^" <<mat.column<< std::endl;
            return {};
        }
        T *data = nullptr;
        data = new T[this->row * this->column];
        if (!data) {
            std::cerr << "Fail to malloc space: Matrix + Matrix" << std::endl;
            return {};
        }
        for (int i = 0; i < this->row * this->column; ++i) {
            data[i] = this->data[i]+mat.data[i];
        }
        JChannel2<T> result = JChannel2<T>(this->row, this->column, data);
        return result;
    }

    JChannel2 operator-(const JChannel2 &mat) {
        if (typeid(this->get(1, 1)).name() != typeid(mat.get(1, 1)).name()) {
            std::cerr << "Type Error: Matrix - Matrix" << std::endl;
            std::cerr << "            ^" << typeid(this->get(1, 1)).name() << "       ^" << typeid(mat.get(1, 1)).name()
                      << std::endl;
            return {};
        }
        if (this->row!=mat.getRow()){
            std::cerr << "Type Error: Matrix - Matrix" << std::endl;
            std::cerr << "r           ^" <<this->row<< "       ^" <<mat.row<< std::endl;
            return {};
        }
        if (this->column!=mat.getColumn()){
            std::cerr << "Type Error: Matrix - Matrix" << std::endl;
            std::cerr << "c           ^c=" <<this->column<< "       ^" <<mat.column<< std::endl;
            return {};
        }
        T *data = nullptr;
        data = new T[this->row * this->column];
        if (!data) {
            std::cerr << "Fail to malloc space: Matrix + Matrix" << std::endl;
            return {};
        }
        for (int i = 0; i < this->row * this->column; ++i) {
            data[i] = this->data[i]-mat.data[i];
        }
        JChannel2<T> result = JChannel2<T>(this->row, this->column, data);
        return result;
    }

    JChannel2 operator*(const JChannel2 &mat) {
        if (row != mat.cols || column != mat.rows) {
            std::cerr << "Error: Invalid to multiply this two matrix." << std::endl;
        }
        size_t r = this->row;
        size_t c = mat.column;
        T tem = 0;
#pragma omp parallel for num_threads(16)
        for (int i = 0; i < r; ++i) {
            for (int k = 0; k < r; ++k) {
                tem = this->ucP[i * r + k];
                for (int j = 0; j < r; ++j) {
                    data[i * r + j] += tem * mat.ucP[k * r + j];
                }
            }
        }
        JChannel2 result = JChannel2(r, c, data);
        delete [] data;
        return result;
    }

    JChannel2 &operator=(const JChannel2 &mat) {
        auto sp = std::shared_ptr<JChannel2<T>>(mat);
        return sp;
    }

    bool operator==(const JChannel2 &mat) {
        if (row != mat.row||column!=mat.column)return false;
        for (int i = 0; i < row*column; ++i) {
            if (this->data[i]!=mat.data[i])return false;
        }
        return true;
    }

    //function

};


#endif
