#include <boost/mp11.hpp>
#include <boost/core/demangle.hpp>
#include <type_traits>
#include <iostream>
#include <typeinfo>

using namespace boost::mp11;

template<class T> std::string name()
{
    return boost::core::demangle( typeid(T).name() );
}

template<class T> using promote = typename std::common_type<T, int>::type;

template<class T, class U> using result =
    typename std::common_type<promote<T>, promote<U>>::type;

template<class T1, class T2> void test_result( mp_list<T1, T2> const& )
{
    using T3 = decltype( T1() + T2() );
    using T4 = result<T1, T2>;

    std::cout << ( std::is_same<T3, T4>::value? "[PASS] ": "[FAIL] " )
        << name<T1>() << " + " << name<T2>() << " -> " << name<T3>()
        << ", result: " << name<T4>() << std::endl;
}

int main()
{
    using L = std::tuple<char, short, int, unsigned, long, unsigned long>;
    tuple_for_each( mp_product<mp_list, L, L>(), [](auto&& x){ test_result(x); } );
}

