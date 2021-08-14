#ifndef DEF_RECIPE_HPP
#define DEF_RECIPE_HPP

#include <vector>

#include "./Aliments.hpp"

class Recipe {

    public:

    Recipe() = default;

    Recipe(const Recipe&) = default;
    Recipe(Recipe&&) noexcept = default;

    ~Recipe() = default;

    Recipe& operator=(const Recipe&) = default;
    Recipe& operator=(Recipe&&) noexcept = default;

    const Aliment& operator[](std::size_t) const;
    Aliment& operator[](std::size_t);

    private:
    std::vector<Aliment> ingredients;

};

#endif // DEF_RECIPE_HPP