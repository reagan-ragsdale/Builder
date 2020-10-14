#include <iostream>
using namespace std;

// Your end product 
class AppleProduct{
    string _product;
    string _input;
    string _processor;

public:

    AppleProduct(string set_product) { _product = set_product; }

    void setProcessor(string set_processor) { _processor = set_processor; }

    void setInput(string set_input) { _input = set_input; }
    string getProcessor() { return _processor; }
    string getInput() { return _input; }
    
    void show() {
    	cout << "Apple Base Product Info: " <<_product << endl;
      cout << "Input Type: " <<_input << endl;
    	cout << "Processor Type: "<<_processor << endl << endl;
    }
};

// AppleProductBuilder Abstract Class all builders should have at least these methods
class AppleProductBuilder{
protected:
    AppleProduct *_apple_product;
public:
    virtual void getOtherParts() = 0;
    virtual void buildInput() = 0;
    virtual void buildProcessor() = 0;
    AppleProduct* getAppleProduct(){ return _apple_product; }
};

// AppleProductBuilder concrete class knows only how to build iPhone AppleProduct!
class iPhoneBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for iPhone"); }

    void buildProcessor() { _apple_product->setProcessor("Apple ARM Processor");   }

    void buildInput() { _apple_product->setInput("Touchscreen Input");   }
};

// AppleProductBuilder concrete class knows only how to build Mac AppleProduct
class MacBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for Mac"); }

    void buildProcessor() { _apple_product->setProcessor("Intel Core Processor"); }

    void buildInput() { _apple_product->setInput("Mouse and Keyboard Input");   }
};

// Defines steps and tells to the builder that build in given order.
class Director{

    AppleProductBuilder *builder;

public:

    AppleProduct* createAppleProduct(AppleProductBuilder *builder) {
        builder->getOtherParts();
        builder->buildInput();
        builder->buildProcessor();
        return builder->getAppleProduct();
    }
};

int main() {
	
  Director dir;
  MacBuilder mb;
  iPhoneBuilder ib;

	AppleProduct *mac = dir.createAppleProduct(&mb);
	AppleProduct *iphone = dir.createAppleProduct(&ib);
	
	mac->show();
  delete mac;

	iphone->show();
  delete iphone;  
    
	return 0;
}