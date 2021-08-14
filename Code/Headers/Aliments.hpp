#ifndef DEF_ALIMENTS_HPP
#define DEF_ALIMENTS_HPP

namespace Conventions {

    constexpr char weightNotation{'g'};
    constexpr char nutrientNotation{'g'};
    constexpr char caloriesNotation[5]{"kcal"};

    constexpr unsigned int nutrientWeight{100};

}

enum Nutrient_Index {PROTEINS = 0, LIPIDS, GLUCIDS, FIBERS, CALORIES, VITAMINS};

class Aliment {

    public:

    Aliment();

    Aliment(const Aliment&) = default;
    Aliment(Aliment&&) noexcept = default;

    Aliment(float);
    Aliment(float, float, float, float, float, float);

    ~Aliment() = default;

    Aliment& operator=(const Aliment&) = default;
    Aliment& operator=(Aliment&&) noexcept = default;

    float operator[](Nutrient_Index) const;
    float& operator[](Nutrient_Index);

    private:
    float proteins, lipids, glucids, fibers, calories, vitamins;

};

#endif // DEF_ALIMENTS_HPP