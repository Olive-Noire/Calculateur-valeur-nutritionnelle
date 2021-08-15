#ifndef DEF_ALIMENTS_HPP
#define DEF_ALIMENTS_HPP

#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <array>

namespace Conventions {

    constexpr char weightNotation{'g'};
    constexpr char nutrimentNotation{'g'};
    constexpr char caloriesNotation[5]{"kcal"};

    constexpr unsigned int nutrimentWeight{100};

}

enum class Nutriment_Type {PROTEINS = 0, LIPIDS, GLUCIDS, FIBERS, CALORIES, VITAMINS};
enum class Vitamin {A = 0, B1, B2, B3, B5, B6, B8, B9, B12, C, D, E, K};

template <Nutriment_Type Type> class Nutriment {

    public:

    Nutriment() = default;

    Nutriment(const Nutriment&) = default;
    Nutriment(Nutriment&&) noexcept = default;

    Nutriment(float q = 0) : quantity{q*(q > 0)} {}

    ~Nutriment() = default;

    bool Any() const { return quantity == 0; }
    float Quantity() const { return quantity; }

    Nutriment_Type GetType() const { return Type; }

    Nutriment& operator++(int) { quantity++; }
    Nutriment& operator++() { ++quantity; }

    Nutriment& operator--(int) { quantity--; }
    Nutriment& operator--() { --quantity; }

    friend Nutriment operator+(const Nutriment &l, const Nutriment &r) { return Nutriment{l.quantity+r.quantity}; }
    friend Nutriment operator-(const Nutriment &l, const Nutriment &r) { return Nutriment{l.quantity-r.quantity}; }

    Nutriment& operator+=(const Nutriment &n) {

        *this = *this+n;
        return *this;

    }

    Nutriment& operator-=(const Nutriment &n) {

        *this = *this-n;
        return *this;

    }

    friend bool operator<(const Nutriment &l, const Nutriment &r) { return l.quantity < r.quantity; }
    friend bool operator<=(const Nutriment &l, const Nutriment &r) { return l.quantity <= r.quantity; }

    friend bool operator>(const Nutriment &l, const Nutriment &r) { return l.quantity > r.quantity; }
    friend bool operator>=(const Nutriment &l, const Nutriment &r) { return l.quantity >= r.quantity; }

    friend bool operator==(const Nutriment &l, const Nutriment &r) { return l.quantity == r.quantity; }
    friend bool operator!=(const Nutriment &l, const Nutriment &r) { return l.quantity != r.quantity; }

    Nutriment& operator=(float q) {
        
        quantity = q*(q > 0);
        return *this;
        
    }

    Nutriment& operator=(const Nutriment&) = default;
    Nutriment& operator=(Nutriment&&) noexcept = default;

    friend std::ostream& operator<<(std::ostream &flux, const Nutriment &n) {

        switch(Type) {

            case Nutriment_Type::PROTEINS:
                flux << "Proteins";
            break;

            case Nutriment_Type::LIPIDS:
                flux << "Lipids";
            break;

            case Nutriment_Type::GLUCIDS:
                flux << "Glucids";
            break;

            case Nutriment_Type::FIBERS:
                flux << "Fibers";
            break;

            case Nutriment_Type::CALORIES:
                flux << "Calories";
            break;

        }

        flux << " : " << n.quantity << Conventions::nutrimentNotation;
        return flux;

    }

    private:

    float quantity;
    Nutriment_Type type;

};

