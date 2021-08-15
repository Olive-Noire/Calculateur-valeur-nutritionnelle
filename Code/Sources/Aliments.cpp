#include "../Headers/Aliments.hpp"

#include <stdexcept>
#include <cassert>

Aliment::Aliment(const std::string &n, float p, float l, float g, float f, float c) :

    name{n},
    proteins{p*(p > 0)},
    lipids{l*(l > 0)},
    glucids{g*(g > 0)},
    fibers{f*(f > 0)},
    calories{c*(c > 0)},
    vitamins{false}

{}

bool operator==(const Aliment &l, const Aliment &r) {

    return
        l.proteins == r.proteins &&
        l.lipids == r.lipids &&
        l.glucids == r.glucids &&
        l.fibers == r.fibers &&
        l.calories == r.calories &&
        l.vitamins == r.vitamins;

}

bool operator!=(const Aliment &l, const Aliment &r) { return !(l == r); }

float Aliment::operator[](Nutriment_Type index) const {

    assert(index != Nutriment_Type::VITAMINS && "Can't return vitamins array in float");

    switch(index) {

        case Nutriment_Type::PROTEINS:
            return proteins.Quantity();
        break;

        case Nutriment_Type::LIPIDS:
            return lipids.Quantity();
        break;

        case Nutriment_Type::GLUCIDS:
            return glucids.Quantity();
        break;

        case Nutriment_Type::FIBERS:
            return fibers.Quantity();
        break;

        case Nutriment_Type::CALORIES:
            return calories.Quantity();
        break;

        default:
            throw std::runtime_error{"Error : Nutriment index no valid"};
        break;

    }

}

std::ostream& operator<<(std::ostream &flux, const Aliment &a) {

    flux << a.name << " (pour " << Conventions::nutrimentWeight << Conventions::weightNotation << ") :\n";

    flux <<
        a.proteins << std::endl <<
        a.lipids << std::endl <<
        a.glucids << std::endl <<
        a.fibers << std::endl <<
        a.calories << std::endl <<
        a.vitamins;

    return flux;

}