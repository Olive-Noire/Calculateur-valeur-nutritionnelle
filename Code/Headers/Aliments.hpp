#ifndef DEF_ALIMENTS_HPP
#define DEF_ALIMENTS_HPP

#include <iosfwd>
#include <string>
#include <array>

namespace Conventions {

    constexpr char weightNotation{'g'};
    constexpr char nutrientNotation{'g'};
    constexpr char caloriesNotation[5]{"kcal"};

    constexpr unsigned int nutrientWeight{100};

}

enum Nutrient_Index : std::size_t {PROTEINS = 0, LIPIDS, GLUCIDS, FIBERS, CALORIES, VITAMINS};
enum class Vitamin {A = 0, B1, B2, B3, B5, B6, B8, B9, B12, C, D, E, K, SIZE};

class Aliment {

    public:

    Aliment(const Aliment&) = default;
    Aliment(Aliment&&) noexcept = default;

    Aliment(const std::string& = "unamed", float = 0, float = 0, float = 0, float = 0, float = 0);

    ~Aliment() = default;

    Aliment& operator=(const Aliment&) = default;
    Aliment& operator=(Aliment&&) noexcept = default;

    float operator[](Nutrient_Index) const;
    float& operator[](Nutrient_Index);

    friend std::ostream& operator<<(std::ostream&, const Aliment&);

    private:

    float proteins, lipids, glucids, fibers, calories;
    std::array<bool, static_cast<std::size_t>(Vitamin::SIZE)> vitamins;

    std::string name;

};

#endif // DEF_ALIMENTS_HPP