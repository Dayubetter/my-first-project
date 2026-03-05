//
// Created by dayub on 2026/3/3.
//
#include<iostream>

// 关键点一、自动扩缩容
//     1.当元素个数达到底层静态数组容量上限，扩容到2倍
//     2.当元素个数缩减到底层静态数组容量的1/4，缩容到1/2
// 关键点二、索引越界检查
//     checkElementIndex index < size
//     checkPositionIndex index <= size 处理插入元素，因为插入时不是元素的索引，而是索引之间的空隙
// 关键点三、删除元素谨防内存泄露
//     删除元素时，置为null

template<typename E>
class MyArrayList {

public:

     // 将data的容量改为newCap
     void resize(int newCap) {
          E* temp = new int[newCap];
          for (int i = 0; i < size; i++) {
               temp[i] = data[i];
          }
          delete[] data;
          data = temp;
          capacity = newCap;
     }

     // 检查索引位置是否可以存在元素
     void checkElementIndex(int index) {
          if (!isElementIndex(index)) {
               throw std::out_of_range("Index out of range");
          }
     }

     //检查索引位置是否可以添加元素
     void checkPositionIndex(int index) {
          if (!isPositionIndex(index)) {
               throw std::out_of_range("Index out of range");
          }
     }

     // int[3] 0 1 2
     bool isElementIndex(int index) {
          return index >= 0 && index < size;
     }

     // int[3] 0 1 2 3(可插)
     bool isPositionIndex(int index) {
          return index >= 0 && index <= size;
     }

     // 末尾增加
     void addBack(E e) {
          // 判断数组容量够不够
          if (size == capacity) {
               resize(2 * capacity);
          }
          // 在尾部插入元素
          data[size]=e;
          size++;
     }

     // 中间增加 在index位置插入i
     void add(int index,E e) {
          // 插入检查索引越界
          checkPositionIndex(index);
          // 看容量够不够
          if (size == capacity) {
               resize(2 * capacity);
          }
          // 从后往前遍历 往后移动
          for (int j = size; j > index; j--) {
               data[j] = data[j-1];
          }
          data[index] = e;
          size++;
     }

     // 开头增加
     void addFront(E e)  {
          add(0,e);
     }

     // 删除末尾
     E removeBack() {
          if (size == 0) {
               throw std::out_of_range("Empty array");
          }
          // 判断缩容
          if (size == capacity / 4) {
               resize(capacity / 2);
          }

          E deleteValue = data[size-1];
          // 删除最后一个元素
          // 必须给最后一个元素置为NULL，不然泄露
          data[size-1] = int();
          size--;
          return deleteValue;
     }

     // 删除中间
     E remove(int index) {
          // 检查索引越界
          checkElementIndex(index);

          if (size == capacity / 4) {
               resize(capacity / 2);
          }

          E deleteValue = data[index];

          // 搬迁数据 data[index+1..] -> data[index..]
          for (int i = index; i < size; i++) {
               data[i] = data[i+1];
          }
          data[size-1] = E();
          size--;
          return deleteValue;
     }

     // 删除首个
     E removeFront() {
          return remove(0);
     }

     // 查
     E get(int index) {
          checkElementIndex(index);
          return data[index];
     }

     // 改
     E set(int index, int value) {
          checkElementIndex(index);
          E temp = data[index];
          data[index] = value;
          return temp;
     }

     void print() const {
          for(int i = 0; i < size; i++){
               std::cout<<data[i]<<" ";
          }
          std::cout<<"\n";
     }

     int getSize() {
          return size;
     }

     MyArrayList() {
          this->data = new int[1];
          this->size = 0;
          this->capacity = 1;
     }

     explicit MyArrayList(int initCapacity){
          this->data = new E[initCapacity];
          this->size = 0;
          this->capacity = initCapacity;
     }

     ~MyArrayList(){
          delete[] data;
     }

private:
     E* data;
     int size;
     int capacity;
};

int main()
{
     MyArrayList<int> arr(3);
     arr.addBack(1);
     arr.addBack(2);
     arr.addFront(0);
     arr.add(2,22);
     arr.print();
     arr.remove(2);
     arr.print();
     arr.removeBack();
     arr.print();
     arr.removeFront();
     arr.print();
     for (int i = 0; i < 8; i++) {
          arr.add(i,i);
     }
     std::cout<<"arr.getSize() = "<<arr.getSize()<<"\n";
     for (int i = 0; i < arr.getSize(); i++) {
          std::cout << arr.get(i) << " ";
     }
}