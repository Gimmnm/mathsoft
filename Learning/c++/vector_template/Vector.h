#ifndef __VECTOR__CRAZYFISH__  
#define __VECTOR__CRAZYFISH__  
  
#include <iostream>    
#include <stdexcept>    
#include <initializer_list>  
#include <cmath>  
  
/**  
 * @class Vector  
 * @brief 一个表示数学向量的类。  
 */  
template <typename T>
class Vector    
{    
private:    
    T *arr = nullptr; ///< 存储向量元素的数组指针。  
    int size = 0; ///< 向量的大小。  
  
    /**  
     * @brief 清理向量占用的内存。  
     */  
    void clear()    
    {    
        if (arr != nullptr)    
            delete[] arr;    
    }    
  
    /**  
     * @brief 初始化向量。  
     */  
    void init()    
    {    
        arr = new T[size]{};    
    }    
  
public:    
    /**  
     * @brief 默认构造函数。  
     */  
    Vector() {};    
  
    /**  
     * @brief 构造函数，创建指定大小的向量。  
     * @param n 向量的大小。  
     */  
    Vector(int n) : size(n)    
    {    
        init();    
    };    
  
    /**  
     * @brief 拷贝构造函数。  
     * @param v 被拷贝的向量。  
     */  
    Vector(const Vector<T> &v);  
  
    /**  
     * @brief 构造函数，使用初始化列表创建向量。  
     * @param init_list 初始化列表。  
     */  
    Vector(std::initializer_list<T> init_list);   
  
    /**  
     * @brief 移动构造函数。  
     * @param v 被移动的向量。  
     */  
    Vector(Vector<T> &&v);  
  
    /**  
     * @brief 移动赋值操作符。  
     * @param v 被移动的向量。  
     * @return *this  
     */  
    Vector<T> &operator=(Vector<T> &&v);    
  
    /**  
     * @brief 下标操作符，用于访问向量的元素。  
     * @param i 元素的索引。  
     * @return 向量的第i个元素。  
     */  
    T &operator[](int i);    
  
    /**  
     * @brief 下标操作符，用于访问向量的元素（const版本）。  
     * @param i 元素的索引。  
     * @return 向量的第i个元素。  
     */  
    const T &operator[](int i)  const;  
  
    /**  
     * @brief 获取向量的大小。  
     * @return 向量的大小。  
     */  
    int get_size() const;    
  
    /**  
     * @brief 析构函数。  
     */  
    ~Vector()    
    {    
        clear();    
    }    
  
    /**  
     * @brief 改变向量的大小。  
     * @param n 新的大小。  
     */  
    void resize(int n);    
  
    /**  
     * @brief 拷贝赋值操作符。  
     * @param v 被拷贝的向量。  
     * @return *this  
     */  
    Vector<T> &operator=(const Vector<T> &v);    
  
    /**  
     * @brief 赋值操作符，使用初始化列表赋值。  
     * @param init_list 初始化列表。  
     * @return *this  
     */  
    Vector<T> &operator=(std::initializer_list<T> init_list);    
  
    /**  
     * @brief 加法赋值操作符，用于向量的加法。  
     * @param v 另一个向量。  
     * @return *this  
     */  
    Vector<T> &operator+=(const Vector<T> &v);    
  
    /**  
     * @brief 减法赋值操作符，用于向量的减法。  
     * @param v 另一个向量。  
     * @return *this  
     */  
    Vector<T> &operator-=(const Vector<T> &v);    
  
    /**  
     * @brief 乘法赋值操作符，用于向量和标量的乘法。  
     * @param x 标量。  
     * @return *this  
     */  
    Vector<T> &operator*=(T x);    
  
    /**  
     * @brief 乘法操作符，用于向量和标量的乘法。  
     * @param x 标量。  
     * @return 新的向量。  
     */  
    Vector<T> operator*(T x);    
  
    /**  
     * @brief 计算向量的2-范数（欧几里得范数）。  
     * @return 向量的2-范数。  
     */  
    double norm() const;    
  
    /**  
     * @brief 输出操作符，用于打印向量。  
     * @param os 输出流。  
     * @param v 被打印的向量。  
     * @return 输出流。  
     */  
    template <typename U>  
    friend std::ostream &operator<<(std::ostream &os, const Vector<U> &v);      
  
    /**  
     * @brief 加法操作符，用于向量的加法。  
     * @param v1 第一个向量。  
     * @param v2 第二个向量。  
     * @return 新的向量。  
     */  
    template <typename U>  
    friend Vector<U> operator+(const Vector<U> &v1, const Vector<U> &v2);      
  
    /**  
     * @brief 减法操作符，用于向量的减法。  
     * @param v1 第一个向量。  
     * @param v2 第二个向量。  
     * @return 新的向量。  
     */  
    template <typename U>  
    friend Vector<U> operator-(const Vector<U> &v1, const Vector<U> &v2); 
};    
    
/**  
 * @brief 输出操作符，用于打印向量。  
 * @param os 输出流。  
 * @param v 被打印的向量。  
 * @return 输出流。  
 */  
