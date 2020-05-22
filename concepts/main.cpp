//
// Created by pierreantoine on 09/01/2020.
//

template <typename T>
concept bool SymbolCollector() {
    return requires (T collector) {
        { collector.lookup("") -> symbol }
    };
}

// hello-concepts.cpp
template<typename T>
requires true   // True concept
struct Foo
{};

template<typename T>
requires false  // False concept
struct Bar
{};

int main()
{
    Foo<int>(); // Ok
    return 0;
}