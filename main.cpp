#include <iostream>
#include <cassert>
#include <map>
#include <exception>

using namespace std;

class OnlineShop
{
    public:
     map <string, int> shopDatabase;
     map <string, int> cart;

     void addTocart(const string & article , int quantity)
     {

     if(shopDatabase.find(article) == shopDatabase.end() || quantity > shopDatabase[article])
     {
       throw invalid_argument(shopDatabase.find(article) == shopDatabase.end() ? "product not found" : "there are not so many items in stock");
     }

        cart[article] +=  quantity;
     }

    
     void removeFromcart(const string & article, int quantity)
     {
       if(cart.find( article) == cart.end() || quantity > cart[article])
       {
         throw invalid_argument(cart.find(article) == cart.end() ? "There is not product in the cart" : "there are not many products in the cart");
       }

       cart[article] -=  quantity;

          if (cart[article] == 0) {
            cart.erase(article);
        }
     }
   
     void printCart()
     {
        cout << " products of the cart: ";
        for(auto item : cart)
        {
          cout << item.first << " " << item.second << endl;
        }
     }

 };


       

int main()
{
  OnlineShop shop;
  shop.shopDatabase["article1"] = 10;
  shop.shopDatabase["article4"] = 4;
  shop.shopDatabase["aricle5"] = 8;
  shop.shopDatabase["article7"] = 10;
  shop.shopDatabase["article9"] = 4;

  try
  {
     shop.addTocart("article1", 8);
  }
  
  catch(const std::invalid_argument& x)
  {
    std::cerr << x.what() << '\n';
  }



  try
  {
     shop.removeFromcart("article1", 4);
     
  }
  
  catch(const std::invalid_argument& x)
  {
    std::cerr << x.what() << '\n';
  }
  
  shop.printCart();

  
 

    return 0;
}