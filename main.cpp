#include <iostream>


using namespace std;

template <int Size>
class IntContainer
{
public:
    int ints[Size];

    IntContainer()
    {
        //fill(ints, size(ints), 0);

        for(int i = 0 ; i < Size; i++)
        {
            ints[i] = i;
        }
    }

    class InputIterator
    {
    public:
        using category = std::input_iterator_tag;
        using diffType = std::ptrdiff_t;
        using reference = const int&;
        using pointer = const int*;
        using valueType = int;


        InputIterator(int *start):  curr(start)
        {

        }

        reference operator*() const {

            return *curr;
        }

        pointer operator->() const{
            return curr;
        }

        InputIterator& operator++()
        {
            ++curr;
            return *this;
        }

        InputIterator operator++(int dum)
        {
            InputIterator temp = *this;
            ++curr;
            return temp;
        }

        bool operator== (InputIterator const& other) const { return this->curr == other.curr; }
        bool operator!= (InputIterator const& other) const { return !(*this == other); }

    private:
        pointer curr;
    };


    InputIterator begin(){ return InputIterator(ints);};
    InputIterator end() { return InputIterator(ints + Size);}

};
int main() {
    std::cout << "Hello, World!" << std::endl;

    IntContainer<200> intContainer;

    for(auto it = intContainer.begin() ; it != intContainer.end(); it++)
    {
        cout<<*it<<endl;
    }
    return 0;
}
