#pragma once
//#include <compare>                                                            // std::weak_ordering
#include <iostream>
#include <string>
class Snack
{
  // Insertion and Extraction Operators
  friend std::ostream & operator<<( std::ostream & stream, Snack const & snackItem );
  friend std::istream & operator>>( std::istream & stream, Snack       & snackItem );

  public:
    // Constructors, assignments, and destructor
    Snack( std::string productName = {},                                // Default and Conversion (from string to GroceryItem) constructor
                 std::string brandName   = {},                                // String parameters intentionally passed by value.  Not perfect, but very very
                 std::string upcCode     = {},
                 std::string vendingNum   = {},
                 int quantity = 0,                                // good when combined with move semantics. 
                 double      price       = 0.0 );

    Snack & operator=( Snack const  & rhs   ) &;                  // Assignment operators available only for l-values (that's what the trailing "&" means), and then
    Snack & operator=( Snack       && rhs   ) & noexcept;         // the 'Rule of 5' says if you define one, then you should define them all
    Snack            ( Snack const  & other );                    // OK:  GroceryItem a{"title"},b;  b = a;  (a and b are both l-values, i.e. named objects)
    Snack            ( Snack       && other )   noexcept;         // Error:  GroceryItem{} = a;              (GroceryItem{} is an r-value, i.e., an unnamed temporary object)
   ~Snack           (                            )   noexcept;


    // Accessors
    std::string const & upcCode    () const &;                                // Returns object's state by constant reference for l-value objects and by value for r-value objects
    std::string const & brandName  () const &;                                // The "const &" at the end says these functions will be called for l-value objects and r-value objects
    std::string const & productName() const &;
    std::string const & vendingNum() const &;
    int quantity () const &;                                // that (listen carefully) haven't been overloaded.
    double              price      () const &;                                //
                                                                              //
    std::string         upcCode    ()       &&;                               // Overloads that return an r-value object's state by value (unsafe to return an r-value's state by reference)
    std::string         brandName  ()       &&;                               // The "&&" at the end says these functions will be called only for r-value objects
    std::string         productName()       &&;
    std::string         vendingNum()       &&;                               
                                                                              

    // Modifiers                                                              // Updates object's state and returns a reference to self (enables chaining)
    Snack & upcCode    ( std::string newUpcCode     ) &;                // String parameters intentionally passed by value
    Snack & brandName  ( std::string newBrandName   ) &;                // Modifiers available for l-values only         (The & at the end says these functions will be called only for l-values)
    Snack & productName( std::string newProductName ) &;
    Snack & vendingNum    ( std::string newVendingNum     ) &;
    Snack & quantity (int newQuantity) &;                // OK:     GroceryItem b; b.price(13.99);        (b is an l-value, i.e. a named object)
    Snack & price      ( double      newPrice       ) &;                // Error:  GroceryItem{}.price(13.99);           (The default constructed GrocerItem is an r-value, i.e., an unnamed temporary object)

    bool               operator== ( Snack const & rhs ) const noexcept;

  private:
    std::string _upcCode;                                                     // a 12 or 14-digit international Universal Product Code uniquely identifying this item (Ex: 051600080015, 05017402006207)
    std::string _brandName;                                                   // the product manufacturer's brand name (Ex: Heinz, Boston Market)
    std::string _productName;
    std::string _vendingNum;
    int _quantity = 0.0;                                                 // the name of the product (Ex: Heinz Tomato Ketchup - 2 Ct, Boston Market Spaghetti With Meatballs)
    double      _price = 0.0;                                                 // the cost of the item in US Dollars (Ex:  2.29, 1.19)
};