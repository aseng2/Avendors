#include <cmath>                                                      // abs(), pow()
//#include <compare>                                                    // weak_ordering
#include <iomanip>                                                    // quoted(), ios::failbit
#include <iostream>                                                   // istream, ostream, ws()
#include <string>
#include <type_traits>                                                // is_floating_point_v, common_type_t
#include <utility>                                                    // move()

#include "Snack.hpp"

// Default and Conversion Constructor
Snack::Snack( std::string productName, std::string brandName, std::string upcCode, std::string vendingNum, int quantity, double price )
  ///////////////////////// TO-DO (2) //////////////////////////////
  /// Copying the parameters into the object's attributes (member variables) "works" but is not correct.  Be sure to move the parameters into the object's attributes
  : _upcCode( std::move( upcCode ) ), _brandName( std::move( brandName ) ), _productName( std::move( productName ) ), _vendingNum( std::move( vendingNum ) ), _quantity(std::move(quantity)), _price( std::move( price ) )
{}
/////////////////////// END-TO-DO (2) ////////////////////////////




// Copy constructor
Snack::Snack( Snack const & other )
  ///////////////////////// TO-DO (3) //////////////////////////////
  : _upcCode( other._upcCode ), _brandName( other._brandName ), _productName( other._productName ), _vendingNum( other._vendingNum ), _quantity( other._quantity ),_price( other._price )
{}
/////////////////////// END-TO-DO (3) ////////////////////////////




// Move constructor
Snack::Snack( Snack && other ) noexcept
  ///////////////////////// TO-DO (4) //////////////////////////////
  : _upcCode( std::move( other._upcCode ) ), _brandName( std::move( other._brandName ) ), _productName( std::move( other._productName ) ), _vendingNum( std::move( other._vendingNum ) ), _quantity( std::move( other._quantity ) ) ,_price( std::move( other._price ) )
{
}
/////////////////////// END-TO-DO (4) ////////////////////////////




// Copy Assignment Operator
Snack & Snack::operator=( Snack const & rhs ) &
///////////////////////// TO-DO (5) //////////////////////////////
{
  if( this != &rhs )
  {
    _productName = rhs._productName;
    _brandName   = rhs._brandName;
    _upcCode     = rhs._upcCode;
    _vendingNum     = rhs._vendingNum;
    _quantity = rhs._quantity;
    _price       = rhs._price;
  }
  return *this;
}
/////////////////////// END-TO-DO (5) ////////////////////////////




// Move Assignment Operator
Snack & Snack::operator=( Snack && rhs ) & noexcept
///////////////////////// TO-DO (6) //////////////////////////////
{
  if( this != &rhs )
  {
    _productName = std::move( rhs._productName );
    _brandName   = std::move( rhs._brandName );
    _upcCode     = std::move( rhs._upcCode );
    _vendingNum     = std::move( rhs._vendingNum );
    _quantity = std::move(rhs._quantity);
    _price       = std::move( rhs._price );
  }
  return *this;
}
/////////////////////// END-TO-DO (6) ////////////////////////////



// Destructor
Snack::~Snack() noexcept
///////////////////////// TO-DO (7) //////////////////////////////
{
}
/////////////////////// END-TO-DO (7) ////////////////////////////








/*******************************************************************************
**  Accessors
*******************************************************************************/

// upcCode() const
std::string const & Snack::upcCode() const &
{
  ///////////////////////// TO-DO (8) //////////////////////////////
  return _upcCode;
  /////////////////////// END-TO-DO (8) ////////////////////////////
}




// brandName() const
std::string const & Snack::brandName() const &
{
  ///////////////////////// TO-DO (9) //////////////////////////////
  return _brandName;
  /////////////////////// END-TO-DO (9) ////////////////////////////
}




// productName() const
std::string const & Snack::productName() const &
{
  ///////////////////////// TO-DO (10) //////////////////////////////
  return _productName;
  /////////////////////// END-TO-DO (10) ////////////////////////////
}

// vendingNum() const
std::string const & Snack::vendingNum() const &
{
  ///////////////////////// TO-DO (10) //////////////////////////////
  return _vendingNum;
  /////////////////////// END-TO-DO (10) ////////////////////////////
}

// quantity() const
int Snack::quantity() const &
{
  ///////////////////////// TO-DO (11) //////////////////////////////
  return _quantity;
  /////////////////////// END-TO-DO (11) ////////////////////////////
}

// price() const
double Snack::price() const &
{
  ///////////////////////// TO-DO (11) //////////////////////////////
  return _price;
  /////////////////////// END-TO-DO (11) ////////////////////////////
}




// upcCode()
std::string Snack::upcCode() &&
{
  ///////////////////////// TO-DO (12) //////////////////////////////
  return std::move( _upcCode );
  /////////////////////// END-TO-DO (12) ////////////////////////////
}




// brandName()
std::string Snack::brandName() &&
{
  ///////////////////////// TO-DO (13) //////////////////////////////
  return std::move( _brandName );
  /////////////////////// END-TO-DO (13) ////////////////////////////
}




// productName()
std::string Snack::productName() &&
{
  ///////////////////////// TO-DO (14) //////////////////////////////
  return std::move( _productName );
  /////////////////////// END-TO-DO (14) ////////////////////////////
}

// vendingNum()
std::string Snack::vendingNum() &&
{
  ///////////////////////// TO-DO (14) //////////////////////////////
  return std::move( _vendingNum );
  /////////////////////// END-TO-DO (14) ////////////////////////////
}






