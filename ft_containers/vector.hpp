namespace ft
{
	template < class T, class Alloc = allocator<T> >
	class vector{
		private:
			//Member types
			typedef T											value_type; //T
			typedef Alloc										allocator_type;

			allocator_type::reference			reference; //	T&
			allocator_type::const_reference		const_reference; //   	const T&
			allocator_type::pointer				pointer; //    	T*
			allocator_type::const_pointer		const_pointer; //    	const T*
			template <typename Spe>
			class iterator // 이거 만들어야함. 
			{
				private:

				public:
			}
		public:

	}
}
