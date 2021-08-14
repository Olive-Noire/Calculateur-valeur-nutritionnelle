#include "../Headers/Aliments.hpp"

#include <stdexcept>
#include <iostream>
#include <cassert>

Aliment::Aliment(const std::string &n, float p, float l, float g, float f, float c) :

    proteins{p*(p > 0)},
    lipids{l*(l > 0)},
    glucids{g*(g > 0)},
    fibers{f*(f > 0)},
    calories{c*(c > 0)},
    vitamins{false},
    name{n}

{}

float Aliment::operator[](Nutrient_Index index) const {

    assert(index != Nutrient_Index::VITAMINS && "Can't return vitamins array in float");

    switch(index) {

        case Nutrient_Index::PROTEINS:
            return proteins;
        break;

        case Nutrient_Index::LIPIDS:
            return lipids;
        break;

        case Nutrient_Index::GLUCIDS:
            return glucids;
        break;

        case Nutrient_Index::FIBERS:
            return fibers;
        break;

        case Nutrient_Index::CALORIES:
            return calories;
        break;

        default:
            throw std::runtime_error{"Error : Nutrient index no valid"};
        break;

    }

}

float& Aliment::operator[](Nutrient_Index index) {

    assert(index != Nutrient_Index::VITAMINS && "Can't return vitamins array in float");

    switch(index) {

        case Nutrient_Index::PROTEINS:
            return proteins;
        break;

        case Nutrient_Index::LIPIDS:
            return lipids;
        break;

        case Nutrient_Index::GLUCIDS:
            return glucids;
        break;

        case Nutrient_Index::FIBERS:
            return fibers;
        break;

        case Nutrient_Index::CALORIES:
            return calories;
        break;

        default:
            throw std::runtime_error{"Error : Nutrient index no valid"};
        break;

    }

}

std::ostream& operator<<(std::ostream &flux, const Aliment &a) {

    flux << a.name << " (pour " << Conventions::nutrientWeight << Conventions::weightNotation << ") :\n";

    flux <<
        "Proteins : " << a.proteins << Conventions::nutrientNotation <<
        "\nLipids : " << a.lipids << Conventions::nutrientNotation <<
        "\nGlucids : " << a.glucids << Conventions::nutrientNotation <<
        "\nFibers : " << a.fibers << Conventions::nutrientNotation <<
        "\nCalories : " << a.calories << Conventions::caloriesNotation <<
        "\nVitamins : ";

    for (std::size_t i{0}; i < static_cast<std::size_t>(Vitamin::SIZE); i++) {

        if (a.vitamins[i]) {

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

                default:
                break;

            }

        }

    }

    return flux;

}