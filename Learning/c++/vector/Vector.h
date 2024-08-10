#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>    
#include <stdexcept>    
#include <initializer_list>  
#include <cmath>  

/**  
 * @class Vector  
 * @brief 一个表示数学向量的类。  
 */  
class Vector {    
private:    
    double *m_Arr = nullptr; ///< 存储向量元素的数组指针。  
    int Size = 0; ///< 向量的大小。  
  
    /**  
     * @brief 清理向量占用的内存。  
     */  
    void Clear() {    
        if (m_Arr != nullptr)    
            delete[] m_Arr;    
    }    
  
    /**  
     * @brief 初始化向量。  
     */  
    void Init() {    
        m_Arr = new double[Size]{};    
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
    Vector(int n) : Size(n) {    
        Init(); 
    };    
  
    /**  
     * @brief 拷贝构造函数。  
     * @param v 被拷贝的向量。  
     */  
    Vector(const Vector& v);  
  
    /**  
     * @brief 构造函数，使用初始化列表创建向量。  
     * @param init_list 初始化列表。  
     */  
    Vector(std::initializer_list<double> init_list);   
  
    /**  
     * @brief 移动构造函数。  
     * @param v 被移动的向量。  
     */  
    Vector(Vector&& v);  
  
    /**  
     * @brief 移动赋值操作符。  
     * @param v 被移动的向量。  
     * @return *this  
     */  
    Vector& operator=(Vector&& v);
  
    /**  
     * @brief 下标操作符，用于访问向量的元素。  
     * @param i 元素的索引。  
     * @return 向量的第i个元素。  
     */  
    double& operator[](int i);    
  
    /**  
     * @brief 下标操作符，用于访问向量的元素（const版本）。  
     * @param i 元素的索引。  
     * @return 向量的第i个元素。  
     */  
    const double &operator[](int i)  const;  
  
    /**  
     * @brief 获取向量的大小。  
     * @return 向量的大小。  
     */  
    int get_size() const;    
  
    /**  
     * @brief 析构函数。  
     */  
    ~Vector() {    
        Clear();
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
    Vector &operator=(const Vector& v);    
  
    /**  
     * @brief 赋值操作符，使用初始化列表赋值。  
     * @param init_list 初始化列表。  
     * @return *this  
     */  
    Vector& operator=(std::initializer_list<double> init_list);    
  
    /**  
     * @brief 加法赋值操作符，用于向量的加法。  
     * @param v 另一个向量。  
     * @return *this  
     */  
    Vector &operator+=(const Vector& v);
  
    /**  
     * @brief 减法赋值操作符，用于向量的减法。  
     * @param v 另一个向量。  
     * @return *this  
     */  
    Vector &operator-=(const Vector& v);    
  
    /**  
     * @brief 乘法赋值操作符，用于向量和标量的乘法。  
     * @param x 标量。  
     * @return *this  
     */  
    Vector &operator*=(double x);    
  
    /**  
     * @brief 乘法操作符，用于向量和标量的乘法。  
     * @param x 标量。  
     * @return 新的向量。  
     */  
    Vector operator*(double x);    
  
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
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);    
  
    /**  
     * @brief 加法操作符，用于向量的加法。  
     * @param v1 第一个向量。  
     * @param v2 第二个向量。  
     * @return 新的向量。  
     */  
    friend Vector operator+(const Vector& v1, const Vector& v2);    
  
    /**  
     * @brief 减法操作符，用于向量的减法。  
     * @param v1 第一个向量。  
     * @param v2 第二个向量。  
     * @return 新的向量。  
     */  
    friend Vector operator-(const Vector& v1, const Vector& v2);  
};    
    
/**  
 * @brief 输出操作符，用于打印向量。  
 * @param os 输出流。  
 * @param v 被打印的向量。  
 * @return 输出流。  
 */  
std::ostream& operator<<(std::ostream& os, const Vector& v);    
    
/**  
 * @brief 加法操作符，用于向量的加法。  
 * @param v1 第一个向量。  
 * @param v2 第二个向量。  
 * @return 新的向量。  
 */  
Vector operator+(const Vector& v1, const Vector& v2);    
  
/**  
 * @brief 减法操作符，用于向量的减法。  
 * @param v1 第一个向量。  
 * @param v2 第二个向量。  
 * @return 新的向量。  
 */  
Vector operator-(const Vector& v1, const Vector& v2);    
    
#else  
//DO NOTHING.  
#endif