template <> class Nutriment<Nutriment_Type::VITAMINS> {

    public:

    Nutriment() = default;

    Nutriment(const Nutriment&) = default;
    Nutriment(Nutriment&&) noexcept = default;

    Nutriment(bool b) : vitamins{b} {}

    ~Nutriment() = default;

    bool Any() const {

        for (bool b : vitamins) {

            if (b) {

                return false;

            }

        }

        return true;

    }

    bool Has(Vitamin v) const { return vitamins[static_cast<std::size_t>(v)]; }

    std::size_t Numbers() const {

        std::size_t num{0};
        for (bool b : vitamins) {

            if (b) num++;

        }

        return num;

    }

    bool operator[](Vitamin index) const { return vitamins[static_cast<std::size_t>(index)]; }
    bool& operator[](Vitamin index) { return vitamins[static_cast<std::size_t>(index)]; }

    friend bool operator<(const Nutriment &l, const Nutriment &r) { return l.Numbers() < r.Numbers(); }
    friend bool operator<=(const Nutriment &l, const Nutriment &r) { return l.Numbers() <= r.Numbers(); }

    friend bool operator>(const Nutriment &l, const Nutriment &r) { return l.Numbers() > r.Numbers(); }
    friend bool operator>=(const Nutriment &l, const Nutriment &r) { return l.Numbers() >= r.Numbers(); }

    friend bool operator==(const Nutriment &l, const Nutriment &r) { return l.vitamins == r.vitamins; }
    friend bool operator!=(const Nutriment &l, const Nutriment &r) { return l.vitamins != r.vitamins; }

    Nutriment& operator=(const Nutriment&) = default;
    Nutriment& operator=(Nutriment&&) noexcept = default;

    friend std::ostream& operator<<(std::ostream &flux, const Nutriment &n) {

        flux << "Vitamins : ";

        for (std::size_t i{0}; i < n.vitamins.size(); i++) {

            if (n.vitamins[i]) {

                switch (static_cast<Vitamin>(i)) {

                    case Vitamin::A:
                        flux << "A ";
                    break;

                    case Vitamin::B1:
                    case Vitamin::B2:
                    case Vitamin::B3:
                    case Vitamin::B5:
                    case Vitamin::B6:
                    case Vitamin::B8:
                    case Vitamin::B9:
                    case Vitamin::B12:
                        flux << 'B' << i-static_cast<std::size_t>(Vitamin::B1)+1 << ' ';
                    break;

                    case Vitamin::C:
                        flux << "C ";
                    break;

                    case Vitamin::D:
                        flux << "D ";
                    break;

                    case Vitamin::E:
                        flux << "E ";
                    break;

                    case Vitamin::K:
                        flux << "K ";
                    break;

                }

            }

        }

        return flux;

    }

    private:

    std::array<bool, 13> vitamins;

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

    float operator[](Nutriment_Type) const;

    template <Nutriment_Type Type> const Nutriment<Type>& GetNutriment() const;
    template <Nutriment_Type Type> Nutriment<Type>& GetNutriment();

    friend std::ostream& operator<<(std::ostream&, const Aliment&);

    std::string name;

    private:

    Nutriment<Nutriment_Type::PROTEINS> proteins;
    Nutriment<Nutriment_Type::LIPIDS> lipids;
    Nutriment<Nutriment_Type::GLUCIDS> glucids;
    Nutriment<Nutriment_Type::FIBERS> fibers;
    Nutriment<Nutriment_Type::CALORIES> calories;
    Nutriment<Nutriment_Type::VITAMINS> vitamins;

};

template <> inline const Nutriment<Nutriment_Type::PROTEINS>& Aliment::GetNutriment<Nutriment_Type::PROTEINS>() const { return proteins; }
template <> inline const Nutriment<Nutriment_Type::LIPIDS>& Aliment::GetNutriment<Nutriment_Type::LIPIDS>() const { return lipids; }
template <> inline const Nutriment<Nutriment_Type::GLUCIDS>& Aliment::GetNutriment<Nutriment_Type::GLUCIDS>() const { return glucids; }
template <> inline const Nutriment<Nutriment_Type::FIBERS>& Aliment::GetNutriment<Nutriment_Type::FIBERS>() const { return fibers; }
template <> inline const Nutriment<Nutriment_Type::CALORIES>& Aliment::GetNutriment<Nutriment_Type::CALORIES>() const { return calories; }
template <> inline const Nutriment<Nutriment_Type::VITAMINS>& Aliment::GetNutriment<Nutriment_Type::VITAMINS>() const { return vitamins; }

template <> inline Nutriment<Nutriment_Type::PROTEINS>& Aliment::GetNutriment<Nutriment_Type::PROTEINS>() { return proteins; }
template <> inline Nutriment<Nutriment_Type::LIPIDS>& Aliment::GetNutriment<Nutriment_Type::LIPIDS>() { return lipids; }
template <> inline Nutriment<Nutriment_Type::GLUCIDS>& Aliment::GetNutriment<Nutriment_Type::GLUCIDS>() { return glucids; }
template <> inline Nutriment<Nutriment_Type::FIBERS>& Aliment::GetNutriment<Nutriment_Type::FIBERS>() { return fibers; }
template <> inline Nutriment<Nutriment_Type::CALORIES>& Aliment::GetNutriment<Nutriment_Type::CALORIES>() { return calories; }
template <> inline Nutriment<Nutriment_Type::VITAMINS>& Aliment::GetNutriment<Nutriment_Type::VITAMINS>() { return vitamins; }

namespace Data_Base {

    extern std::vector<Aliment> aliments;

}

#endif // DEF_ALIMENTS_HPP