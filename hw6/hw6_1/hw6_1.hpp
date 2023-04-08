#include <algorithm>
#include <cstdbool>
#include <iostream>
#include <memory>
#include <set>
#include <vector>

#ifndef ITEM_HPP
#define ITEM_HPP

using namespace std;
class Menu;
class Delivery;
class Restaurant;
class Owner;
class Order;
class Customer;
class Cart;


// represents a food or drink item that can be ordered, displayed on a menu, and delivered
class Item {

public:
  string name;
  int price;
  // JPG image ;
  // sides that comee with the food
  vector<Item> sides;
  // optional add ons, for example making a chicken burrito with more chicken
  vector<Item> addOns;
  // the resturant assoiated with the item
  Restaurant *rest;
  // the menu associates with the item
  Menu *menu;
  // the owner whose made the food
  Owner *owner;

// constructor
  Item(string name, int price, vector<Item> sides, vector<Item> addOns,
       Restaurant rest, Menu menu, Owner owner);

  virtual ~Item(){};

  // list off commmon foods that are allrgies, found in the food
  virtual vector<string> allergies() const;
  // list off the ingredients in the food to help identify allergies
  virtual vector<string> ingredients() const;
  // the description of the item
  virtual vector<string> description() const;

  // makes a new item for the user with the added on items
  virtual Item addOnItem(vector<Item> item);

// displays the contents of the item
  static void display_Item_info(Item *item);
};

class Menu {

public:
  string name;
  // list of items
  vector<Item> items;
  // restuaant associated with it
  Restaurant *rest;
  // owner associated with it
  Owner *owner;

  Menu(string name, vector<Item> items, Restaurant rest, Owner owner);

  virtual ~Menu(){};

// adds item to menu
  virtual void addItem(Item *item);
  // adds menu to resturant
  virtual void addMenuToResturant(Restaurant *res);
  // remove menu
  virtual void rmoveMenuToResturant();
  // the description of menu
  virtual vector<string> description() const;
// displays description of menu
  static void display_Menu_info(Menu *Menu);
};

class Restaurant {

public:
  string name;
  string address;
  int opening_time;
  int closing_time;

  vector<Order> orders;
  Menu menu;
  Owner *owner;


  Restaurant(string name, string address, int opening_time, int closing_time,
             Menu menu, Owner owner);

  virtual ~Restaurant(){};

// adds a menu to the resturant
  virtual void addMenu(Menu *menu);
  // adds an item to the menu
  virtual void addItemToMenu(Item *item);
  // establishes a new owner for a shop
  virtual void addResturantToOwner(Owner *owner);
  // the description of resturant
  virtual vector<string> description() const;

  static void display_Resturant_info(Restaurant *res);
};

class Delivery {

public:
  string address;
  Customer *user;
  bool deliveryStatus;
  string driverName;
  int timeToDelivery; //
  int orderID;

public:
  Delivery(string address, string driverName, Customer user, int orderID);

  virtual ~Delivery(){};
  // was the delivery made
  virtual bool deliveryOrderMade() const;
  // preforms stuff to remove order from customers stuff
  virtual void delivered() const;
  // has the resurant finished making it and gave food to driver
  virtual bool pickedUpFromShop() const;
  // outputs delivery info to user and shop
  static void display_delivery_info(Delivery *del);
};

class Owner {

public:
  string name;
  string location;
  Restaurant res;
  vector<Order> orders;

public:
  Owner(string name, string location, Restaurant res, vector<Order> orders);

  virtual ~Owner(){};

// updates the resturant that they owns data
  virtual void setResturantTime(int time, int tiem2);
  virtual void removeItems(Item *item);
  virtual void cancelOrder(Order *order);
  virtual void editMenu(Item *item);
  virtual void editMenu(Menu *menu);
  virtual void addItem(Item *item);
};

class Order {

public:
  int orderID;
  Customer *cus;
  Restaurant res;
  vector<Item> items;

public:
  Order(int orderID, Customer cus, Restaurant res, vector<Item> items);

  virtual ~Order(){};

  // the items in an order outputted
  virtual vector<Item> getItems(Order *order);

  // sets data into customers account
  virtual void addOrderToCustomerFavorite();
};


class Customer {

public:
  string name;
  string address;
  vector<Item> favFoods;
  vector<Restaurant> favRes;
  Cart *cart;

public:
  Customer(string name, string address);

  virtual ~Customer(){};

  // updates a customers cart
  virtual void addItem(Item *item);
  virtual void removeItems(Item *item);

  virtual Item editItem(Item *item);
  virtual void chooseDeliveryType(string type);
};

class Cart {

public:
  Customer cus;
  Restaurant res;
  Menu menu;

public:
  Cart(Customer cus, Restaurant res, Menu menu);

  virtual ~Cart(){};

// updates a cart
  virtual void addItem(Item *item);
  virtual void removeItems(Item *item);

  virtual Item editItem(Item *item);

  virtual string displayOrder();
  virtual string displayAmount();
  virtual int displayCost();
  virtual void checkout();
};

#endif