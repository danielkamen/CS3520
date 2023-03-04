#include <cstring>
#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <limits>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <cstdlib>


using namespace std;

int main(void) {
    cout << "START!" << endl;
    double randomValue = rand() % 1000 + 1;

    // instantiates the list of items and the stores we wanna see

    vector<string> items;
    items.push_back("iP14");
    items.push_back("IPad");
    items.push_back("Nois");
    items.push_back("Back");
    items.push_back("Bike" );

    vector<string> stores; 
    stores.push_back("BestBuy");
    stores.push_back("Amazon");
    stores.push_back("eBay");
    stores.push_back("OfficeMax");
    stores.push_back("Staples");
    

    // map of (item: (map of store to price))
    // map <string, map<string, double>>

    // represents a map of:
    // eg
    // headphones: bestBuy 12
    // headphones: apple 13



    map<string, map<string, double> > blackFridayWishList;

    // insntaniates random values to each stores item price
    for (int i = 0; i < items.size(); i++) {
        for (int s = 0; s < stores.size(); s++) {
            double randomValue = rand() % 1000 + 1;
            blackFridayWishList[items[i]][stores[s]] = randomValue;
        }
    }

// since the order of items are now different, get the items from nested map and update list
vector<string> newItems;
vector<string> newStores;

for (const auto& itemStorePair : blackFridayWishList) {
    const string& item = itemStorePair.first;
    newItems.push_back(item);
    for (const auto& storePricePair : itemStorePair.second) {
        const string& store = storePricePair.first;
        if (find(newStores.begin(), newStores.end(), store) == newStores.end()) {
            newStores.push_back(store);
        }
    }
}

sort(newItems.begin(), newItems.end());
sort(newStores.begin(), newStores.end());

items = newItems;
stores = newStores;

cout<<"table of each store and the items & prices of every item I want to buy"<<endl;
// header for the first print section
cout << "Name: ";
for (int i = 0; i < stores.size(); i++) {
    cout << stores[i] << " ";
}
cout<<endl;



    // displays the rows of data ex
    // iphone  1300 2000 200 2 2000
    // hedaphones  1300 2000 200 2 2000
    for (auto const& item : blackFridayWishList) {
        cout << item.first << "  ";
        for (auto const& storez : item.second) {
            cout << storez.second << "   ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;


cout<<"breakdown of each store's items that are on my wishlist"<<endl;
for (const auto& store : stores) {
    cout << "Name: " << store << endl;
    for (const auto& item : items) {
        if (blackFridayWishList.count(item) && blackFridayWishList[item].count(store)) {
            double price = blackFridayWishList[item][store];
            cout << item << ": $" << price << endl;
        }
    }
    cout << endl; 
}
        cout << endl;
        cout << endl;

cout << "Average Cost of each item across all stores using ***lambdas***" << endl;
auto printAverage = [](const pair<string, map<string, double>>& item) {
    double totalMoneys = 0;
    int n_stores_that_carry_item = 0;
    int avg = 0;

    for (auto const& storez : item.second) {
        totalMoneys += storez.second;
        n_stores_that_carry_item++;
    }

    avg = totalMoneys / n_stores_that_carry_item;
    cout << item.first << " Avg: $" << avg << endl;
};

for_each(blackFridayWishList.begin(), blackFridayWishList.end(), printAverage);

cout<<endl;
cout<<endl;


// Iterate over items and stores
cout<<"Best place to buy each item, and for how much, with ***lambdas***"<<endl;
for (const auto& item : items) {
    string bestStore;
    double bestPrice = numeric_limits<double>::max();

    // Find the store with the best price for the current item
    for_each(stores.begin(), stores.end(), [&](const string& store) {
        // Check if the store carries the item
        if (blackFridayWishList[item].count(store)) {
            // Check if the price is lower than the current best price
            if (blackFridayWishList[item][store] < bestPrice) {
                bestPrice = blackFridayWishList[item][store];
                bestStore = store;
            }
        }
    });

    // Print the best store and price for the current item
    cout << "Best store for " << item << ": " << bestStore << ", for $" << bestPrice << endl;
}

    return 0;
}