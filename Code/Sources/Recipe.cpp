#include "../Headers/Recipe.hpp"

Recipe::Recipe(const std::string &n) : name{n} {}

bool Recipe::Empty() const { return ingredients.empty(); }
bool Recipe::Unique() const { return Size() == 1; }

bool Recipe::Has(const Aliment &a) const {

    for (const Ingredient &i : ingredients) {

        if (a == i.first) {

            return true;

        }

    }

    return false;

}

unsigned int Recipe::Get(const Aliment &a) const {

    for (const Ingredient &i : ingredients) {

        if (a == i.first) {

            return i.second;

        }

    }

    return 0;

}

unsigned int& Recipe::Get(const Aliment &a) {

    for (Ingredient &i : ingredients) {

        if (a == i.first) {

            return i.second;

        }

    }

    ingredients.push_back(Ingredient{a, 0});
    return ingredients.back().second;

}

void Recipe::Remove(const Aliment &a) {

    for (std::size_t i{0}; i < ingredients.size(); i++) {

        if (ingredients[i].first == a) {

            ingredients.erase(ingredients.begin()+i);

        }

    }

}

std::size_t Recipe::Size() const { return ingredients.size(); }

Recipe operator+(const Recipe &r, const Ingredient &i) {

    Recipe tmp{r};
    tmp.Get(i.first) += i.second;

    return tmp;

}

Recipe& Recipe::operator+=(const Ingredient &i) {

    Get(i.first) += i.second;
    return *this;

}

Recipe operator+(const Recipe &l, const Recipe &r) {

    Recipe tmp{l};

    for (const Ingredient &i : r.ingredients) {

        tmp.Get(i.first) += r.Get(i.first);

    }

    return tmp;

}

Recipe& Recipe::operator+=(const Recipe &r) {

    for (const Ingredient &i : r.ingredients) {

        Get(i.first) += r.Get(i.first);

    }

    return *this;

}

bool operator==(const Recipe &l, const Recipe &r) { return l.ingredients == r.ingredients; }
bool operator!=(const Recipe &l, const Recipe &r) { return !(l == r); }

const Ingredient& Recipe::operator[](std::size_t index) const { return ingredients[index]; }

std::ostream& operator<<(std::ostream &flux, const Recipe &r) {

    flux << r.name << " : \n";

    for (const Ingredient &i : r.ingredients) {

        flux << "- " << i.first.name << " (" << i.second << Conventions::weightNotation << ")\n";

    }

    flux << std::endl;

    flux << 
        "Proteins : " << r.GetNutrimentTotal<Nutriment_Type::PROTEINS>() << Conventions::nutrimentNotation <<
        "\nLipids : " << r.GetNutrimentTotal<Nutriment_Type::LIPIDS>() << Conventions::nutrimentNotation <<
        "\nGlucids : " << r.GetNutrimentTotal<Nutriment_Type::GLUCIDS>() << Conventions::nutrimentNotation <<
        "\nFibers : " << r.GetNutrimentTotal<Nutriment_Type::FIBERS>() << Conventions::nutrimentNotation <<
        "\nCalories : " << r.GetNutrimentTotal<Nutriment_Type::CALORIES>() << ' ' << Conventions::caloriesNotation;

    return flux;

}