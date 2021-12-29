#include <iostream>
class dummy {
public:
dummy() { std::cout<<"2"<<std::endl; }
dummy(int) { std::cout<<"ctor"<<std::endl; }
~dummy() { std::cout<<"dtor"<<std::endl; }
};


int main(void)
{
//std::allocator <dummy> alloc;
//
//dummy *p = alloc.allocate(sizeof(dummy));
//alloc.construct(p, dummy());
//alloc.construct(p, dummy(0));
////
//	std::allocator<dummy> alloc;
//
//dummy *p = alloc.allocate(sizeof(dummy));
//alloc.construct(p, dummy());
//
	std::allocator<dummy> alloc;

	dummy *p = alloc.allocate(sizeof(dummy));
	alloc.construct(p, dummy(0));
	alloc.destroy(p);
	alloc.deallocate(p, sizeof(dummy)); 


	return(0);
}

//construct 와 allocate는 container 의 reserve와 resize 를 생각하면 이해하기 쉬움

//reserve : 생성자를 호출하지 않고 사이즈 만큼 공간을 예약 ( allocate )만 해둠

//resize : 사이즈만큼 공간을 할당 ( allocate ) 하고, 사이즈만큼 생성자 ( construct ) 를 호출함
