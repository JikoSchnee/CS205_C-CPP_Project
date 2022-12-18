#include "JChannel2.h"

////printFunc///////////////////////////////////////////////////////////////////////////////////////////////////////////
//template<typename T>
//std::string toString(const JChannel2<T> *t) {
//    std::string result = "";
//    result += "A ";
//    result += t->getRow() + 48;
//    result += "*";
//    result += t->getColumn() + 48;
//    result += " ";
//    result += typeid(t->get(1, 1)).name();
//    result += " matrix with ";
//    result += t->getChannel() + 48;
//    result += " channels";
//    return result;
//}
//
//std::ostream &operator<<(std::ostream &os, const JChannel2<int> &t) {
////    os<< typeid(t.data[0]).name()<<" int"<<" matrix with "<<t.row<<" rows and "<<t.column<<" columns and "<<t.channel<<" channels.";
//    os << toString(&t);
//    return os;
//}
//
//std::ostream &operator<<(std::ostream &os, const JChannel2<unsigned char> &t) {
//    os << toString(&t);
//    return os;
//}
//
//std::ostream &operator<<(std::ostream &os, const JChannel2<short> &t) {
//    os << toString(&t);
//    return os;
//}
//
//std::ostream &operator<<(std::ostream &os, const JChannel2<float> &t) {
//    os << toString(&t);
//    return os;
//}
//
//std::ostream &operator<<(std::ostream &os, const JChannel2<long> &t) {
//    os << toString(&t);
//    return os;
//}
////operator////////////////////////////////////////////////////////////////////////////////////////////////////////////

//template<typename T>
//JChannel2<T> JChannel2::operator+(const JChannel2<T> &mat) {
//    if (typeid(this->get(1,1)).name() != typeid(mat.get(1,1)).name()){
//        std::cerr<<"Type Error: Matrix + Matrix"<<std::endl;
//        std::cerr<<"            ^"<<typeid(this->get(1,1)).name()<<"       ^"<<typeid(mat.get(1,1)).name()<<std::endl;
//        return NULL;
//    }
//
//    T *data = nullptr;
//    data = malloc(this->row*this->column*sizeof (T));
//    if (!data){
//        std::cerr<<"Fail to malloc space: Matrix + Matrix"<<std::endl;
//        return NULL;
//    }
//    JChannel2<T> result = JChannel2<T>(this->row,this->column,data);
//    return result;
//}




////function////////////////////////////////////////////////////////////////////////////////////////////////////////////
//template<typename T>
//T JChannel2<T>::get(const size_t row, const size_t column) const {
//    return this->data[(row - 1) * this->column + (column - 1)];
//}







