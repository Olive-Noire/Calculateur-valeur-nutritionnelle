#ifndef DEF_RECIPE_HPP
#define DEF_RECIPE_HPP

#include "./Aliments.hpp"

struct Ingredient {

    public:

    unsigned int quantity{0};
    Aliment aliment;

};

class Recipe {

    public:

    Recipe(const Recipe&) = default;
    Recipe(Recipe&&) noexcept = default;

    Recipe(const std::string& = "unamed");

    ~Recipe() = default;

    bool Empty() const;
    bool Unique() const;

    std::size_t Size() const;

    friend Recipe operator+(const Recipe&, const Recipe&);
    Recipe& operator+=(const Recipe&);

    friend bool operator==(const Recipe&, const Recipe&);
    friend bool operator!=(const Recipe&, const Recipe&);

    Recipe& operator=(const Recipe&) = default;
    Recipe& operator=(Recipe&&) noexcept = default;

    const Aliment& operator[](std::size_t) const;
    Aliment& operator[](std::size_t);

    friend std::ostream& operator<<(std::ostream&, const Recipe&);

    private:

    std::string name;
    std::vector<Ingredient> ingredients;

};

#endif // DEF_RECIPE_HPP