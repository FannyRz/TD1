#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;
    int hash()const;
};

bool operator==(Card const& c1, Card const& c2){
    return c1.kind == c2.kind && c1.value == c2.value ;
}

int Card::hash() const{
    return (static_cast<int>(this->value)+1) * (static_cast<int>(this->kind)+1);
}

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
        name += '0' + card_value;
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'V';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}

int main(){

    Card myCard {CardKind::Spade, CardValue::Ace};
    std::cout << myCard.hash() << std::endl;

    std::vector<Card> listRandomCard {get_cards(100)};
    std::unordered_map<Card,int> numberOfCard {};

    for(Card element : listRandomCard){
        numberOfCard[element] = numberOfCard[element] + 1;
    }
    
    for(auto element : numberOfCard){ 
        std::cout << "Il y a " << element.second << " cartes de " << card_name(element.first) << std::endl;
    }
    
    return 0;
}