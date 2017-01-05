#ifndef _CPPAPPENDIX_H_

#define _CPPAPPENDIX_H_

#include <vector>

template<typename T>int IndexOf(std::vector<T> &vec, T el)
{
	return find(vec.begin(), vec.end(), el) - vec.begin();
}


#endif // !_CPPAPPENDIX_H_
