#include "../Headers/Recipe.hpp"

bool operator==(const Ingredient &l, const Ingredient &r) { return l.quantity == r.quantity && l.aliment == r.aliment; }
bool operator!=(const Ingredient &l, const Ingredient &r) { return !(l == r); }

bool Recipe::Empty() const { return ingredients.empty(); }
bool Recipe::Unique() const { return Size() == 1; }
std::size_t Recipe::Size() const { return ingredients.size(); }

Recipe operator+(const Recipe &l, const Recipe &r) {

    Recipe tmp{l};
    for (const Ingredient& i : r.ingredients) {

        tmp.ingredients.push_back(i);

    }

    return tmp;

}

Recipe& Recipe::operator+=(const Recipe &r) {

    for (const Ingredient& i : r.ingredients) {

        ingredients.push_back(i);

    }

    return *this;

}

bool operator==(const Recipe &l, const Recipe &r) { return l.ingredients == r.ingredients; }
bool operator!=(const Recipe &l, const Recipe &r) { return !(l == r); }

const Ingredient& Recipe::operator[](std::size_t index) const { return ingredients[index]; }
Ingredient& Recipe::operator[](std::size_t index) { return ingredients[index]; }

std::ostream& operator<<(std::ostream &flux, const Recipe &r) {

    return flux;

}