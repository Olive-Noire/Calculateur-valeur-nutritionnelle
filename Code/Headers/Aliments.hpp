#ifndef DEF_ALIMENTS_HPP
#define DEF_ALIMENTS_HPP

#include <iosfwd>
#include <string>
#include <vector>
#include <array>

namespace Conventions {

    constexpr char weightNotation{'g'};
    constexpr char nutrientNotation{'g'};
    constexpr char caloriesNotation[5]{"kcal"};

    constexpr unsigned int nutrientWeight{100};

}

enum class Nutrient_Type {PROTEINS = 0, LIPIDS, GLUCIDS, FIBERS, CALORIES, VITAMINS};
enum class Vitamin {A = 0, B1, B2, B3, B5, B6, B8, B9, B12, C, D, E, K, SIZE};

class Nutrient {

    public:

    Nutrient();

    Nutrient(const Nutrient&) = default;
    Nutrient(Nutrient&&) noexcept = default;

    Nutrient(Nutrient_Type, float = 0);

    ~Nutrient() = default;

    bool Any() const;
    float Quantity() const;

    Nutrient_Type Type() const;

    Nutrient& operator++(int);
    Nutrient& operator++();

    Nutrient& operator--(int);
    Nutrient& operator--();

    friend Nutrient operator+(const Nutrient&, const Nutrient&);
    friend Nutrient operator-(const Nutrient&, const Nutrient&);

    Nutrient& operator+=(const Nutrient&);
    Nutrient& operator-=(const Nutrient&);

    friend bool operator<(const Nutrient&, const Nutrient&);
    friend bool operator<=(const Nutrient&, const Nutrient&);

    friend bool operator>(const Nutrient&, const Nutrient&);
    friend bool operator>=(const Nutrient&, const Nutrient&);

    friend bool operator==(const Nutrient&, const Nutrient&);
    friend bool operator!=(const Nutrient&, const Nutrient&);

    Nutrient& operator=(float);

    Nutrient& operator=(const Nutrient&) = default;
    Nutrient& operator=(Nutrient&&) noexcept = default;

    private:

    float quantity;
    Nutrient_Type type;

};

class Aliment {

    public:

    Aliment(const Aliment&) = default;
    Aliment(Aliment&&) noexcept = default;

    Aliment(const std::string& = "unamed", float = 0, float = 0, float = 0, float = 0, float = 0);

    ~Aliment() = default;

    friend bool operator==(const Aliment&, const Aliment&);
    friend bool operator!=(const Aliment&, const Aliment&);

    Aliment& operator=(const Aliment&) = default;
    Aliment& operator=(Aliment&&) noexcept = default;

    float operator[](Nutrient_Type) const;

    friend std::ostream& operator<<(std::ostream&, const Aliment&);

    private:

    Nutrient proteins, lipids, glucids, fibers, calories;
    std::array<bool, static_cast<std::size_t>(Vitamin::SIZE)> vitamins;

    std::string name;

};

namespace Data_Base {

    extern std::vector<Aliment> aliments;

}

#endif // DEF_ALIMENTS_HPP