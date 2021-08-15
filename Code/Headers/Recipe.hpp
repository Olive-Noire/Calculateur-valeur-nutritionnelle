#ifndef DEF_RECIPE_HPP
#define DEF_RECIPE_HPP

#include <iostream>

#include "./Aliments.hpp"

using Ingredient = std::pair<Aliment, unsigned int>; // <Aliment, quantity (in 'g')>

class Recipe {

    public:

    Recipe(const Recipe&) = default;
    Recipe(Recipe&&) noexcept = default;

    Recipe(const std::string& = "unamed");

    ~Recipe() = default;

    bool Empty() const;
    bool Unique() const;

    bool Has(const Aliment&) const;

    unsigned int Get(const Aliment&) const;
    unsigned int& Get(const Aliment&);

    void Remove(const Aliment&);

    std::size_t Size() const;

    template <Nutriment_Type Type> float GetNutrimentTotal() const {

        float total{0};
        for (const Ingredient &i : ingredients) {

            total += i.first.GetNutriment<Type>().Quantity()*(static_cast<double>(i.second)/Conventions::nutrimentWeight);

        }

        return total;

    }

    friend Recipe operator+(const Recipe&, const Ingredient&);
    Recipe& operator+=(const Ingredient&);

    friend Recipe operator+(const Recipe&, const Recipe&);
    Recipe& operator+=(const Recipe&);

    friend bool operator==(const Recipe&, const Recipe&);
    friend bool operator!=(const Recipe&, const Recipe&);

    Recipe& operator=(const Recipe&) = default;
    Recipe& operator=(Recipe&&) noexcept = default;

    const Ingredient& operator[](std::size_t) const;

    friend std::ostream& operator<<(std::ostream&, const Recipe&);

    std::string name;

    private:

    std::vector<Ingredient> ingredients;

};

#endif // DEF_RECIPE_HPP