#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int d;
  std::vector<T> vec;
  PComparator p;
  void heapify(int pos);
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
  d = m;
  p = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{

}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return vec.size();
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return vec.empty();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int pos)
{
  int curpos = pos;
  while (curpos < vec.size())
  {
    int bestpos = curpos;
    for (int i = 1; i <= d;i++)
    {
      int child = d * curpos + i;
      if (child < vec.size())
        if (p(vec[child], vec[bestpos]))
          bestpos = child;
    }
    if (bestpos == curpos)
      return;
    std::swap(vec[curpos], vec[bestpos]);
    curpos = bestpos;
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  vec.push_back(item);
  int curpos = vec.size() - 1;
  while (curpos > 0)
  {
    int parent = (curpos - 1) / d;
    if (p(vec[curpos], vec[parent]))
    {
      std::swap(vec[curpos],vec[parent]);
      curpos = parent;
    }
    else
      return;
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return vec[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  std::swap(vec[0], vec[size()-1]);
  vec.pop_back();
  heapify(0);
}

#endif

