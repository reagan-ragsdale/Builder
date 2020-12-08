#include <iostream>
using namespace std;

// Your end product 
class AppleProduct{
    string _product;
    string _input;
    string _processor;
    string _camera;
    string _speakers;

public:

    AppleProduct(string set_product) { _product = set_product; }

    void setProcessor(string set_processor) { _processor = set_processor; }

    void setInput(string set_input) { _input = set_input; }

    void setCamera(string set_camera) { _camera = set_camera;}

    void setSpeakers(string set_speakers) { _speakers = set_speakers;}


    string getProcessor() { return _processor; }
    string getInput() { return _input; }
    string getCamera() { return _camera; }
    string getSpeakers() { return _speakers; }
    
    void show() {
    	cout << "Apple Base Product Info: " <<_product << endl;
      cout << "Input Type: " <<_input << endl;
    	cout << "Processor Type: "<<_processor << endl;
      cout << "Camera Type: "<<_camera << endl;
      cout << "Speaker Type: "<<_speakers << endl << endl;
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
    virtual void buildCamera() = 0;
    virtual void buildSpeakers() = 0;
    AppleProduct* getAppleProduct(){ return _apple_product; }
};

// AppleProductBuilder concrete class knows only how to build iPhone AppleProduct!
class iPhoneBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for iPhone"); }

    void buildProcessor() { _apple_product->setProcessor("Apple ARM Processor");   }

    void buildInput() { _apple_product->setInput("Touchscreen Input");   }

    void buildCamera() { _apple_product->setCamera("12 MegaPixels");   }

    void buildSpeakers() { _apple_product->setSpeakers("Dolby Atmos surround sound");   }
};

// AppleProductBuilder concrete class knows only how to build Mac AppleProduct
class MacBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for Mac"); }

    void buildProcessor() { _apple_product->setProcessor("Intel Core Processor"); }

    void buildInput() { _apple_product->setInput("Mouse and Keyboard Input");   }

    void buildCamera() { _apple_product->setCamera("1080p Camera");   }

    void buildSpeakers() { _apple_product->setSpeakers("Sterio Speakers");   }
};

// AppleProductBuilder concrete class knows only how to build iPod AppleProduct!
class iPodBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for iPod"); }

    void buildProcessor() { _apple_product->setProcessor("Apple A4 Processor");   }

    void buildInput() { _apple_product->setInput("Touchscreen Input");   }

    void buildCamera() { _apple_product->setCamera("No Camera");   }

    void buildSpeakers() { _apple_product->setSpeakers("Sterio speakers");   }
};

// AppleProductBuilder concrete class knows only how to build macbook AppleProduct!
class MacbookBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for Macbook"); }

    void buildProcessor() { _apple_product->setProcessor("Apple M1 Processor");   }

    void buildInput() { _apple_product->setInput("Keyboard and Mouse");   }

    void buildCamera() { _apple_product->setCamera("720p camera");   }

    void buildSpeakers() { _apple_product->setSpeakers("Surround sound");   }
};



// Defines steps and tells to the builder that build in given order.
class Director{

    AppleProductBuilder *builder;

public:

    AppleProduct* createAppleProduct(AppleProductBuilder *builder) {
        builder->getOtherParts();
        builder->buildInput();
        builder->buildProcessor();
        builder->buildCamera();
        builder->buildSpeakers();
        return builder->getAppleProduct();
    }
};

int main() {
	
  Director dir;
  MacBuilder mb;
  iPhoneBuilder ib;
  iPodBuilder ip;
  MacbookBuilder mp;

	AppleProduct *mac = dir.createAppleProduct(&mb);
	AppleProduct *iphone = dir.createAppleProduct(&ib);
  AppleProduct *ipod = dir.createAppleProduct(&ip);
  AppleProduct *macbook = dir.createAppleProduct(&mp);
	
	mac->show();
  delete mac;

	iphone->show();
  delete iphone;

  ipod->show();
  delete ipod;      
    
  macbook->show();
  delete macbook;

  
	return 0;
}