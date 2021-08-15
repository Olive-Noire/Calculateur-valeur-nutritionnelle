#include "../Headers/Recipe.hpp"

int main() {

    Recipe test{"Salad bowl"};

    Aliment salad{"Salad", 1.36, 0.15, 2.87, 1.3, 15};
    Aliment thon{"Thon", 23.33, 4.19, 0, 0, 111};
    Aliment carott{"Carrote", 0.93, 0.24, 9.58, 2.44, 41};

    test += Ingredient{salad, 100};
    test += Ingredient{thon, 150};
    test += Ingredient{carott, 200};

    std::cout << test;

    std::cin.get();

    return 0;

}