template <typename U>
std::ostream &operator<< (std::ostream &os, const Vector<U> &v);    
    
/**  
 * @brief 加法操作符，用于向量的加法。  
 * @param v1 第一个向量。  
 * @param v2 第二个向量。  
 * @return 新的向量。  
 */  
template <typename U>
Vector<U> operator+ (const Vector<U> &v1, const Vector<U> &v2);    
  
/**  
 * @brief 减法操作符，用于向量的减法。  
 * @param v1 第一个向量。  
 * @param v2 第二个向量。  
 * @return 新的向量。  
 */  
template <typename U>
Vector<U> operator- (const Vector<U> &v1, const Vector<U> &v2);    

template <typename T>
Vector<T>::Vector(const Vector<T> &v) : size(v.size)  
{  
    if (this == &v)  
        return;
    init();  
    for (int i = 0; i < size; i++)  
    {  
        arr[i] = v.arr[i];  
    }  
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> init_list) 
        : size(init_list.size())  
{  
    init();  
    std::copy(init_list.begin(), init_list.end(), arr);  
}  

template <typename T>
Vector<T>::Vector(Vector<T> &&v) : size(v.size), arr(v.arr)  
{  
    v.size = 0;  
    v.arr = nullptr;  
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &&v)  
{
    clear();  
    size = v.size;  
    arr = v.arr;  
    v.size = 0;  
    v.arr = nullptr;  
    return *this;  
}

template <typename T>
T &Vector<T>::operator[](int i)  
{  
    if (i >= size)  
    {  
        throw std::out_of_range("Index out of range!");  
    }  
    return arr[i];  
}  

template <typename T>
const T &Vector<T>::operator[](int i)  const
{  
    if (i >= size)  
    {  
        throw std::out_of_range("Index out of range!");  
    }  
    return arr[i];  
}  

template <typename T>
int Vector<T>::get_size() const  
{  
    return size;  
}  
  
template <typename T>  
void Vector<T>::resize(int n)  
{  
    clear();  
    size = n;  
    init();  
}  

template <typename T>  
Vector<T> &Vector<T>::operator=(const Vector<T> &v)  
{  
    if (this == &v)  
        return *this;  

    clear();  
    size = v.size;  
    init();  
    for (int i = 0; i < size; i++)  
    {  
        arr[i] = v.arr[i];  
    }  
    return *this;  
}  

template <typename T>
Vector<T> &Vector<T>::operator=(std::initializer_list<T> init_list)  
{  
    clear();  
    size = init_list.size();  
    init();  
    std::copy(init_list.begin(), init_list.end(), arr);  
    return *this;  
}

template <typename T>
Vector<T> &Vector<T>::operator+=(const Vector<T> &v)  
{  
    if (size != v.size)  
    {  
        throw std::invalid_argument("Vector size mismatch!");  
    }  
    for (int i = 0; i < size; i++)  
    {  
        arr[i] += v.arr[i];  
    }  
    return *this;  
}

template <typename T>
Vector<T> &Vector<T>::operator-=(const Vector<T> &v)  
{  
    if (size != v.size)  
    {  
        throw std::invalid_argument("Vector size mismatch!");  
    }  
    for (int i = 0; i < size; i++)  
    {  
        arr[i] -= v.arr[i];  
    }  
    return *this;  
}

template <typename T>
Vector<T> &Vector<T>::operator*=(T x)  
{  
    for (int i = 0; i < size; i++)  
    {  
        arr[i] *= x;  
    }  
    return *this;  
}

template <typename T>
Vector<T> Vector<T>::operator*(T x)  
{  
    Vector<T> v(size);  
    for (int i = 0; i < size; i++)  
    {  
        v.arr[i] = arr[i] * x;  
    }  
    return v;  
}

template <typename T>
double Vector<T>::norm() const  
{  
    double sum = 0.0;  
    for (int i = 0; i < size; i++)  
    {  
        sum += arr[i] * arr[i];  
    }  
    return std::sqrt(sum);  
}

template <typename U> 
std::ostream &operator<< (std::ostream &os, const Vector<U> &v)  
{  
    for (int i = 0; i < v.size; i++)  
    {  
        os << v.arr[i] << " ";  
    }  
    return os;  
}  

template <typename U>  
Vector<U> operator+ (const Vector<U> &v1, const Vector<U> &v2)  
{  
    if (v1.size != v2.size)  
    {  
        throw std::invalid_argument("Vector size mismatch!");  
    }  
  
    Vector<U> v(v1.size);  
    for (int i = 0; i < v1.size; i++)  
    {  
        v.arr[i] = v1.arr[i] + v2.arr[i];  
    }  
    return v;  
}  

template <typename U>
Vector<U> operator- (const Vector<U> &v1, const Vector<U> &v2)  
{  
    if (v1.size != v2.size)  
    {  
        throw std::invalid_argument("Vector size mismatch!");  
    }  
  
    Vector<U> v(v1.size);  
    for (int i = 0; i < v1.size; i++)  
    {  
        v.arr[i] = v1.arr[i] - v2.arr[i];  
    }  
    return v;  
}

#else  
//DO NOTHING.  
#endif