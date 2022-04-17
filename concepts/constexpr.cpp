#include<iostream>
#include<vector>
#include<map>

//constexpr to remove spaces
//constexpr to create map  (key, value)
//constexpr to create list (key, array)
//constexpr to write in header file

struct abc {
    std::string key;
    std::string value;
};

struct transactions {
     struct transaction {
          int id;
          std::string pd;
          std::string url;
          std::string title;
          std::string sell_id;
          std::string last_update;
          std::string inventory_id;
          std::string amount;
          std::string item_id;
          std::string buyer_id;
     };
} mtransactions() {
     mtransaction = [
        {
          payment_id = 2;
          payment_date = "2015-06-30";
          url = "myurl";
          title = "mytitle";
          sell_id = 4;
          last_update = "2015-06-30";
          inventory_id = 4;
          amount = 30.00;
          item_id = 4682;
          buyer_id = 1;
        },
        {
          payment_id = 2;
          payment_date = "2015-06-30";
          url = "myurl";
          title = "mytitle";
          sell_id = 4;
          last_update = "2015-06-30";
          inventory_id = 4;
          amount = 30.00;
          item_id = 4682;
          buyer_id = 1;
        },
     ]
  }
}

constexpr char* deblank(char* input)                                                  /* deblank accepts a char[] argument and returns a char[] */
{
    char *output=input;
    for (int i = 0, j = 0; i<strlen(input); i++,j++)                        /* Evaluate each character in the input */
    {
        if (input[i]!=' ')                                                  /* If the character is not a space */
            output[j]=input[i];                                             /* Copy that character to the output char[] */
        else
            j--;                                                            /* If it is a space then do not increment the output index (j), the next non-space will be entered at the current index */
    }
    return output;                                                          /* Return output char[]. Should have no spaces*/
}

int main()
{
    // constexpr std::map <std::string, std::string> objmap {"hello", "world"};   
    std::cout << "Hello" << std::endl;
    return 0;
}