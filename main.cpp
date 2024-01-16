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
       throw invalid_argument(shopDatabase.find(article) == shopDatabase.end() ? "product not found" : "there are not so many products in stock");
     }

        cart[article] +=  quantity;

        shopDatabase[article] -= quantity;
        if(shopDatabase[article] == 0)
        {
          shopDatabase.erase(article);
        }
     }



    
     void removeFromcart(const string & article, int quantity)
     {
       if(cart.find( article) == cart.end() || quantity > cart[article])
       {
         throw invalid_argument(cart.find(article) == cart.end() ? "There is not product in the cart" : "there are not many products in the cart");
       }

       cart[article] -=  quantity;
       shopDatabase[article] += quantity;

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

  string article;
  int quantity = 0;

  while(1)
  {
    string select;
    cout << "select add or remove product: ";
    cin >> select;

    if(select == "add")
    {
      cout << "enter the article you want to add: ";
      cin >> article;
      cout << "enter the quantity you want to add: ";
      cin >> quantity;
       try
  {
     shop.addTocart(article, quantity);
  }
  
  catch(const std::invalid_argument& x)
  {
    std::cerr << x.what() << '\n';
  }

    }
    

    if(select == "remove")
    {
      cout << "enter the article you want to remove: ";
      cin >> article;
      cout << "enter the quantity you want to remove: ";
      cin >> quantity;

      try
  {
     shop.removeFromcart(article, quantity);
     
  }
  
  catch(const std::invalid_argument& x)
  {
    std::cerr << x.what() << '\n';
  }
    }

  
  shop.printCart();

  }

  
    return 0;
}