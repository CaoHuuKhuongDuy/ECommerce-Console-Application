#include "customerRanking.h"

string CustomerRankingNormal::getCustomerRankingName() {
    return "Normal";
}

double CustomerRankingNormal::calculateDiscount() {
    return 1;
}

string CustomerRankingBronze::getCustomerRankingName() {
    return "Bronze";
}

double CustomerRankingBronze::calculateDiscount() {
    return 0.99;
}

string CustomerRankingSilver::getCustomerRankingName() {
    return "Silver";
}

double CustomerRankingSilver::calculateDiscount() {
    return 0.98;
}

string CustomerRankingGold::getCustomerRankingName() {
    return "Gold";
}

double CustomerRankingGold::calculateDiscount() {
    return 0.96;
}

