#include "Vector.h"

Vector::Vector(const Vector& v) : Size(v.Size) {
    if (this == &v) return;
    Init();
    for (int i = 0; i < Size; i++) m_Arr[i] = v.m_Arr[i];
}

Vector::Vector(std::initializer_list<double> init_list) : Size(init_list.size()) {
    Init();
    std::copy(init_list.begin(), init_list.end(), m_Arr);
}

Vector::Vector(Vector&& v) : m_Arr(v.m_Arr), Size(v.Size) {
    v.Size = 0;
    v.m_Arr = nullptr;
}

Vector& Vector::operator=(Vector&& v) {
    Clear();
    Size = v.Size;
    m_Arr = v.m_Arr;
    v.Size = 0;
    v.m_Arr = nullptr;
    return *this;
}

double& Vector::operator[](int i) {
    if (i >= Size) throw std::out_of_range("Index out of range!");  
    return m_Arr[i];  
}  

const double& Vector::operator[](int i) const {  
    if (i >= Size) throw std::out_of_range("Index out of range!");  
    return m_Arr[i];  
}  


int Vector::get_size() const {  
    return Size;  
}  
  
void Vector::resize(int n) {  
    Clear();  
    Size = n;  
    Init();  
}  
  
Vector& Vector::operator=(const Vector& v) {  
    if (this == &v) return *this;  
    Clear();  
    Size = v.Size;  
    Init();  
    for (int i = 0; i < Size; i++)  
        m_Arr[i] = v.m_Arr[i];
    return *this;  
}  

Vector& Vector::operator=(std::initializer_list<double> init_list) {
    Clear();  
    Size = init_list.size();  
    Init();  
    std::copy(init_list.begin(), init_list.end(), m_Arr);  
    return *this;  
}

Vector& Vector::operator+=(const Vector& v) {
    if (Size != v.Size) throw std::invalid_argument("Vector size mismatch!");  
    for (int i = 0; i < Size; i++)  
        m_Arr[i] += v.m_Arr[i];  
    return *this;  
}

Vector& Vector::operator-=(const Vector& v)  
{  
    if (Size != v.Size) throw std::invalid_argument("Vector size mismatch!");  
    for (int i = 0; i < Size; i++)
        m_Arr[i] -= v.m_Arr[i];  
    return *this;  
}

Vector& Vector::operator*=(double x) {  
    for (int i = 0; i < Size; i++)  
        m_Arr[i] *= x;  
    return *this;  
}

Vector Vector::operator*(double x) {  
    Vector v(Size);  
    for (int i = 0; i < Size; i++)  
        v.m_Arr[i] = m_Arr[i] * x;  
    return v;  
}

double Vector::norm() const {  
    double sum = 0.0;  
    for (int i = 0; i < Size; i++)  
        sum += m_Arr[i] * m_Arr[i];  
    return std::sqrt(sum);  
}
 
std::ostream& operator<<(std::ostream& os, const Vector& v) {  
    for (int i = 0; i < v.Size; i++)
        os << v.m_Arr[i] << " ";  
    return os;  
}  
  
Vector operator+(const Vector& v1, const Vector& v2) {  
    if (v1.Size != v2.Size) throw std::invalid_argument("Vector size mismatch!");  
  
    Vector v(v1.Size);
    for (int i = 0; i < v1.Size; i++)  
        v.m_Arr[i] = v1.m_Arr[i] + v2.m_Arr[i];  
    return v;  
}  

Vector operator-(const Vector& v1, const Vector& v2) {  
    if (v1.Size != v2.Size) throw std::invalid_argument("Vector size mismatch!");  
  
    Vector v(v1.Size);  
    for (int i = 0; i < v1.Size; i++)  
        v.m_Arr[i] = v1.m_Arr[i] - v2.m_Arr[i];  
    return v;  
}