/*******************************************************************************
**  Modifiers
*******************************************************************************/

// upcCode()
Snack & Snack::upcCode( std::string newUpcCode ) &
{
  ///////////////////////// TO-DO (15) //////////////////////////////
    /// Copy assignment "works" but is not correct.  Be sure to move newUpcCode into _upcCode
  _upcCode = std::move( newUpcCode );
  return *this;
  /////////////////////// END-TO-DO (15) ////////////////////////////
}




// brandName()
Snack & Snack::brandName( std::string newBrandName ) &
{
  ///////////////////////// TO-DO (16) //////////////////////////////
  _brandName = std::move( newBrandName );
  return *this;
  /////////////////////// END-TO-DO (16) ////////////////////////////
}




// productName()
Snack & Snack::productName( std::string newProductName ) &
{
  ///////////////////////// TO-DO (17) //////////////////////////////
  _productName = std::move( newProductName );
  return *this;
  /////////////////////// END-TO-DO (17) ////////////////////////////
}

// vendingNum()
Snack & Snack::vendingNum( std::string newVendingNum ) &
{
  ///////////////////////// TO-DO (17) //////////////////////////////
  _vendingNum = std::move( newVendingNum );
  return *this;
  /////////////////////// END-TO-DO (17) ////////////////////////////
}

// price()
Snack & Snack::quantity( int newQuantity ) &
{
  ///////////////////////// TO-DO (18) //////////////////////////////
  _quantity = std::move( newQuantity );
  return *this;
  /////////////////////// END-TO-DO (18) ////////////////////////////
}

// price()
Snack & Snack::price( double newPrice ) &
{
  ///////////////////////// TO-DO (18) //////////////////////////////
  _price = std::move( newPrice );
  return *this;
  /////////////////////// END-TO-DO (18) ////////////////////////////
}





// operator==
bool Snack::operator==( const Snack & rhs ) const noexcept
{
  // All attributes must be equal for the two grocery items to be equal to the other.  This can be done in any order, so put the
  // quickest and then the most likely to be different first.

  ///////////////////////// TO-DO (20) //////////////////////////////
  return _price == rhs._price && _upcCode == rhs._upcCode && _brandName == rhs._brandName && _vendingNum == rhs._vendingNum && _quantity == rhs._quantity && _productName == rhs._productName;
  /////////////////////// END-TO-DO (20) ////////////////////////////
}








/*******************************************************************************
**  Insertion and Extraction Operators
*******************************************************************************/

// operator>>
std::istream & operator>>( std::istream & stream, Snack & snackItem )
{
  ///////////////////////// TO-DO (21) //////////////////////////////
    /// A lot can go wrong when reading from streams - no permission, wrong types, end of file, etc. Minimal exception guarantee says
    /// there should be no side affects if an error or exception occurs, so let's do our work in a local object and move it into place
    /// at the end if all goes well.
    ///
    /// This function should be symmetrical with operator<< below.  Read what your write, and write what you read
    ///
    ///
    /// Assume fields are separated by commas & optional spaces, and string attributes are enclosed with double quotes.  For example:
    ///    UPC Code         | Brand Name | Product Name                                                  | Price
    ///    -----------------+------------+---------------------------------------------------------------+-------
    ///    "00034000020706",  "York",      "York Peppermint Patties Dark Chocolate Covered Snack Size"  ,  12.64
    ///
    ///
    /// Hint:  Use std::quoted to read and write quoted strings.  See
    ///        1) https://en.cppreference.com/w/cpp/io/manip/quoted
    ///        2) https://www.youtube.com/watch?v=Mu-GUZuU31A
  Snack temp;
  char        delimiter = '\0';


  if( stream >> std::ws >> std::quoted( temp._upcCode ) && stream >> std::ws >> delimiter && delimiter == ',' && stream >> std::ws >> std::quoted( temp._brandName ) && stream >> std::ws >> delimiter && delimiter == ',' && stream >> std::ws >> std::quoted( temp._productName ) && stream >> std::ws >> delimiter && delimiter == ',' && stream >> std::ws >> std::quoted( temp._vendingNum ) && stream >> std::ws >> delimiter && delimiter == ',' && stream >> std::ws >> temp._quantity && stream >> std::ws >> delimiter && delimiter == ',' && stream >> std::ws >> temp._price)
  {
    snackItem = std::move( temp );
  }
  else
  {
    stream.setstate( std::ios::failbit );
  }


  return stream;
  /////////////////////// END-TO-DO (21) ////////////////////////////
}




// operator<<
std::ostream & operator<<( std::ostream & stream, const Snack & Snack )
{
  ///////////////////////// TO-DO (22) //////////////////////////////
    /// This function should be symmetrical with operator>> above.  Read what your write, and write what you read
    ///
    /// Hint:  Brand and product names may have quotes, which need to escaped when printing.  Use std::quoted to read and write quoted strings.  See
    ///        1) https://en.cppreference.com/w/cpp/io/manip/quoted
    ///        2) https://www.youtube.com/watch?v=Mu-GUZuU31A
  return stream << std::quoted( Snack._upcCode ) << ", " << std::quoted( Snack._brandName ) << ", " << std::quoted( Snack._productName ) << ", " << std::quoted( Snack._vendingNum ) << ", "  << Snack._quantity << ", "  << Snack._price;
}