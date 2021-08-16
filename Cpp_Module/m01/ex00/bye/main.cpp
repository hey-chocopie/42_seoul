#include "Pony.hpp"

void ponyOnTheHeap( void )
{
	std::cout << "========= heap pony ========" << std::endl;
    Pony *pony_heap = new Pony;
	pony_heap->crying_sound();
	pony_heap->sleeping_sound();
    delete pony_heap;
}

void ponyOnTheStack ( void )
{
	std::cout << "========= stack pony ========" << std::endl;
    Pony pony_stack;
	pony_stack.crying_sound();
	pony_stack.sleeping_sound();
}

int main( void )
{
	ponyOnTheHeap();
	ponyOnTheStack();
}
